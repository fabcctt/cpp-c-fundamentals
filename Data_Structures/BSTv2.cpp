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
        if(value < node->value){
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
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
};
int main() {
    BST tree;

    tree.insert(2);
    tree.insert(15);
    tree.insert(3);
    tree.insert(6);

    tree.inOrder();

    std::cout << std::boolalpha;
    std::cout << "Find 2: " << tree.search(2) << std::endl;
    std::cout << "Find 18: " << tree.search(18) << std::endl;

    return 0;
}