/*
In C++, serialization is the process of converting an object into a sequence of bytes so that it can be stored in memory or transmitted across a network and deserialization is the reverse process, where the byte stream is used to reconstruct the original object.
*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;
    
public:
    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    friend class BinaryTree;
};


class BinaryTree{
private:
    Node* root;
    
    Node* helper_insert(Node* node, int val){
        if(!node) return new Node(val);
        if(val < node->data){
            node->left = helper_insert(node->left, val);
        } else node->right = helper_insert(node->right, val);

        return node;
    }

    //function to serialize tree into a string
    string serialize_helper(Node* node)const{
        if(!node) return "# ";
        return to_string(node->data) + " " + serialize_helper(node->left) + serialize_helper(node->right); 
    }

    //function to deserialize tree from string and back into tree
    Node* deserialize_helper(istringstream& iss){  //istreamstring is useful for parsing and extracting formatted data from a string
        string value;
        iss >> value; //reading data in chunks from iss and storing it in value

        if(value == "#") return nullptr;

        Node* newnode = new Node(stoi(value)); //converting string to vale using stoi() and then storing it in node

        newnode->left = deserialize_helper(iss);
        newnode->right = deserialize_helper(iss);

        return newnode;
    }

    void inorder_helper(Node* node)const{
        if(!node) return;
        inorder_helper(node->left);
        cout << node->data << " ";
        inorder_helper(node->right);
    }

    void destroy_tree(Node* node){
        if(!node) return;
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert_value(int val){
        root = helper_insert(root, val);
    }

    string serialize() const{
        return serialize_helper(root);
    }

    void deserialize(const string& value){
        istringstream iss(value);
        root = deserialize_helper(iss);
    }

    void inorder()const{
        inorder_helper(root);
        cout << endl;
    }

    ~BinaryTree(){
        destroy_tree(root);
    }
};


int main() {
    BinaryTree tree;
    tree.insert_value(5);
    tree.insert_value(3);
    tree.insert_value(7);
    tree.insert_value(2);
    tree.insert_value(4);
    tree.insert_value(6);
    tree.insert_value(8);
    tree.insert_value(26);
    cout << "Original tree (in-order): ";
    tree.inorder();

    string serialized = tree.serialize();
    cout << "Serialized tree: " << serialized << std::endl;

    BinaryTree newTree;
    newTree.deserialize(serialized);
    cout << "Deserialized tree (in-order): ";
    newTree.inorder();
}