/*
 * Programmer : Amna(23k-0066)
 * Date : 26 aug 2024
 * Desc : Write a program that creates a 2D array of 5x5 values of type Boolean. Suppose indices represent people and the value at row i, column j of a 2D array is true just in case i and j are friends and
          false otherwise. You can use initializer list to instantiate and initialize your array to represent the
          following configuration: (* means “friends”)
                i/j 0 1  2  3 4
                0     *     * *
                1   *    *    *
                2        *
                3   *         *
                4   *  *    *

          Write a method to check whether two people have a common friend. For example, in the example above, 0 and 4
          are both friends with 3 (so they have a common friend), whereas 1 and 2 have no common friends.
*/


#include<iostream>
using namespace std;

#define size 5

bool mutual(bool friends[size][size], int i, int j){
    bool check = false;
    for(int k = 0; k < size; ++k){
        if(friends[i][k] && friends[j][k]){
            cout << k << " ";
            check = true;
        }
    }

    return check;
}


int main(){
    int i, j;
    bool friendship[size][size] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 0}
    };

    cout << "Enter person 1: "; cin >> i;
    cout << "Enter person 2: "; cin >> j;
    cout << "\nMutual friends: ";
    if(!mutual(friendship, i, j)) cout << "no mutual friends\n";
}