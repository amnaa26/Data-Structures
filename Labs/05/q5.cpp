#include <iostream>
using namespace std;

class NQueens{
private:
    int N;
    int** board;
    int solution_count;

    bool isSafe(int row, int col){

        //checking column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 1) return false;
        }

        //checking upper left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 1) return false;
        }

        //checking upper right diagonal
         for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) return false;
        }

        return true;
    }

    void Queen(int row){
         if (row == N) {
            printBoard(); 
            solution_count++; 
            return;
        }

        for(int col = 0; col < N; col++){
            if(isSafe(row, col)){
                board[row][col] = 1; //placed the queen
                Queen(row + 1); //moving to the next row
                board[row][col] = 0; //backtrack
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl << "----------------\n"; 
    }

public:
     NQueens(int n) : N(n) {
        board = new int*[N];
        for (int i = 0; i < N; i++) {
            board[i] = new int[N]();
        }
        solution_count = 0;
    }

    ~NQueens() {
        for (int i = 0; i < N; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

     void solve() {
        Queen(0);
    }

    void printSolutions() {
        std::cout << "Total Solutions: " << solution_count << std::endl;
    }

};


int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    NQueens nQueens(N);
    nQueens.solve();
    nQueens.printSolutions();

    return 0;
}