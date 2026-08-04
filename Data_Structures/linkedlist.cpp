#include <iostream>

class Node {
    public:
        int value;
        Node* next;
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() {
            head = nullptr;
        }
        void add(int value) {
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        void printAll() {
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->value << std::endl;
                current = current->next;
            }
        }
        void deleteAll() {
            Node* current = head;
             while (current != nullptr) {
             Node* temp = current;
              current = current->next;
               delete temp;
    }
    head = nullptr;
}
};

int main() {
    LinkedList list;
    list.add(3);
    list.add(7);
    list.add(12);
    list.printAll();

    list.deleteAll();

    return 0;
}