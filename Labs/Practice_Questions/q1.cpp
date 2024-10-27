/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the
destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to
destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R'
(right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it
while value 1 at a cell in the matrix represents that rat can be travel through it.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> allPaths;
    
    void findPaths(vector<vector<int>>& mat, vector<vector<bool>>& visited, int i, int j, string path, int n) {
        // Base condition: if the destination (n-1, n-1) is reached, save the path and return
        if (i == n - 1 && j == n - 1) {
            allPaths.push_back(path);
            return;
        }
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Move Down
        if (i + 1 < n && mat[i + 1][j] == 1 && !visited[i + 1][j]) {
            findPaths(mat, visited, i + 1, j, path + "D", n);
        }
        
        // Move Left
        if (j - 1 >= 0 && mat[i][j - 1] == 1 && !visited[i][j - 1]) {
            findPaths(mat, visited, i, j - 1, path + "L", n);
        }
        
        // Move Right
        if (j + 1 < n && mat[i][j + 1] == 1 && !visited[i][j + 1]) {
            findPaths(mat, visited, i, j + 1, path + "R", n);
        }

        // Move Up
        if (i - 1 >= 0 && mat[i - 1][j] == 1 && !visited[i - 1][j]) {
            findPaths(mat, visited, i - 1, j, path + "U", n);
        }
        
        // Backtrack: Unmark the current cell as visited
        visited[i][j] = false;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& mat, int n) {
        // Edge case: if starting point is blocked
        if (mat[0][0] == 0) return {};

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";
        
        // Start finding paths from (0, 0)
        findPaths(mat, visited, 0, 0, path, n);
        
        return allPaths;
    }
};


int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = mat.size();
    
    Solution solution;
    vector<string> result = solution.ratInMaze(mat, n);
    
    if(result.empty()) {
        cout << "No paths found." << endl;
    } else {
        cout << "All possible paths are:" << endl;
        for (string path : result) {
            cout << path << endl;
        }
    }

}
