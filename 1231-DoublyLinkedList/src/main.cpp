// An empty list:
//
//  Node*      Node*
// +------+   +------+
// | head |   | tail |
// +------+   +------+
//     \_________/
//          |
//          V
//       nullptr
//
//
// A list with two elements:
//
//  Node*      Node         Node      Node*
// +------+   +-----+      +-----+   +------+
// | head |-->|value|  +-->|value|<--| tail |
// +------+   +-----+  |   +-----+   +------+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
#include <iostream>

template <typename T> class List;

template <typename T> class Node {
  public:
    Node(T value);

    Node(const Node& value) = delete;
    Node& operator=(const Node& value) = delete;
    Node(Node&& value) = delete;
    Node& operator=(Node&& value) = delete;
    ~Node();

  private:
    friend class List<T>;
    T value;

    // NOT an ownership
    Node* next;
    Node* prev;
};

template <typename T> Node<T>::Node(T value) : value(value) {
    std::cerr << "+Node(" << value << ")\n";
}

template <typename T> Node<T>::~Node() {
    std::cerr << "~Node(" << value << ")\n";
}

template <typename T> class List {
  public:
    List() = default;

    List(const List& other) = delete;
    List& operator=(const List& other) = delete;
    List(const List&& other) = delete;
    List& operator=(const List&& other) = delete;
    ~List();

    void push_front(T value);
    void push_back(T value);
    bool pop_front(T& out);

  private:
    Node<T>* head;
    Node<T>* tail;
};
// push_back
//
//    head      tail -------+
//     |                    |
// +------+     +-----+   +-----+
// | node |<-+  | n0  |   | n1  |
// +------+  |  +-----+   +-----+
// | prev |  +--|prev |   |prev |
// +------+     +-----+   +-----+
// |next  | --> |next |   |next |
// +------+     +-----+   +-----+
//

template <typename T> void List<T>::push_front(T value) {
    auto* node = new Node<T>{value};

    // if list is empty
    if (!tail) {
        tail = node;
    }

    if (head) {
        head->prev = node;
        node->next = head;
    }

    head = node;
}

// push_back
//
//    head      tail ---------+
//     |                      |
// +------+    +-----+       +-----+
// | n0   |    | n1  |<-+    |node |
// +------+    +-----+  |    +-----+
// | prev |    |prev |  +--  |prev |
// +------+    +-----+       +-----+
// |next  |--> |next | --->  |next |
// +------+    +-----+       +-----+
//
template <typename T> void List<T>::push_back(T value) {
    auto* node = new Node<T>{value};

    // if list is empty
    if (!head) {
        head = node;
    }

    if (tail) {
        node->prev = tail;
        tail->next = node;
    }
    tail = node;
}

template <typename T> bool List<T>::pop_front(T& out) {
    // list is empty
    if (!head) {
        return false;
    }

    auto* node = head;
    out = node->value;

    head = head->next;
    delete node;
    return true;
}

template <typename T> List<T>::~List() {
    for (Node<T>* n = head; n;) {
        Node<T>* tmp = n->next;
        delete n;
        n = tmp;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    List<int> list{};

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    for (int value; list.pop_front(value);) {
        std::cout << value << std::endl;
    }

    return 0;
}
