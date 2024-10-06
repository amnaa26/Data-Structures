/*
(a) You are tasked with creating a ticketing system for a public transport service using a
    linear queue implemented with an array. The system allows passengers to queue up to
    purchase tickets. Once a passenger purchases their ticket, they are removed from the
    queue. The queue is configured to hold a maximum of 10 passengers at a time.
    Implement the “Ticket Queue” class, add 10 passengers to the queue and then remove the
    first 5 passengers. Now, attempt to add 5 more passengers to the queue, and observe the
    behavior of the queue.
*/

#include <iostream>
using namespace std;

#define MAX 10 //max size of queue

class TicketQueue{
private:
    int front;
    int rear;
    int queue[MAX]; //array to store queue

public:
    TicketQueue():front(0), rear(-1) {}

    bool isFull(){
        return rear == MAX - 1;
    }

    bool isEmpty(){
        return front > rear;
    }

    void enqueue(int id){
        if(isFull()){
            cout << "Queue is full! Cannot add more passsengers.\n";
            return;
        }

        rear++; // Incrementing rear to add new passenger
        queue[rear] = id; // Add passenger to the queue
        cout << "Passenger " << id << " added to the ticket queue.\n";
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty! No passengers to remove!" << endl;
            return;
        }

        cout << "Passenger " << queue[front] << " has purchased the ticket and now has left the queue.\n";
        front++; // Move the front pointer to the next passenger
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Current ticket queue: " << endl;
         for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    TicketQueue queue;
    for (int i = 1; i <= 10; i++) queue.enqueue(i);
    queue.display();

    for (int i = 0; i < 5; i++)queue.dequeue();
    queue.display();

    for (int i = 11; i <= 15; i++)queue.enqueue(i);
    queue.display();

}
