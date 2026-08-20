#include <iostream>
struct TreeNode {
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
        std::cout << std::endl;
    }
    void remove(int value) {
        root = removeHelper(root, value);
    }
    private:
    void inOrderHelper(TreeNode* node) {
        if(node == nullptr) {
            return;
        }
        inOrderHelper(node->left);
        std::cout << node->value << " ";
        inOrderHelper(node->right);
    }
    TreeNode* removeHelper(TreeNode* node, int value) {
        if(node == nullptr) {
            return nullptr;
        }
        if(value < node->value) {
            node->left = removeHelper(node->left, value);
        } else if(value > node->value) {
            node->right = removeHelper(node->right, value);
        } else {
            if(node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = node->right;
            while(temp->left != nullptr) {
                temp = temp->left;
            }
            node->value = temp->value;
            node->right = removeHelper(node->right, temp->value);
        }
        return node;
    }
};
int main() {
    BST tree;
    tree.insert(6);
    tree.insert(2);
    tree.insert(9);
    tree.insert(4);

    tree.inOrder();

    std::cout << "Removed 9: " << std::endl;
    tree.remove(9);

    tree.inOrder();

    return 0;
}