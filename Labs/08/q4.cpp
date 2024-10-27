#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* s, TreeNode* t) {
    // If both nodes are null, trees are identical
    if (s == nullptr && t == nullptr) return true;
    // If one of the nodes is null or values do not match, trees are not identical
    if (s == nullptr || t == nullptr) return false;
    if (s->val != t->val) return false;

    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(TreeNode* T1, TreeNode* T2) {
    // If T2 is null, it is a subtree of T1
    if (T2 == nullptr) return true;
    // If T1 is null and T2 is not, T2 cannot be a subtree of T1
    if (T1 == nullptr) return false;

    // Check if the current nodes are the same and if T2 is identical to the subtree of T1
    if (isSameTree(T1, T2)) return true;

    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

// Function to print the tree in pre-order
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}


int main() {
    TreeNode* T1 = new TreeNode(3);
    T1->left = new TreeNode(4);
    T1->right = new TreeNode(5);
    T1->left->left = new TreeNode(1);
    T1->left->right = new TreeNode(2);

    cout << "Original Tree (Pre-order): ";
    printTree(T1);
    cout << endl;

    TreeNode* T2 = new TreeNode(4);
    T2->left = new TreeNode(1);
    T2->right = new TreeNode(2);

    cout << "Original Tree (Pre-order): ";
    printTree(T2);
    cout << endl;

    if (isSubtree(T1, T2)) {
        cout << "T2 is a subtree of T1." << endl;
    } else {
        cout << "T2 is NOT a subtree of T1." << endl;
    }

    // deallocating memory
    delete T1->left->right->left; 
    delete T1->left->right;        
    delete T1->left->left;         
    delete T1->left;               
    delete T1->right;              
    delete T1;                     
    delete T2->left;               
    delete T2->right;              
    delete T2;                     
}


/*for my understanding: 
    // Deleting node with value 0
    // Deleting node with value 2
    // Deleting node with value 1
    // Deleting node with value 4
    // Deleting node with value 5
    // Deleting root node
    // Deleting node with value 1
    // Deleting node with value 2
    // Deleting root node

*/