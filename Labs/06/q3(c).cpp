/*
Implement (a) with the linked list.
*/

#include <iostream>
using namespace std;

#define MAX 10

class Node{
private:
    int passenger;
    Node* next;

public:
    Node(int p) : passenger(p), next(nullptr) {}
    friend class TicketQueue;
};

class TicketQueue{
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    TicketQueue() : front(nullptr), rear(nullptr), size(0), capacity(MAX) {}

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int passenger){
        if (isFull()) {
            cout << "Queue is full! Cannot add more passengers." << endl;
            return;
        }

        Node* newNode = new Node(passenger);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }

        else{
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        //cout << "Passenger " << passenger << " added to the ticket queue." << endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty! No passengers to remove." << endl;
            return;
        }

        Node* temp = front;
        //cout << "Passenger " << front->passenger << " has purchased the ticket and now has left the queue." << endl;
        front = front->next;
        delete temp;

        size--;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Ticket queue is empty!" << endl;
            return;
        }

        cout << "Current ticket queue: " << endl;
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->passenger << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~TicketQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


int main() {
    TicketQueue queue;
    for (int i = 1; i <= 10; ++i) {
        queue.enqueue(i);
    }
    queue.displayQueue();

    for (int i = 0; i < 5; ++i) {
        queue.dequeue();
    }
    queue.displayQueue();


    for (int i = 11; i <= 15; ++i) {
        queue.enqueue(i);
    }
    queue.displayQueue();

    return 0;
}