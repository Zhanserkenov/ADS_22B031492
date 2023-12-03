//2097
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1005;
int grid[MAX][MAX];
int mario[MAX][MAX];
int m, n;

bool isValid(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                mario[i][j] = 1;
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mario[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int minutes = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isValid(nx, ny) && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        minutes++;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
	
    if(minutes == 0){
    	cout << 0;
    	return 0;
    }
    cout << minutes - 1 << endl;
    return 0;
}
