#include <iostream>
using namespace std;

struct runners{
    string name;
    int finish_time;
};

void merge(runners* RUNNERS, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    runners* leftarray = new runners[n1];
    runners* rightarray = new runners[n2];

    //copying data of original array from start till mid in a temp array
    for(int i = 0; i < n1; i++){
        leftarray[i] = RUNNERS[left+i]; 
    }

    //copying data of original array from mid+1 till end in a temp array
    for(int i = 0; i < n2; i++){
        rightarray[i] = RUNNERS[mid+1+i];
    }

    int i = 0, j = 0, k= left;
    while(i < n1 && j < n2){
        if(leftarray[i].finish_time <= rightarray[j].finish_time){
            RUNNERS[k] = leftarray[i];
            i++;
        } else{
            RUNNERS[k] = rightarray[j]; 
            j++;
        }

        k++;
    }

    //copying elements if any left(ya know the one who oculdnt be comapred beacuse the elements of other subarray were finished)
    while(i < n1){
        RUNNERS[k] = leftarray[i];
        i++;
        k++;
    }

    while(j < n2){
        RUNNERS[k] = rightarray[j];
        j++;
        k++;
    }

    delete [] leftarray;
    delete [] rightarray;
}

void mergesort(runners* r, int left, int right){
    int mid;
    if(left < right){
        mid = left + (right - left) / 2;
        mergesort(r, left, mid);
        mergesort(r, mid+1, right);
        merge(r, left, mid, right);
    }
}

int main(){
    const int MAX_PARTICIPANTS = 10;
    runners runners_list[MAX_PARTICIPANTS];
    for(int i = 0; i < MAX_PARTICIPANTS; i++){
        cout << "Enter the name of participant " << i+1  << " : ";
        cin >> runners_list[i].name;
        cout << "Enter the finish time of " << runners_list[i].name << " (in seconds) : ";
        cin >> runners_list[i].finish_time;
        cout << endl;
    }

    mergesort(runners_list, 0, MAX_PARTICIPANTS - 1);

    cout << "\nTop 5 fastest runners: " << endl;
    for(int i = 0; i < 5; i++){
        cout << runners_list[i].name << " : " << runners_list[i].finish_time << " seconds" << endl;
    }
    
}