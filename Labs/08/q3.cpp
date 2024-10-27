#include <iostream>
#include <algorithm> // for max
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class StockMarketAnalyzer {
public:
    int maxProfit = INT_MIN; // initializing to the smallest integer value

    // Function to calculate the maximum path sum
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;

        // Calculate maximum profit from left and right subtrees
        int leftProfit = max(0, maxPathSum(root->left));  // Ignore negative profits
        int rightProfit = max(0, maxPathSum(root->right)); // Ignore negative profits

        // Calculate the maximum profit path that passes through this node
        maxProfit = max(maxProfit, root->val + leftProfit + rightProfit);

        // Return the maximum profit path that can be extended to the parent
        return root->val + max(leftProfit, rightProfit);
    }
};

// Function to print the binary tree in pre-order
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Original Tree (Pre-order): ";
    printTree(root);
    cout << endl;

    StockMarketAnalyzer analyzer;
    analyzer.maxPathSum(root);

    cout << "Maximum Profit Path: " << analyzer.maxProfit << endl;

    // deallocating memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
