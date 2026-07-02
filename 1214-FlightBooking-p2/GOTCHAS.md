# C++ Gotchas — Multi-Flight Booking

### 1. `std::map` cannot store references as values

```cpp
std::map<uint, FlightBooking&>  // ❌ compile error
```

Containers require copyable/movable value types. Use a value, pointer, or smart pointer instead.

### 2. Store by value and use `auto&` — no smart pointer needed

When the map is the sole owner, store by value and take a reference via `auto&`:

```cpp
std::map<uint, FlightBooking> bookings;

auto it = bookings.find(number);
auto& fb = it->second;   // ✅ direct reference — no indirection, no heap allocation
fb.reserveSeats(n);      // mutation affects the stored value
```

`std::shared_ptr` is only warranted when something outside the map also holds a reference and both need to keep the object alive.

### 3. `std::map::operator[]` inserts on a miss — never use it for lookup

```cpp
auto fb = bookings[number];  // ❌ inserts a default-constructed entry if key is missing
```

This can cause segfaults when iterating a map that contains unexpected default entries. Always use `find` for conditional lookup:

```cpp
auto it = bookings.find(number);
if (it == bookings.end()) { /* not found */ }
auto& fb = it->second;
```

### 4. `std::map` insert with `emplace`, not `insert`

```cpp
bookings.insert(number, FlightBooking(...));  // ❌ wrong signature
bookings.emplace(number, FlightBooking(...)); // ✅
```

### 5. `std::map` erase by key with `erase`

```cpp
delete bookings[number];  // ❌ wrong
bookings.erase(number);   // ✅ removes the entry cleanly
```

### 6. Distinguishing read vs. write `operator[]` with a Proxy

C++ cannot overload `operator[]` by whether it appears on the left or right side of `=`. The idiomatic solution is to return a **Proxy** object that defers the decision:

```cpp
struct Proxy {
    FlightBookingCtrl& ctrl;
    uint key;

    // Called when used on the left side of =
    Proxy& operator=(std::shared_ptr<FlightBooking> fb) {
        ctrl.bookings.emplace(key, fb);
        return *this;
    }

    // Called when used on the right side (implicit conversion)
    operator std::shared_ptr<FlightBooking>() const {
        return ctrl.bookings.at(key);
    }
};
```

`ctrl[key] = fb` triggers `operator=`; `auto fb = ctrl[key]` triggers the type conversion operator.

**Gotcha — forward declaration order.** `Proxy` references `FlightBookingCtrl` and `FlightBookingCtrl` returns `Proxy`, so neither can be fully defined first. The fix is to separate declarations from definitions:

```cpp
// 1. Forward-declare FlightBookingCtrl so Proxy can reference it
struct FlightBookingCtrl;

// 2. Fully declare Proxy (no method bodies yet)
struct Proxy { ... };

// 3. Fully declare FlightBookingCtrl (no method bodies yet)
struct FlightBookingCtrl { ... };

// 4. Define all method bodies after both types are complete
inline Proxy& Proxy::operator=(...) { ... }
inline Proxy::operator std::shared_ptr<FlightBooking>() const { ... }
```

Without step 1, `Proxy` sees an incomplete `FlightBookingCtrl` and cannot access its members in the method bodies.

### 7. Smart pointer choice for map values

- Value (`FlightBooking`): simplest — use `auto&` (see Gotcha 2) to avoid copies.
- `std::unique_ptr`: single owner — can't be shared outside the map.
- `std::shared_ptr`: correct when multiple owners exist (e.g., the map and an external reference).
