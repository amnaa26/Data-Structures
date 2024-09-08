/*
 * Programmer: Amna(23k-0066)
 * Date: 2/Sept/2024
 * Desc: Create a singly linked list and write functions to
             Insert node at front
             Insert node at end
             Insert node before and after a given value
             Delete node from head
             Delete last node
             Delete node of a particular value
             Count number of nodes
*/

#include<iostream>
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
    
    
    void InsertAtEnd(const int value){
        Node *n = new Node(value);
        if (head == NULL){
            head = n;
        }
        else{
            Node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
           current->next = n;
           n->next = NULL; //This is now our tail
        }
    }
    
    void InsertBeforeValue(int before_value, int data){
    	if(head == NULL){
    		cout << "Linked list is empty"<<endl;
		}
		
		else{
			if(head->data == before_value){ //if our target node is head and we want to add value before the head so this if condition is for this purpose
				InsertAtFront(data);
			}
			
			else{
				Node* current = head;
				while(current->next != NULL && current->next->data != before_value){
					current = current->next;
				}
				
				if(current->next == NULL){
					cout << "Node with value " << before_value << " not found." << endl;
				}
				
				else{
					Node* newNode = new Node(data);
					newNode -> next = current->next;
					current->next = newNode;
				}
			}
		}
	}
	
	
	void InsertAfterValue(int target_data, int data){
		Node* current = head;
		while(current != NULL && current->data != target_data ){
			current = current->next;
		}
		
		if(current == NULL) cout << "Node with value " << target_data << " not found" << endl;
		else{
			Node* newNode = new Node(data);
			newNode->next = current->next;
			current->next = newNode;
		}
	}
	
	void DeleteFromHead(){
		if(head == NULL) cout << "List is empty" << endl;
		else{
			Node* temp = head;
			head = head -> next;
			delete temp;
		}
	}
	
	void DeleteFromTail(){
		if(head == NULL) cout << "List is empty" << endl;
		else{
			if(head->next == NULL){
				delete head;
				head = NULL;
				return;
			}
			
			Node* secondLast = head;
			while(secondLast->next->next != NULL){
				secondLast = secondLast->next;
			}
			delete secondLast->next;
			secondLast->next = NULL;
		}
	}
	
	void DeleteParticularValue(int value){
		if(head == NULL) cout << "List is empty" << endl;
		else{
			if(head->data == value){ //The node to del is the head
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			else{
				Node* current = head;
				while(current->next != NULL && current->next->data != value){
					current = current->next;
				}
				
				if(current->next == NULL){
					cout << "Node with value " << value << " not found." << endl;
				}
				else{
					Node* temp = current->next;
					current->next = current->next->next;
					delete temp;
				}
			}
		}
	}
	
	int countNodes(){
		int count = 0;
		Node* current = head;
		while(current != NULL){
			count++;
			current = current->next;
		}
		return count;
	}
	
	void printList(){
		Node* current = head;
		while(current != NULL){
			cout << current->data << " -> ";
			current = current->next;
		}
		
		cout << "nullptr" << endl;
	}

};



int main(){
	SinglyLinkedList linkedlist;
	linkedlist.InsertAtFront(3);
	linkedlist.InsertAtEnd(5);
	linkedlist.InsertAfterValue(3, 4);
	linkedlist.InsertBeforeValue(5, 2);
	linkedlist.InsertBeforeValue(2, 33);
	linkedlist.printList();

	
	linkedlist.DeleteFromHead();
	cout << "\nLinked-list after deleting head: " << endl;
	linkedlist.printList();
	linkedlist.DeleteFromTail();
	cout << "\nLinked-list after deleting tail: " << endl;
	linkedlist.printList();
	linkedlist.DeleteParticularValue(33);
	cout << "\nLinked-list after deleting value 33: " << endl;
	linkedlist.printList();
	int count = linkedlist.countNodes();
	cout << "\nCount of nodes: " << count << endl;
}
