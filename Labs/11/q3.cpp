/*
A university uses an academic portal which has limited storage, so it adjusts its storage capacity
dynamically when the number of student IDs exceeds a certain threshold. However, these
unique IDs need to be strategically placed to minimize search times while ensuring that all slots
are accessible.

a. Create a hash table with an initial size of 7 and a load factor threshold of 0.75. Insert student IDs: 12, 22, 32, 42, 52, 62.
b. Search for student IDs: 22, 42, 72.
c. Insert additional IDs: 72, 82 to exceed the load factor threshold. Use a new hash function based on the resized table size.

Display the hash table after each operation.
*/

#include<iostream>
using namespace std;

class HASH{
private:
    void resize(){
        int oldsize = size;
        size = size * 2;

        int* oldtable = array;
        array = new int[size];

        for(int i = 0; i < size; i++){
            array[i] = -1;
        }

        for(int i = 0; i < oldsize; i++){
            if(oldtable[i] != -1){
                insert(oldtable[i]);
            }
        }

        delete [] oldtable; //free memory
        cout << "\nHash Table resized to new size " << size << endl;
    }

    float get_threshold(){
        return (float) capacity / size;
    }

public:
    int size;
    int capacity;
    int* array;
    float load_factor;

    HASH(int s, float loadfactor) : size(s), capacity(0), load_factor(loadfactor) {
        array = new int[s];
        for(int i = 0; i < s; i++){
            array[i] = -1;
        }
    }

    int hashfunction(int value){
        return (value % size);
    }

    void insert(int value){
        if(get_threshold() >= load_factor){
            resize();
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
    HASH h1(7, 0.75);

    //inserting student ids 12, 22, 32, 42, 52, 62
    cout << "\nInserting student ids.." << endl;
    h1.insert(12);
    h1.insert(22);
    h1.insert(32);
    h1.insert(42);
    h1.insert(52);
    h1.insert(62);
    cout << "\nPrinting table..." << endl;
    h1.printtable(); 

    //searching for student ids 22, 42, 72
    cout << "\nSearching.." << endl;
    h1.search(22);
    h1.search(42);
    h1.search(72);

    //inserting additional student ids 72, 82
    cout << "\nInserting student ids.." << endl;
    h1.insert(72);
    h1.insert(82);
    cout << "\nPrinting table..." << endl;
    h1.printtable(); 
}