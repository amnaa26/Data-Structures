/*
Sliding Window Maximum. Given an array nums and an integer k, implement a
function that finds the maximum element in every sliding window of size k using
a max-heap.
*/

#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
private:
    vector<int>heap;
    vector<int>indices;

    void swap(int i, int j){
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;

        int temp_index = indices[i];
        indices[i] = indices[j];
        indices[j] = temp_index;
    }

    //used after removing the top element
    void heapifyDown(int index){
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < heap.size() && heap[left] > heap[largest]){
            largest = left;
        }

        if(right < heap.size() && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest != index){
            swap(index, largest);
            heapifyDown(largest);
        }
    }

    //used after inserting a new element
    void heapifyUp(int index){
        int parent = (index - 1) / 2;
        if(index > 0 && heap[index] > heap[parent]){
            swap(index, parent);
            heapifyUp(parent);
        }
    }

public:
    void push(int value, int index){
        heap.push_back(value);
        indices.push_back(index);
        heapifyUp(heap.size() - 1);
    }

    //removing the top element i.e max element
    void pop(){
        if(heap.empty()) return;

        heap[0] = heap.back(); //replace root with last element
        indices[0] = indices.back();
        heap.pop_back(); //deleting the top element i.e max which is now the last element
        indices.pop_back();
        heapifyDown(0);
    }

    int topValue(){
        return heap.empty() ? -1 : heap[0];
    }

    int topIndex(){
        return heap.empty() ? -1 : indices[0];
    }

    //removing elements outside of sliding window
    void removeOutOfWindow(int windowStart){
        while(!heap.empty() && indices[0] < windowStart){
            pop();
        }
    }

    bool empty(){
        return heap.empty();
    }
};


//function to find sliding window max using heaps
vector<int> slidingWindowMax(vector<int>& nums, int k){
    MaxHeap maxheap;
    vector<int> results;

    for(int i = 0; i < nums.size(); i++){
        //add current element to the heap
        maxheap.push(nums[i], i);

        maxheap.removeOutOfWindow(i-k+1);

        if(i >= k - 1){
            results.push_back(maxheap.topValue());
        }
    }

    return results;
}


int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMax(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int maxVal : result) {
        cout << maxVal << " ";
    }
    cout << endl;

    return 0;
}