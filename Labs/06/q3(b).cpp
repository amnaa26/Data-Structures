/*
b) Suggest and implement a potential solution or modification to this linear queue
implementation to handle this issue more effectively.
*/

#include <iostream>
using namespace std;

#define MAX 10

class TicketQueue {
private:
    int queue[MAX];  // array for queue
    int front;      
    int rear;       
    int size;      // Current count of passengers

public:
    TicketQueue() : front(0), rear(0), size(MAX) {} 

    bool isEmpty(){
        return front == rear;
    }

    bool isFull(){
         return ((rear + 1) % size == front);
    }

    void enqueue(int passenger) {
       if (isFull()) {
            cout << "Queue is full. Cannot add more passengers." << endl;
            return;
        }

        queue[rear] = passenger;  // Add passenger at the rear position
        rear = (rear + 1) % size;  // Move rear to the next position
        cout << "Passenger " << passenger << " added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }
        cout << "Passenger " << queue[front] << " has purchased a ticket and is removed from the queue." << endl;
        front = (front + 1) % size;  // Move front to the next position
    }

    void displayQueue() {
       if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i != rear; i = (i + 1) % size) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TicketQueue queue;
    for (int i = 1; i <= 10; i++) {
        queue.enqueue(i);
    }
    queue.displayQueue(); 

    for (int i = 0; i < 5; i++) {
        queue.dequeue();
    }
    queue.displayQueue(); 

    for (int i = 11; i <= 15; i++) {
        queue.enqueue(i);
    }
    queue.displayQueue(); 

}
