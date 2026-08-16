#include <iostream>
class Node {
    public:
    int value;
    Node* next;
};
class Queue {
    private:
    Node* front;
    Node* rear;
    public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = nullptr;

        if(rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->value;
        front = front->next;
        delete temp;
        return value;
    }

    void printQueue() {
        Node* current = front;
        while(current != nullptr) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(12);

    q.printQueue();

    std::cout << "Dequeued: " << q.dequeue() << std::endl;

    q.printQueue();


    return 0;
}