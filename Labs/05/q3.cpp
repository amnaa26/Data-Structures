#include <iostream>
using namespace std;

#include <iostream>

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    std::cout << "Reversed list: ";
    printList(head);
    
    return 0;
}
