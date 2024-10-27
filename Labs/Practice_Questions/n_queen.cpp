#include <iostream>
using namespace std;

class NQueens{
private:
    int N;
    int** board;
    int solutioncount;

    bool isSafe(int row, int col){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 1) return false;
        }

        for(int i = 0; i < col; i++){
            if(board[row][i] == 1)return false;
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 1) return false;
        }

        for(int i = row, j = col; i >= 0 && j < N; i--, j++){
            if(board[i][j] == 1) return false;
        }

        return true;
    }

public:
    NQueens(int n) : N(n) {
        board = new int*[N];
        for(int i = 0; i < N; i++){
            board[i] = new int[N] ();
        }
        solutioncount = 0;
    }

    ~NQueens(){
        for(int i = 0; i < N; i++){
            delete board[i];
        }

        delete board;
    }

    void queen(int row){
        if(row == N){
            printBoard();
            cout << "------------------" << endl;
            solutioncount++;
            return;
        }

        for(int i = 0; i < N; i++){
            if(isSafe(row, i)){
                board[row][i] = 1;
                queen(row + 1);
                board[row][i] = 0; //backtrack
            }
        }
    }

    void printBoard(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << (board[i][j] == 1 ? 'Q' : '.');
            }
            cout << endl;
        }
    }

    void solve(){
        queen(0);
    }

    void solutioncounts(){
        cout << "Number of solutions: " << solutioncount << endl;
    }

};

int main(){
    int n = 8;
    NQueens q(n);
    q.solve();
    q.solutioncounts();
}