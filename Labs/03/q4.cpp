/*
 * Programmer: Amna(23k-0066)
 * Date: 2/Sept/2024
 * Desc: Create a doubly linked list and write functions to
             Insert node at front
             Insert node at end
             Insert node before and after a given value
             Delete node from head
             Delete last node
             Delete node of a particular value
*/

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};


class DoublyLinkedList {
private:
    Node* head; // Pointer to head of the list

public:
    DoublyLinkedList(): head(NULL) {}
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode; // First node becomes the head
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode; // New node becomes the head
        }
        cout << value << " inserted at the front.\n";
    }

    
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode; // First node becomes the head
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next; // Traversing to the end
            }
            temp->next = newNode;
            newNode->prev = temp; // Linking the new node to the previous one
        }
        cout << value << " inserted at the end.\n";
    }

    
    void insertBefore(int value, int before) {
        Node* newNode = new Node(value);
        Node* temp = head;
        while (temp != NULL && temp->data != before) {
            temp = temp->next;
        }

        if (temp == NULL) cout << "Value " << before << " not found in the list.\n";
        else {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = newNode;
            } else {
                head = newNode; // If inserting before the head
            }
            temp->prev = newNode;
            cout << value << " inserted before " << before << ".\n";
        }
    }

    
    void insertAfter(int value, int after) {
        Node* newNode = new Node(value);
        Node* temp = head;
        while (temp != NULL && temp->data != after) {
            temp = temp->next;
        }

        if (temp == NULL) cout << "Value " << after << " not found in the list.\n";
        else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            cout << value << " inserted after " << after << ".\n";
        }
    }

   
    void deleteFront() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        cout << "Node with value " << temp->data << " deleted from the front.\n";
        delete temp;
    }

   
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) temp->prev->next = NULL;
        else head = NULL; // If the list only had one node
        cout << "Node with value " << temp->data << " deleted from the end.\n";
        delete temp;
    }

    
    void deleteValue(int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != value) temp = temp->next;
        if (temp == NULL) {
            cout << "Value " << value << " not found in the list.\n";
            return;
        }

        if (temp->prev != NULL) temp->prev->next = temp->next; 
        else head = temp->next; // If deleting the head
        
        if (temp->next != NULL) temp->next->prev = temp->prev;
        cout << "Node with value " << value << " deleted from the list.\n";
        delete temp;
    }

    // Function to print the list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> "; // Display nodes
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertFront(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertBefore(15, 20);
    list.insertAfter(25, 20);
    list.display();

    list.deleteFront();
    list.display();

    list.deleteEnd();
    list.display();

    list.deleteValue(15);
    list.display();

    return 0;
}
