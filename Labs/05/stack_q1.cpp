/*
Implementing stack using dynamic array
*/

#include <iostream>
using namespace std;

class Stack {
private:
    int* DArray;
    int top;
    int capacity;

    void resize(int newCapacity) {
        int* newArray = new int[newCapacity];
        for (int i = 0; i <= top; i++) {
            newArray[i] = DArray[i];
        }
        delete[] DArray;
        DArray = newArray;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 1) : capacity(initialCapacity), top(-1) {
        DArray = new int[capacity];
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
            return -1; // Return a sentinel value
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

};


int main() {
    Stack s1;
    cout << "Before adding data, capacity is : " << s1.getCapacity() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout << "After adding data, capacity is : " << s1.getCapacity() << endl;
    while (!s1.isEmpty()) {
        cout << "Popped: " << s1.pop() << endl;
        cout << "After deleting data, capacity is : " << s1.getCapacity() << endl;
    }

    return 0;
}