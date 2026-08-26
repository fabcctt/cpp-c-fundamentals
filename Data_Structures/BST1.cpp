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
};
int main() {
    BST tree;

    tree.insert(2);
    tree.insert(9);
    tree.insert(6);

    tree.inOrder();

    return 0;
}