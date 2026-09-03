#include <iostream>
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};
class BST {
    private:
    TreeNode* root;

    void inOrderHelper(TreeNode* node) {
        if(node == nullptr) return;
        inOrderHelper(node->left);
        std::cout << node->value << std::endl;
        inOrderHelper(node->right);
    }

    bool searchHelper(TreeNode* node, int value) {
        if(node == nullptr) return false;
        if(value == node->value) return true;
        if(value < node->value) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    TreeNode* findMinHelper(TreeNode* node) {
        if(node == nullptr) return nullptr;
        while(node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* findMaxHelper(TreeNode* node) {
        if(node == nullptr) return nullptr;
        while(node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    public:
    BST() : root(nullptr) {}

    void insert(int value) {
        TreeNode* newNode = new TreeNode{value, nullptr, nullptr};

        if(root == nullptr) {
            root = newNode;
        } else {
            TreeNode* current = root;
            while(true) {
                if(value < current->value) {
                    if(current->left == nullptr) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                } else {
                    if(current->right == nullptr) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }
    void inOrder() {
        inOrderHelper(root);
    }

    bool search(int value) {
        return searchHelper(root, value);
    }

    int findMin() {
        TreeNode* minNode = findMinHelper(root);
        if(minNode == nullptr) return -1;
        return minNode->value;
    }

    int findMax() {
        TreeNode* maxNode = findMaxHelper(root);
        if(maxNode == nullptr) return -1;
        return maxNode->value;
    }
};
int main() {
    BST tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(2);
    tree.insert(8);
    tree.insert(15);
    tree.insert(30);

    tree.inOrder();

    std::cout << std::boolalpha;
    std::cout << "Find 8: " << tree.search(8) << std::endl;
    std::cout << "Find 99: " << tree.search(99) << std::endl;

    std::cout << "Min value: " << tree.findMin() << std::endl;
    std::cout << "Max value: " << tree.findMax() << std::endl;

    return 0;
}