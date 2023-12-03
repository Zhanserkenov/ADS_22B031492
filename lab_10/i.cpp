//2203
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool topologicalSort(int n, vector<vector<int>>& requirements, vector<int>& inDegree, vector<int>& order) {
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
            order.push_back(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : requirements[current]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                q.push(next);
                order.push_back(next);
            }
        }
    }

    return order.size() == n;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> requirements(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        requirements[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> order;
    bool possible = topologicalSort(n, requirements, inDegree, order);

    if (possible) {
        cout << "Possible\n";
        for (int i : order) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
