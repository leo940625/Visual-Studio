#include <iostream>
using namespace std;

// Node structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Private helper function - insert node
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else if (value > node->value) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    // Private helper function - search node
    TreeNode* searchNode(TreeNode* node, int value) {
        if (node == nullptr || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return searchNode(node->left, value);
        }
        return searchNode(node->right, value);
    }

    // Private helper function - delete node
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) return node;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            // Current node is the target node
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Find the minimum node in the right subtree
            TreeNode* minNode = findMin(node->right);
            node->value = minNode->value;
            node->right = deleteNode(node->right, minNode->value);
        }
        return node;
    }

    // Private helper function - find minimum node
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Inorder traversal helper function
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    void intsert(TreeNode* node,int value){
        if (node == nullptr){
            node = new TreeNode(value);
        }else if (value > node->value){
            return intsert(node->right,value);
        }else if (value < node->value){
            return intsert(node->left,value);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert node
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Search node
    bool search(int value) {
        return searchNode(root, value) != nullptr;
    }

    // Delete node
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Inorder traversal
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Searching for 70: " << (bst.search(70) ? "Found" : "Not found") << endl;

    cout << "Deleting 20" << endl;
    bst.remove(20);
    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Deleting 30" << endl;
    bst.remove(30);
    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Deleting 50" << endl;
    bst.remove(50);
    cout << "Inorder traversal: ";
    bst.inorder();

    return 0;
}
