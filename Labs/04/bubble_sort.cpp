#include<iostream>
using namespace std;

int main(){
    int arr[5];
    for(int i = 0; i < 5; ++i){
        cout << "Enter element " << i+1 << ": ";
        cin>>arr[i];
    }

    cout << "Printing original array: \n";
    for(int i = 0; i < 5; ++i){
        cout << arr[i] << ", ";
    }


    bool flag = false;
    for(int i = 0; i < 5 - 1; i++){
        for(int j = 5 - 1; j > i - 1; --j){
            if(arr[j] < arr[j - 1]){
                swap(arr[j], arr[j-1]);
                flag = true;
            }
        }

        if(flag != true) break;
    }

    cout << "\nPrinting swapped array: \n";
    for(int i = 0; i < 5; ++i){
        cout << arr[i] << ", ";
    }
}