/*
 * Programmer: Amna(23k-0066)
 * Date: 2/Sept/2024
 * Desc: Write a program to sort a doubly linked list and remove duplicates from the sorted list.
*/

#include <iostream>
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
    Node* head;

public:
    DoublyLinkedList(): head(NULL) {}

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

    // Sorting the list using bubble sort
    void sortList() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        Node* index = NULL;
        int temp;

        // Bubble Sort
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    // Swapping the data
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
        cout << "List sorted successfully.\n";
    }

    
    void removeDuplicates() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        while (current != NULL && current->next != NULL) {
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = duplicate->next;

                if (duplicate->next != NULL) {
                    duplicate->next->prev = current;
                }

                delete duplicate; // Free memory
            } else {
                current = current->next;
            }
        }
        cout << "Duplicates removed from the list.\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertEnd(5);
    list.insertEnd(3);
    list.insertEnd(8);
    list.insertEnd(3);
    list.insertEnd(7);
    list.insertEnd(5);

    cout << "Original List: ";
    list.display();

    list.sortList();
    cout << "Sorted List: ";
    list.display();

    list.removeDuplicates();
    cout << "List after removing duplicates: ";
    list.display();

    return 0;
}
