#include <iostream>
using namespace std;

int factorial_non_tailed(int n){
    if(n == 1) return 1;
    else{
        return n*factorial_non_tailed(n - 1);
    } 
}

int factorial_tailed(int n, int result = 1) {
    if (n <= 1) {
        return result;
    }
    return factorial_tailed(n - 1, n * result);
}

int main(){
    int number;
    cout << "Enter a number to compute its factorial: ";
    cin >> number;

    // Non-Tail Recursive Factorial
    cout << "Factorial (Non-Tail): " << factorial_non_tailed(number) << endl;

    // Tail Recursive Factorial
    cout << "Factorial (Tail): " << factorial_tailed(number) << endl;
}