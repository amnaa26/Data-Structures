#include<iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Stack{
private:
    struct StackNode {
        TreeNode* treeNode;
        StackNode* next;

        StackNode(TreeNode* node) : treeNode(node), next(nullptr) {}
    };

    StackNode* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(TreeNode* node){
        StackNode* newnode = new StackNode(node);
        newnode->next = topNode;
        topNode= newnode;
    }

    TreeNode* pop(){
        if(isEmpty()){
            return nullptr;
        }

        StackNode* temp = topNode;
        TreeNode* poppednode = topNode->treeNode;
        topNode = topNode->next;
        delete temp;
        return poppednode;
    }

    bool isEmpty(){
        return topNode == nullptr;
    }

    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
};


//function to print the binary tree in zigzag order
void zigzagLevelOrder(TreeNode* root){
    if(!root) return;

    //two stacks to hold the current and next level node
    Stack currentlevel;
    Stack nextlevel;
    bool left_to_right = true;

    currentlevel.push(root);

    while(!currentlevel.isEmpty()){
        TreeNode* node = currentlevel.pop();
        cout << node->data << " ";

        // Depending on the traversal direction push children onto the nextlevel stack
        if(left_to_right){
            if(node->left) nextlevel.push(node->left);
            if(node->right) nextlevel.push(node->right);
        }

        else{
            if(node->right) nextlevel.push(node->right);
            if(node->left) nextlevel.push(node->left);
        }

        // If the current level is empty, switch stacks and toggle the direction
        if(currentlevel.isEmpty()){
            swap(currentlevel, nextlevel);
            left_to_right = !left_to_right;
        }
    }
}

// Function to print the binary tree in pre-order
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original Tree (Pre-order): ";
    printTree(root);
    cout << endl;

    cout << "Zigzag Level Order Traversal: ";
    zigzagLevelOrder(root);
    cout << endl;
}
