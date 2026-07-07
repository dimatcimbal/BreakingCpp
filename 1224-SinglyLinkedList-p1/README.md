# Singly Linked List: Part 1

A singly linked list of integers built from scratch using dynamic allocation.

A node consists of a value and a `next` pointer to the following node. The list maintains a `head` pointer to the first node — `nullptr` when the list is empty. The last node's `next` is also `nullptr`.

## Methods

| Method | Description |
|--------|-------------|
| `push_front(int value)` | Adds a value to the front of the list |
| `pop_front()` | Removes and returns the value at the front |

## Expected output

Push `1`, `2`, `3`, `4` to the front, then pop all four values:

```
4
3
2
1
```

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
