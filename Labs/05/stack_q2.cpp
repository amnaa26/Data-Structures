/*
Implementing stack using linked list
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};


class Stack{
private:
    Node *top;

public:
    Stack(){top = NULL;}

    void push(int value){
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed onto stack." << endl;
    }

    int pop(){
        if(top == NULL){
            cout << "Stack is empty.." << endl;
            return -1;
        }

        Node *temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }


    int peek(){
        if(top == NULL){
            cout << "Stack is empty.." << endl;
            return -1;
        }

        return top->data;
    }


    bool isEmpty(){
        return top == NULL;
    }


    ~Stack(){
        while(top != NULL){
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};


int main(){
    Stack s;
    s.push(12);
    s.push(13);
    s.push(30);
    cout << s.pop() << " popped from the stack." << endl;
    cout << "Top element is: " << s.peek() << endl;
    if(s.isEmpty()){
        cout << "Stack is empty." << endl;
    } else cout << "Stack is not empty." << endl;
}