// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
// +------+
//
//
//
// A list with two elements:
//
//  Node*      Node         Node
// +------+   +-----+      +-----+
// | head |-->|value|  +-->|value|
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
#include <iostream>

class List;

class Node {
  public:
    Node(int val);

    // rule of 5
    Node(const Node& other) = delete;
    Node& operator=(const Node& other) = delete;
    Node(Node&& other) = delete;
    Node& operator=(Node&& other) = delete;
    ~Node();

  private:
    friend class List;
    int value;

    // NOT an ownership
    Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {
    std::cerr << "+Node(" << value << ")\n";
}

Node::~Node() {
    // debug statement but since std::cout is used in the unit tests
    // we output into std::cerr
    std::cerr << "~Node(" << value << ")\n";

    next = nullptr;
};

class List {
  public:
    List();

    // rule of 5
    List(const List& other) = delete;
    List& operator=(const List& other) = delete;
    List(List&& other) = delete;
    List& operator=(List&& other) = delete;
    ~List();

    void push_front(int value);
    bool pop_front(int& out);

  private:
    // IS the ownership
    Node* head;
};

List::List() : head(nullptr) {}

List::~List() {
    // as the List owns the nodes it has to delete all of then
    for (Node* n = head; n;) {
        Node* tmp = n->next;
        delete n;
        n = tmp;
    }
    head = nullptr;
}

void List::push_front(int value) {
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
}

// START
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 1
//
//            +------+
//            |popped|
//            +------+
//               |
//               V
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 2
// +------+
// | head |-------------------+
// +------+                   |
//                            V
// +------+   +-----+      +-----+
// |popped|-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 3
// returned = popped->value;
// delete popped;
// +------+   +-----+
// | head |-->|  Y  |
// +------+   +-----+
//            |next |-->nullptr
//            +-----+

bool List::pop_front(int& out) {
    // The list is empty
    if (!head) {
        return false;
    }

    // temp node pointing to the prev head
    const Node* prev = head;

    // return the value by reference
    out = head->value;

    // move to the next element
    head = head->next;

    // cleanup the old head
    delete prev;
    return true;
}

int main() {
    List list;
    //
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    for (int value; list.pop_front(value);) {
        std::cout << value << std::endl;
    }
    return 0;
}