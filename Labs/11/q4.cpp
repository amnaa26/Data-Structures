/*
A banking system is designed to store customer account numbers on a hash table. To ensure
data security and efficiency, the system uses an additional mathematical formula to decide the
next slot when collisions occur. This method ensures that even closely related account numbers
do not lead to clusters of occupied slots.

a. Create a hash table of size 11 to store customer account numbers. Use primary_hash = ID % table_size for the initial position and secondary_hash = 7 - (ID % 7) for the step size. Insert the following account numbers: 101, 111, 121, 131, 141, 151.
b. Search for account numbers: 111, 141, 161.
c. Delete account numbers: 111 and 131. Insert additional account numbers: 161 and 171 to demonstrate how the secondary formula resolves collisions while avoiding clustering.

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

    int secondaryhashfunction(int value){
        return 7 - (value % 7);
    }

    void insert(int value){
        if(capacity == size){
            cout << "Hash table overflow.." << endl;
            return;
        }

        int key = hashfunction(value);
        int start = key;
        int firstDeleted = -1;

        if(array[key] == value){
            cout << value << " already exists in the hash table.." << endl;
            return;
        }

        while(array[key] != -1 && array[key] != value){
            if(array[key] == -1 && firstDeleted == -1){
                firstDeleted = key; //firstDeleted is the first deleted slot
            }

            key = (key + secondaryhashfunction(value)) % size; //double hashing

            if(key == start){
                break;
            }
        }

       if(array[key] == -1){
            if(firstDeleted != -1){ //prefering the first deleted slot
                array[firstDeleted] = value;
            } else{
                array[key] = value;
            }
    
            capacity++;
            cout << value << " added to the hash table.." << endl;
            return;
       }

       else  cout << value << " already exists in the hash table.." << endl;
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

            key = (key + secondaryhashfunction(value)) % size;

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
            key = (key + secondaryhashfunction(value)) % size;

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
    HASH h1(11);

    //inserting customer ids 101, 111, 121, 131, 141, 151
    cout << "\nInserting customer ids.." << endl;
    h1.insert(111);
    h1.insert(121);
    h1.insert(131);
    h1.insert(141);
    h1.insert(151);
    cout << "\nPrinting hash table: " << endl;
    h1.printtable();

    //Search for account numbers: 111, 141, 161.
    cout << "\nSearching for customer ids 111, 141, 161.." << endl;
    h1.search(111);
    h1.search(141);
    h1.search(161);

    // Delete account numbers: 111 and 131
    cout << "\nDeleting account numbers.. " << endl;
    h1.deletevalue(111);
    h1.deletevalue(131);
    cout << "\nPrinting hash table: " << endl;
    h1.printtable();

    //Insert additional account numbers: 161 and 171
    cout << "\nInserting customer ids.." << endl;
    h1.insert(161);
    h1.insert(171);
    cout << "\nPrinting hash table: " << endl;
    h1.printtable();
}
