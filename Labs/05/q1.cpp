#include<iostream>
using namespace std;

void sort(int arr[], int size, int start){
    if(start == size+1) return;
    else{
        for(int i = 0; i < size; ++i){
            if(arr[start] < arr[i]) swap(arr[start], arr[i]);
        }

        sort(arr, size, start + 1);
    }
    
}



void print(int arr[], int size){
    cout << "[ ";
    for(int i = 0; i < size; ++i){
        cout << arr[i] << ", ";
    }
    cout << " ]" << endl;
}

int main(){
    const int size = 5;
    int arr[size] = {23, 4, 6, 9, 5};
    print(arr, size);
    sort(arr, size, 0);
    print(arr, size);


}

 