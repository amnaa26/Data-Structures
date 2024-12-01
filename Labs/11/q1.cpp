/*
Design a library catalog system where each book is assigned a unique ID. To store and retrieve
book information efficiently, the system uses a hash table. However, due to limited storage
slots, books of the same authors map to the same index create a mechanism to handle
overlapping book IDs effectively.
Each book ID is a 3-digit number with 1st two numbers representing the book author and the last
digit is the book ID specific to that author.

    a. Create a hash table of size 10 and insert 9 records (3 for author A, 2 for author B, 4 for author C).
    b. Search for 2 of the author’s books inserted and 1 book that is not on the table.
    c. Delete the 2 books from part b.
    
Display the hash table after each operation.
*/


#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class HASH{
public:
    vector<vector<int>> table;
    int size;

    HASH(int s){
        size = s;
        table.resize(s);
    }

    int hashfunction(int value){
        return (value % size);
    }

    void insert(int value){
        int key = hashfunction(value);

        for(const auto &value1 : table[key]){
            if(value == value1){
                cout << value << " already exists in the table.." << endl;
                return;
            }
        }

        table[key].push_back(value);
        cout << value << " inserted at key: " << key << endl;
    }

    void deletevalue(int value){
        int key = hashfunction(value);
        auto it = find(table[key].begin(), table[key].end(), value);
        if(it != table[key].end()){
            cout << value << " found.." << endl;
            table[key].erase(it); //erase the key if found
            cout << value << " deleted from index/key: " << key << endl;
            return;
        }

        else{
            cout << value << " not found.." << endl;
            return;
        }
    }

    void search(int value){
        int key = hashfunction(value);
        auto it = find(table[key].begin(), table[key].end(), value);
        if(it != table[key].end()){
            cout << value << " found at key: " << key << endl;
            return;
        }
        else{
            cout << value << " does not exist in the table.." << endl;
            return;
        }
    }

    void printtable(){
        for(int i = 0; i < table.size(); i++){
            cout << "Key " << i << " , Values: ";
            for(const auto &value : table[i]){
                cout << value << " ";
            } 
            cout << endl;
        }
    }
};


int main(){
    HASH h1(10);

    //author A
    cout << "\nInserting books for author A, B, and C: " << endl;
    h1.insert(101);
    h1.insert(102);
    h1.insert(103);

    //author B
    h1.insert(201);
    h1.insert(202);

    //author C
    h1.insert(301);
    h1.insert(302);
    h1.insert(303);
    h1.insert(304);

    //print table
    cout << "\nPrinting the table: " << endl;
    h1.printtable();

    //searching
    cout << "\nSearching..."  << endl;
    h1.search(101);
    h1.search(102);
    h1.search(126);

    //print table;
    cout << "\nPrinting the table: " << endl;
    h1.printtable();

    //deleting
    cout << "\nDeleteing values: " << endl;
    h1.deletevalue(101);
    h1.deletevalue(102);

    //print table;
    cout << "\nPrinting the table: " << endl;
    h1.printtable();

    cout << "\nInserting a value which already exists: " << endl;
    h1.insert(304);
}


