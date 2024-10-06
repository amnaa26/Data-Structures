#include<iostream>
using namespace std;

class Stack {
private:
    char* DArray;
    int top;
    int capacity;

    void resize(int newCapacity) {
        char* newArray = new char[newCapacity];
        for (int i = 0; i <= top; i++) {
            newArray[i] = DArray[i];
        }
        delete[] DArray;
        DArray = newArray;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 1) : capacity(initialCapacity), top(-1) {
        DArray = new char[capacity];
    }

    ~Stack() {
        delete[] DArray;
    }

    void push(int data) {
        if (isFull()) {
            resize(capacity * 2);
        }
        DArray[++top] = data;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        int data = DArray[top--];
        if (top >= 0 && top <= capacity / 4) {
            resize(capacity / 2);
        }
        return data;
    }

    bool isEmpty() const {
        return top < 0;
    }

    bool isFull() const {
        return top + 1 == capacity;
    }

    int getSize() const {
        return top + 1;
    }

    int getCapacity() const {
        return capacity;
    }

    char peek() {
        if (top == -1)
            return -1;
        return DArray[top];
    }


    void print(){
        for(int i = 0; i < capacity; ++i){
            cout << "element " << i+1 << ": " << DArray[i] << endl;
        }
    }

};