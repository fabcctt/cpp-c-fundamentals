#include <iostream>
class Node {
    public:
    int value;
    Node* next;
};
class Stack {
    private:
    Node* top;
    public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }
    void printStack() {
        Node* current = top;
        while(current != nullptr) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }
    int pop() {
        if (top == nullptr) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->value;
        top = top->next;
        delete temp;
        return value;
    }
};
int main() {
    Stack s;
    s.push(5);
    s.push(9);

    s.printStack();

    std::cout << "Popped: " << s.pop() << std::endl;

    s.printStack();
    
    return 0;
}
