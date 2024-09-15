#include<iostream>
using namespace std;

int main(){
    int num, n, index;
    cout << "Enter number of elements you want in the array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cout << "Index " << i  << " : ";
        cin >> arr[i];
    }

    cout << "\nEnter value you want to search: ";
    cin >> num;

    for(int i = 0; i < n; ++i){
        if(arr[i] == num){
            index = i;
            break;
        }
    }

    cout << "\n" << num << " is at index " << index << endl;
}