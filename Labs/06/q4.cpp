/*
We are given a stack data structure with push and pop operations, the task is to implement a
queue using instances of stack data structure and operations on them. (HINT: Two stacks will be
used either for enqueue or for dequeue)
*/

#include <iostream>
#include "stack.hpp"
using namespace std;

class QueueStack{
private:
    Stack* stack1;
    Stack* stack2;
    int capacity;

public:
    QueueStack(int size): capacity(size), stack1(new Stack(capacity)), stack2(new Stack(capacity)) {}

    void enqueue(int x){
        if(stack1->getSize() == capacity){
            cout << "Queue is full! Cannot enqueue " << x << endl;
            return;
        }

        stack1->push(x);
        cout << "Enqueued " << x << endl;
    }

    int dequeue(){
        if(stack2->isEmpty()){
            if(stack1->isEmpty()){
                cout << "\nQueue is empty! " << endl;
                return -1;
            }

            while(!stack1->isEmpty()){
                stack2->push(stack1->pop());
            }
        }

        return stack2->pop();
    }


    bool isEmpty(){
        return stack1->isEmpty() && stack2->isEmpty();
    }

    void display(){
        if(isEmpty()){
            cout << "\nQueue is empty!" << endl;
            return;
        }

        // Display elements from stack2 (which is in correct queue order)
        Stack* tempStack2 = new Stack(capacity);
        while(!stack2->isEmpty()){
            int val = stack2->pop();
            cout << val << " ";
            tempStack2->push(val);
        }

        while(!tempStack2->isEmpty()){
            stack2->push(tempStack2->pop());
        }

        //Display elements from stack1 (in reverse order)
        Stack* tempStack1 = new Stack(capacity);
        while(!stack1->isEmpty()){
            tempStack1->push(stack1->pop());
        }

        while(!tempStack1->isEmpty()){
            int val = tempStack1->pop();
            cout << val << " ";
            stack1->push(val);
        }

        cout << endl;
    }
};


int main() {
    QueueStack queue(10);  // Queue with a capacity of 10 elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    cout << "Current queue: ";
    queue.display();
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Current queue after dequeue: ";
    queue.display();
    queue.enqueue(6);
    queue.enqueue(7);
    cout << "Current queue after enqueue: ";
    queue.display();

}