# C++ Gotchas — Flight Booking

### 1. `std::cin >>` operator vs `std::getline`

The `cin >>` operator skips leading whitespace, reads until it hits whitespace again, then stops — leaving the terminating `\n` in the buffer. A subsequent `getline` call will immediately read that leftover newline as an empty line.

`std::getline` reads the entire line up to and including the `\n`, discarding the newline but not storing it. This leaves the buffer clean for the next read.

Prefer `getline` + `std::stoi` for all initial input to avoid the leftover newline problem:

```cpp
std::string line;
std::getline(std::cin, line);
int capacity = std::stoi(line);
```

### 2. Parsing a command line with `std::istringstream`

`std::istringstream` is the idiomatic way to read a string word by word — it wraps a string in a stream interface so you can use the `>>` operator on it exactly as you would with `cin`. Each `>>` call extracts one whitespace-delimited token at a time:

```cpp
std::istringstream iss{line};
std::string command;
iss >> command;  // first token — the command name
```

### 3. Reading an integer argument from the same stream

The `>>` operator on a stringstream converts directly to the target type, so no `std::stoi` needed for subsequent tokens:

```cpp
int number_of_seats;
iss >> number_of_seats;  // second token parsed straight to int
```
