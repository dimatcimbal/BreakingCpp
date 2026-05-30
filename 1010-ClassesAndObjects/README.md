# Classes and Objects

With encapsulation covered, it's time to design a class from scratch.

Imagine you're building an e-commerce back-end. Your task is to implement `ShopItemOrder`, which represents a single line item in a shopping cart.

## Requirements

**Data members** (private):
- Item name
- Unit price
- Quantity ordered

**Public interface**:
- Getters and setters for all three fields
- `get_total()` — returns the total price for the order
- `print()` — displays the order in a readable format

You may choose any strategy (eager, ad hoc, or lazy) for computing the total price.
