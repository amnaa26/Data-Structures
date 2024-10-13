/*
Implement Quick Sort using linked list in C++. Define a node for a linked list with integer
data and a pointer to the next node. Write a function to swap two nodes in the linked list. Write
a function to partition the linked list using the last node as the pivot. Implement the Quick Sort
algorithm using the partition function and the swap function. Finally, write a function to print
the sorted linked list. Your implementation should be able to handle empty linked lists and
linked lists with only one node. Test your implementation with a sample linked list containing
the following integers: 10, 7, 8, 9, 1, 5, 3. The expected output after sorting should be: 1 3 5 7
8 9 10.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList(): head(NULL) {}

    // Function to push node to the front of the list
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to get the last node of the list (tail)
    Node* getTail() {
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }

    // Partition function to rearrange nodes
    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = NULL, *curr = head, *tail = pivot;

        while (curr != pivot) {
            if (curr->data < pivot->data) {
                // Move node to the head of the list
                if ((*newHead) == NULL)
                    (*newHead) = curr;

                prev = curr;
                curr = curr->next;
            } else {
                // Move node to the end of the list
                if (prev) {
                    prev->next = curr->next;
                }
                Node* temp = curr->next;
                curr->next = NULL;
                tail->next = curr;
                tail = curr;
                curr = temp;
            }
        }

        if ((*newHead) == NULL)
            (*newHead) = pivot;

        (*newEnd) = tail;

        return pivot;
    }

    // Recursive quicksort function
    Node* quickSortRecur(Node* head, Node* end) {
        if (!head || head == end)
            return head;

        Node* newHead = NULL, *newEnd = NULL;

        // Partition the list, newHead and newEnd will be updated
        Node* pivot = partition(head, end, &newHead, &newEnd);

        // Sort the list before pivot
        if (newHead != pivot) {
            Node* temp = newHead;
            while (temp->next != pivot) {
                temp = temp->next;
            }
            temp->next = NULL;

            newHead = quickSortRecur(newHead, temp);

            temp = getTail();
            temp->next = pivot;
        }

        // Sort the list after pivot
        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    // Function to sort the linked list using quicksort
    void QUICKSORT() {
        head = quickSortRecur(head, getTail());
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    list.push(10);
    list.push(7);
    list.push(8);
    list.push(9);
    list.push(1);
    list.push(5);
    list.push(3);

    cout << "Original List: ";
    list.printList();

    list.QUICKSORT();

    cout << "Sorted List: ";
    list.printList();

    return 0;
}
