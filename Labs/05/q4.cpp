#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target){
    if(left > right){
        return -1; //means target not found
    }

    int mid = left + (right - left) / 2;

    if(arr[mid] == target) return mid;

    else if(arr[mid] > target){
        return binarySearch(arr, left, mid-1, target);
    }
    else {
        return binarySearch(arr, mid+1, right, target);
    }
}


int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target = 7;
    int binary_search = binarySearch(arr, 0, size - 1, target);

    if(binary_search != -1){
        cout << "Element found at index " << binary_search << endl;
    }

    else cout << "Element not found." << endl;
}