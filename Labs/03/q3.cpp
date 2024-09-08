/*
 * Programmer: Amna(23k-0066)
 * Date: 2/Sept/2024
 * Desc: Insert some elements in Singly Linked List and write a function to segregate even and odd numbers such that all even numbers precede odd numbers.
*/

#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node *next;
public:
    Node():data(0), next(NULL){}
    Node(const int d): data(d), next(NULL){}
    friend class SinglyLinkedList;
};


class SinglyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    SinglyLinkedList(): head(NULL), tail(NULL){}
    SinglyLinkedList(Node *n): head(n), tail(n) {}
    void InsertAtFront(const int value){
    	Node *n = new Node(value);
    	if(head == NULL){
    		head = n;
		}
		else{
			n -> next = head;
			head = n;
		}
	}

    void printList(){
		Node* current = head;
		while(current != NULL){
			cout << current->data << " -> ";
			current = current->next;
		}
		
		cout << "nullptr" << endl;
	}

    void segregateEvenOdd() {
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* current = head;

        while (current != NULL) {
            int value = current->data;

            if (value % 2 == 0) { 
                if (evenStart == NULL) {
                    evenStart = current;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            } else { // Odd
                if (oddStart == NULL) {
                    oddStart = current;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }

        // If no even numbers are present, return only odd list
        if (evenStart == NULL) {
            head = oddStart;
            return;
        }

        // Combining even and odd lists
        evenEnd->next = oddStart;

        // If odd numbers exist then terminating the list
        if (oddEnd != NULL) {
            oddEnd->next = NULL;
        }

        // Setting head to the start of the even list
        head = evenStart;
    }
};


int main() {
    SinglyLinkedList list;

    list.InsertAtFront(17);
    list.InsertAtFront(15);
    list.InsertAtFront(8);
    list.InsertAtFront(12);
    list.InsertAtFront(10);
    list.InsertAtFront(5);
    list.InsertAtFront(4);
    cout << "Original List: " << endl;
    list.printList();

    list.segregateEvenOdd();
    cout << "\nList after segregating even and odd numbers: " << endl;
    list.printList();

    return 0;
}
