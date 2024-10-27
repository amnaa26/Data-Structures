#include <iostream>
#include<vector>
using namespace std;

struct ListNode{
    string name;
    int score;
    ListNode* next;
    ListNode(string name, int score): name(name), score(score), next(NULL) {}
};

void push(ListNode* &head, const string &name, int score){
    ListNode* newNode = new ListNode(name, score);
    newNode->next = head;
    head = newNode;
}

int max_score(ListNode* head){
    int maximum = 0;
    ListNode* curr = head;
    while(curr != NULL){
        maximum = max(maximum, curr->score);
        curr = curr->next;
    }

    return maximum;
}

//counting sort based on digits(exp)
void countingsort(ListNode* &head, int exp) {
    vector<ListNode*> buckets[10];

    ListNode* curr = head;
    while (curr != NULL) {
        int digit = (curr->score / exp) % 10;
        buckets[digit].push_back(curr);
        curr = curr->next;
    }

    //reconstructiing the linked list by iterating through the buckets
    ListNode* sortedHead = NULL;
    ListNode* sortedTail = NULL;
    
    for(int i = 0; i < 10; i++){
        for (ListNode* node : buckets[i]) {
            if (sortedHead == NULL) {
                sortedHead = node;
                sortedTail = sortedHead;
            } else {
                sortedTail->next = node;
                sortedTail = sortedTail->next;
            }
        }
    }

    // setting the last node's next to NULL
    if (sortedTail != NULL) {
        sortedTail->next = NULL;
    }

    // updating the head pointer to the sorted list
    head = sortedHead;
}


void radixSort(ListNode* &head) {
    int maxVal = max_score(head);
    //performing counting sort for each digit (exp represents 1, 10, 100...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingsort(head, exp);
    }
}


void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->name << " - " << curr->score << endl;
        curr = curr->next;
    }
}


int main() {
    ListNode* head = NULL;

    push(head, "Ayan", 90);
    push(head, "Ali", 60);
    push(head, "Sara", 70);
    push(head, "Zara", 50);
    push(head, "Jeena", 40);
    push(head, "Alice", 75);
    push(head, "Bob", 85);
    push(head, "Charlie", 95);
    push(head, "David", 65);
    push(head, "Eva", 100);
    push(head, "Frank", 50);

    cout << "Before sorting:" << endl;
    printList(head);

    radixSort(head);

    cout << "\nAfter sorting:" << endl;
    printList(head);
}