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

    void print(){
        for(int i = 0; i < getSize(); ++i){
            cout << "element " << i+1 << ": " << DArray[i] << endl;
        }
    }

};


int main() {
    Stack s1;
    cout << "Before adding data, capacity is : " << s1.getCapacity() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(45);
    s1.push(66); 
    s1.push(23);
    s1.push(95);
    cout << "Main Stack: \n";
    s1.print();
    int even;
    Stack even_stack;
    Stack odd_stack;
    int size = s1.getSize();
    cout << "\nSize: " << size << endl;
   for(int i = 0; i < size; i++){
       even = s1.pop();
     if(even % 2 == 0){
        even_stack.push(even);
    }

    else{
        odd_stack.push(even);
    }
   }

    cout << "Even Stack: " << endl;
    even_stack.print();
    cout << "Odd Stack: " << endl;
    odd_stack.print();
}