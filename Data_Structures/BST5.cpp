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
    void preOrderHelper(TreeNode* node) {
        if(node == nullptr) return;
        std::cout << node->value << std::endl;
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
    void postOrderHelper(TreeNode* node) {
        if(node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->value << std::endl;
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
    TreeNode* removeHelper(TreeNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->value) {
        node->left = removeHelper(node->left, value);
    } else if (value > node->value) {
        node->right = removeHelper(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        } else {
            TreeNode* successor = findMinHelper(node->right);
            node->value = successor->value;
            node->right = removeHelper(node->right, successor->value);
        }
    }
    return node;
}
    public:
    BST() : root(nullptr){}
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
    void preOrder() {
        preOrderHelper(root);
    }
    void postOrder() {
        postOrderHelper(root);
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
    void remove(int value) {
        root = removeHelper(root, value);
    }
};
int main() {
    BST tree;
    tree.insert(9);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);

    std::cout << "--inOrder--" << std::endl;
    tree.inOrder();

    std::cout << "--preOrder--" << std::endl;
    tree.preOrder();

    std::cout << "--postOrder--" << std::endl;
    tree.postOrder();

    std::cout << std::boolalpha;
    std::cout << "--Search--" << std::endl;
    std::cout << "Find 9: " << tree.search(9) << std::endl;
    std::cout << "Find 3: " << tree.search(3) << std::endl;

    std::cout << "--findMin--" << std::endl;
    std::cout << tree.findMin() << std::endl;
    std::cout << "--findMax--" << std::endl;
    std::cout << tree.findMax() << std::endl;

    tree.remove(9);
    std::cout << "After removing 9:" << std::endl;
    tree.inOrder();
    return 0;
}
