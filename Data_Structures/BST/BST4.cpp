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

    void PreOrderHelper(TreeNode* node) {
        if(node == nullptr) return;
        std::cout << node->value << std::endl;
        PreOrderHelper(node->left);
        PreOrderHelper(node->right);
    }

    void PostOrderhelper(TreeNode* node) {
        if(node == nullptr) return;
        PostOrderhelper(node->left);
        PostOrderhelper(node->right);
        std::cout << node->value << std::endl;
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

    void preOrder() {
        PreOrderHelper(root);
        std::cout << std::endl;
    }

    void postOrder() {
        PostOrderhelper(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    tree.insert(8);
    tree.insert(4);
    tree.insert(6);
    tree.insert(12);
    tree.insert(38);
    tree.insert(48);
    tree.insert(14);
    tree.insert(36);

    std::cout << "-- InOrder --" << std::endl;
    tree.inOrder();

    std::cout << std::boolalpha;
    std::cout << "Find 4: " << tree.search(4) << std::endl;
    std::cout << "Find 10: " << tree.search(10) << std::endl;

    std::cout << "Find min: " << tree.findMin() << std::endl;
    std::cout << "Find max: " << tree.findMax() << std::endl;

    std::cout << "\n-- Pre Order --" << std::endl;
    tree.preOrder();
    
    std::cout << "-- Post Order --" << std::endl;
    tree.postOrder();

    return 0;
}
