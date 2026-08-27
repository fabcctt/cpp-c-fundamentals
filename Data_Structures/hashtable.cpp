#include <iostream>

struct Node {
    int value;
    Node* next;
};

class HashTable {
    private:
        Node* buckets[10];
    public:
        HashTable() {
            for (int i = 0; i < 10; i++) {
                buckets[i] = nullptr;
            }
        }

        void insert(int value) {
            int index = value % 10;
            Node* newNode = new Node{value, nullptr};

            if (buckets[index] == nullptr) {
                buckets[index] = newNode;
            } else {
                newNode->next = buckets[index];
                buckets[index] = newNode;
            }
        }

        bool search(int value) {
            int index = value % 10;
            Node* current = buckets[index];

            while (current != nullptr) {
                if (current->value == value) {
                    return true;
                }
                current = current->next;
            }

            return false;
        }
        void printTable() {
           for (int i = 0; i < 10; i++) {
             std::cout << "Bucket " << i << ": ";
             Node* current = buckets[i];
           while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
};

int main() {
    HashTable table;
    table.insert(23);
    table.insert(13);
    table.insert(7);
    table.printTable();

    std::cout << std::boolalpha;
    std::cout << "Search 13: " << table.search(13) << std::endl;
    std::cout << "Search 99: " << table.search(99) << std::endl;

    return 0;
}