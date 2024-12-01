/*
Merge K Sorted Lists using a Min-Heap. Given K sorted linked lists, write a
function to merge them into a single sorted list.
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int v) : val(v), next(nullptr) {}
};

struct HeapNode{
    int val;
    int listindex;
    ListNode* node; //pointer to the node
};

class heap{
private:
    vector<HeapNode> hn;

    //maintaining min heap properties after removing root
    void heapifydown(int i){
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < hn.size() && hn[left].val < hn[smallest].val) smallest = left;
        if(right < hn.size() && hn[right].val < hn[smallest].val) smallest = right;

        if(smallest != i){
            swap(hn[smallest], hn[i]);
            heapifydown(smallest);
        }
    }

    //maintaining min heap properties after insertion
    void heapifyup(int i){
        int parent = (i-1) / 2;
        if(i > 0 && hn[i].val < hn[parent].val){
            swap(hn[i], hn[parent]);
            heapifyup(parent);
        }
    }

public:
    void insert(HeapNode node){
        hn.push_back(node);
        heapifyup(hn.size() - 1);
    }

    HeapNode extractmin(){
        if(hn.empty()){
            cout << "Heap is empty.." << endl;
            return {0, -1, nullptr};
        }

        HeapNode root = hn[0]; //root value is now stored in root
        hn[0] = hn.back(); //last value i.e max val is now stored in the root val of min heap
        hn.pop_back();

        if (!hn.empty()) heapifydown(0); //maintaing properties of heap

        return root;
    }

    bool isEmpty(){
        return hn.empty();
    }
};


ListNode* mergeKlists(vector<ListNode*>& lists){
    heap minheap;

    for(int i = 0; i < lists.size(); i++){
        if(lists[i] != nullptr){
            minheap.insert({lists[i]->val, i, lists[i]});
        }
    }

    ListNode* dummy = new ListNode(0); // Dummy node for the result list
    ListNode* current = dummy;

    while (!minheap.isEmpty()) {
        // Extract the minimum node
        HeapNode minNode = minheap.extractmin();
        current->next = minNode.node; // Add this node to the result list
        current = current->next;

        // If there is a next node in the same list, insert it into the heap
        if (minNode.node->next != nullptr) {
            minheap.insert({minNode.node->next->val, minNode.listindex, minNode.node->next});
        }
    }

    return dummy->next; // Return the merged list, skipping the dummy node
}


// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// Test case
int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    cout << "\nList1: " << endl;
    printList(list1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    cout << "\nList2: " << endl;
    printList(list2);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    cout << "\nList3: " << endl;
    printList(list3);

    vector<ListNode*> lists = {list1, list2, list3};

    ListNode* result = mergeKlists(lists);
    cout << "\nMerged list: " << endl;
    printList(result);

    return 0;
}