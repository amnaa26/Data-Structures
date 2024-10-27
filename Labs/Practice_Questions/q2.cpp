/*
A two dimensional array of characters can be considered as a field. Each cell is either water 'W' or a
tree 'T'. A forest is a collection of connected trees. Two trees are connected if they sharea side i.e. if they
are adjacent to each other with respect to any of the four sides. Given the information about the field, write
a function which inputs this 2-D array and returns the size of the largest forest, where size of a forest is the
number of trees in it.
*/


#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>>& field, int x, int y, vector<vector<bool>>& visited) {
    // Check for out of bounds and if the cell is water or already visited
    if (x < 0 || x >= field.size() || y < 0 || y >= field[0].size() ||
        field[x][y] == 'W' || visited[x][y]) {
        return 0;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    int count = 1; //count gives size of the forest

    // Explore all four adjacent cells
    count += dfs(field, x + 1, y, visited); // down
    count += dfs(field, x - 1, y, visited); // up
    count += dfs(field, x, y + 1, visited); // right
    count += dfs(field, x, y - 1, visited); // left

    return count;
}

int largestForestSize(vector<vector<char>>& field) {
    if (field.empty()) return 0;

    int maxForestSize = 0;
    int rows = field.size();
    int cols = field[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Iterate through each cell in the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If we find an unvisited tree, perform DFS
            if (field[i][j] == 'T' && !visited[i][j]) {
                int currentForestSize = dfs(field, i, j, visited);
                maxForestSize = max(maxForestSize, currentForestSize);
            }
        }
    }

    return maxForestSize;
}

int main() {
    vector<vector<char>> field = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'T'}
    };

    int largestSize = largestForestSize(field);
}
