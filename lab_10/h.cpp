//2206
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col, int n, int m) {
    if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0') {
        return;
    }

    grid[row][col] = '0';  // Mark the current cell as visited

    // Explore neighboring cells in all four directions
    dfs(grid, row + 1, col, n, m);
    dfs(grid, row - 1, col, n, m);
    dfs(grid, row, col + 1, n, m);
    dfs(grid, row, col - 1, n, m);
}

int countIslands(vector<vector<char>>& grid, int n, int m) {
    int islandCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') {
                islandCount++;
                dfs(grid, i, j, n, m);
            }
        }
    }

    return islandCount;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = countIslands(grid, n, m);
    cout << result << endl;

    return 0;
}
