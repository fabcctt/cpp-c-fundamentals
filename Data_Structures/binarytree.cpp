#include <iostream>
class TreeNode {
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
};
class BST {
    private:
    TreeNode* root;
    public:
    BST() : root(nullptr) {}
    void insert(int value) {
        TreeNode* newNode = new TreeNode();
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
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
    private:
    void inOrderHelper(TreeNode* node) {
        if(node == nullptr) {
            return;
        }
        inOrderHelper(node->left);
        std::cout << node->value << std::endl;
        inOrderHelper(node->right);
    }
    bool searchHelper(TreeNode* node, int value) {
        if(node == nullptr) {
            return false;
        }
        if(value == node->value) {
            return true;
        }
        if(value < node->value) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }
};
int main() {
    BST tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);

    tree.inOrder();

    std::cout << std::boolalpha; 
    std::cout << "Search 3: " << tree.search(3) << std::endl;
    std::cout << "Search 15: " << tree.search(15) << std::endl; 

    return 0;
}