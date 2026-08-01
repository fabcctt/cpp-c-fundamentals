#include <iostream>

class Node {
    public:
        int value;
        Node* next;
};

int main() {
    Node nodeA;
    Node nodeB;
    Node nodeC;

    nodeA.value = 10;
    nodeB.value = 20;
    nodeC.value = 30;

    nodeA.next = nullptr;
    nodeB.next = nullptr;
    nodeC.next = nullptr;

    nodeA.next = &nodeB;
    nodeB.next = &nodeC;

    Node* current = &nodeA;

    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;
    }

    return 0;
}