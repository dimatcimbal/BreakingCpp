# Doubly Linked List

A doubly linked list of integers that also supports appending to the back — turning the list into a usable queue (FIFO).

A node consists of a value, a `next` pointer to the following node, and a `prev` pointer to the preceding node. The list maintains a `head` pointer to the first node and a `tail` pointer to the last node — both `nullptr` when the list is empty. Keeping a dedicated `tail` pointer means `push_back` does not need to walk the list to find the last node — it stays O(1).

## Methods

| Method | Description |
|--------|-------------|
| `push_front(int value)` | Adds a value to the front of the list |
| `push_back(int value)` | Adds a value to the back of the list |
| `pop_front()` | Removes and returns the value at the front |

## Expected output

Push `1`, `2`, `3`, `4` to the back, then pop all four values:

```
1
2
3
4
```

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
