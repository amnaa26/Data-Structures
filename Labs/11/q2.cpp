/*
A fitness club stores its member IDs on a fixed-size table for quick access. Each unique member
ID is mapped to a position in the table using a hash function. Due to limited storage, the table
cannot have gaps left unused for long, so if a position is occupied, the system must look for the
next available slot for the new member ID.

    a. Create a hash table of size 7 and insert member IDs 10 - 60.
    b. Search for member IDs: 30, 50, 70.
    c. Delete member IDs: 20 and 40. Insert additional member IDs: 70, 80 to show how the deleted slots are reused.

Display the hash table after each operation.
*/


#include<iostream>
using namespace std;

class HASH{
public:
    int size;
    int capacity;
    int* array;

    HASH(int s) : size(s), capacity(0) {
        array = new int[s];
        for(int i = 0; i < s; i++){
            array[i] = -1;
        }
    }

    int hashfunction(int value){
        return (value % size);
    }

    void insert(int value){
        if(capacity == size){
            cout << "Hash table overflow.." << endl;
            return;
        }

        int key = hashfunction(value);
        int start = key;
        int firstDeleted = -1;

        while(array[key] != -1 && array[key] != value){
            if(array[key] == -1 && firstDeleted == -1){
                firstDeleted = key; //firstDeleted is the first deleted slot
            }

            key = (key + 1) % size;

            if(key == start){
                break;
            }
        }

        if(array[key] == value){
            cout << value << " already exists in the hash table.." << endl;
            return;
        }

        if(firstDeleted != -1){ //prefering the first deleted slot
            array[firstDeleted] = value;
        } else{
            array[key] = value;
        }
    
        capacity++;
        cout << value << " added to the hash table.." << endl;
    }

    void deletevalue(int value){
        int key = hashfunction(value);
        int start = key;
        
        while(array[key] != -1){
            if(array[key] == value){
                cout << value << " found.. "<< endl;
                array[key] = -1;
                cout << value << " deleted from index/key " << key << endl;
                capacity--;
                return;
            }

            key = (key + 1) % size;

            if (key == start) {  // Completed a full cycle
                break;
            }
        }

        cout << value << " does not exists in the hash table.." << endl;
    }

    void search(int value){
        int key = hashfunction(value);
        int start = key;

        while(array[key] != -1){
            if(array[key] == value){
                cout << value << " found at key: " << key << endl;
                return;
            }

            //moving to next slot
            key = (key + 1) % size;

            if(key == start){ // Completed a full cycle
                break;
            }
        }

        cout << value << " does not exists.." << endl;
        return;
    }

    void printtable(){
        for(int i = 0; i < size; i++){
            cout << "Key " << i << " , Values: " << array[i] << endl;
        }
    }

    ~HASH(){
        delete [] array;
    }
};


int main(){
    HASH h1(7);

    //inserting
    cout << "\nInserting members: " << endl;
    h1.insert(10);
    h1.insert(20);
    h1.insert(30);
    h1.insert(40);
    h1.insert(50);
    h1.insert(60);

    //print the table
    cout << "\nPrinting table.." << endl;
    h1.printtable();
 
    //searching..
    cout << "\nSearching for ids..." << endl;
    h1.search(30);
    h1.search(50);
    h1.search(70);

    //deleting
    cout << "\nDeleting member ids..." << endl;
    h1.deletevalue(20);
    h1.deletevalue(40);

    //print the table
    cout << "\nPrinting table.." << endl;
    h1.printtable();

    //inserting new members
    cout << "\nInserting new members..." << endl;
    h1.insert(70);
    h1.insert(80);

    //print the table
    cout << "\nPrinting table.." << endl;
    h1.printtable();
}
