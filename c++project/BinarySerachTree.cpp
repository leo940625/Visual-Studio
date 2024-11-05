#include <iostream>
using namespace std;

// 節點結構
struct TreeNode {
    int value; // 節點的值
    TreeNode* left; // 左子節點
    TreeNode* right; // 右子節點
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {} // 節點的構造函數
};

// 二元搜尋樹類別
class BinarySearchTree {
private:
    TreeNode* root; // 樹的根節點

    // 私有輔助函數 - 插入節點
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value); // 如果節點為空，創建新節點
        }
        if (value < node->value) {
            node->left = insertNode(node->left, value); // 插入左子樹
        } else if (value > node->value) {
            node->right = insertNode(node->right, value); // 插入右子樹
        }
        return node;
    }

    // 私有輔助函數 - 搜尋節點
    TreeNode* searchNode(TreeNode* node, int value) {
        if (node == nullptr || node->value == value) {
            return node; // 如果節點為空或找到目標節點，返回節點
        }
        if (value < node->value) {
            return searchNode(node->left, value); // 在左子樹中搜尋
        }
        return searchNode(node->right, value); // 在右子樹中搜尋
    }

    // 私有輔助函數 - 刪除節點
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) return node; // 如果節點為空，返回節點

        if (value < node->value) {
            node->left = deleteNode(node->left, value); // 在左子樹中刪除
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value); // 在右子樹中刪除
        } else {
            // 當前節點是目標節點
            if (node->left == nullptr) {
                TreeNode* temp = node->right; // 如果左子節點為空，返回右子節點
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left; // 如果右子節點為空，返回左子節點
                delete node;
                return temp;
            }
            // 在右子樹中找到最小節點
            TreeNode* minNode = findMin(node->right);
            node->value = minNode->value; // 用最小節點的值替換當前節點的值
            node->right = deleteNode(node->right, minNode->value); // 刪除右子樹中的最小節點
        }
        return node;
    }

    // 私有輔助函數 - 找到最小節點
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left; // 一直向左找到最小節點
        }
        return node;
    }

    // 中序遍歷輔助函數
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left); // 遍歷左子樹
            cout << node->value << " "; // 輸出節點值
            inorderTraversal(node->right); // 遍歷右子樹
        }
    }

    // 插入節點輔助函數
    void intsert(TreeNode* node,int value){
        if (node == nullptr){
            node = new TreeNode(value); // 如果節點為空，創建新節點
        }else if (value > node->value){
            return intsert(node->right,value); // 插入右子樹
        }else if (value < node->value){
            return intsert(node->left,value); // 插入左子樹
        }
    }

public:
    BinarySearchTree() : root(nullptr) {} // 二元搜尋樹的構造函數

    // 插入節點
    void insert(int value) {
        root = insertNode(root, value); // 調用插入節點輔助函數
    }

    // 搜尋節點
    bool search(int value) {
        return searchNode(root, value) != nullptr; // 調用搜尋節點輔助函數
    }

    // 刪除節點
    void remove(int value) {
        root = deleteNode(root, value); // 調用刪除節點輔助函數
    }

    // 中序遍歷
    void inorder() {
        inorderTraversal(root); // 調用中序遍歷輔助函數
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
