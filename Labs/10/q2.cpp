/*
Find the k largest elements in an array using a Min-Heap. Implement a function
that finds the k largest elements in an array using a min-heap.
*/

#include<iostream>
#include<vector>
using namespace std;

void minHeapify(vector<int>& heap, int i, int size){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] < heap[smallest]) smallest = left;
    if(right < size && heap[right] < heap[smallest]) smallest = right;

    if(smallest != i){ //means smallest is not root
        swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest, size);
    }
}

//function to build a min heap 
void build(vector<int>& heap, int size){
    for(int i = 0; i < size; i++){
        minHeapify(heap, i, size);
    }
}

//function to find k largest elements
vector<int> find_K_largest_elements(vector<int>& array, int k){
    vector<int> heap (array.begin(), array.begin() + k);
    build(heap, k);

    for(int i = k; i < array.size(); i++){
        if(array[i] > array[0]){
            heap[0] = array[i];
            minHeapify(heap, 0, k);
        }
    }

    return heap;
}


int main() {
    vector<int> arr = {5, 3, 1, 10, 12, 7, 9};
    int k = 3;

    vector<int> result = find_K_largest_elements(arr, k);

    cout << "The " << k << " largest elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
}