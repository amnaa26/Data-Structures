#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) {
    if (start > end) return nullptr; //base case
    int mid = start + (end - start) / 2;

    // Create a tree node with the middle element
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = sortedArrayToBST(nums, start, mid - 1);
    node->right = sortedArrayToBST(nums, mid + 1, end);

    return node;
}

TreeNode* sortedArrayToBST(const vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void printPreOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    vector<int> sortedArray = {-10, -3, 0, 5, 9}; 
    TreeNode* root = sortedArrayToBST(sortedArray);
    cout << "Pre-order traversal of the constructed BST: ";
    printPreOrder(root);
    cout << endl;
}
