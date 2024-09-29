#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;

    if (N < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = fibonacci(N);
    cout << "The " << N << "th Fibonacci number is: " << result << endl;

    return 0;
}
