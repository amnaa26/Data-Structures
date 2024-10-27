#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class CorrectTree {
public:
    TreeNode* first = nullptr;   // First node that is out of order
    TreeNode* second = nullptr;  // Second node that is out of order
    TreeNode* prev = nullptr;    // Previous node during in-order traversal

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        // Check if the current node is out of order
        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;  
            }
            second = root;      // Always update the second
        }
        prev = root;
        inorderTraversal(root->right);
    }


    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};


void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2); // This should be swapped with 3

    cout << "Original BST (In-order): ";
    printInOrder(root);
    cout << endl;

    CorrectTree T;
    T.recoverTree(root);

    cout << "Recovered BST (In-order): ";
    printInOrder(root);
    cout << endl;
}
