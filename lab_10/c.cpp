//2105
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int dist[MAX], parent[MAX];

int main() {
    int A, B;
    cin >> A >> B;

    queue<int> q;
    q.push(A);
    dist[A] = 0;
    parent[A] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == B) {
            vector<int> path;
            for (int v = cur; v != A; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());

            cout << dist[B] << endl;
            for (int num : path) {
                cout << num << " ";
            }
            cout << endl;
            return 0;
        }

        if (cur * 2 < MAX && !dist[cur * 2]) {
            q.push(cur * 2);
            dist[cur * 2] = dist[cur] + 1;
            parent[cur * 2] = cur;
        }
        if (cur - 1 > 0 && !dist[cur - 1]) {
            q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
            parent[cur - 1] = cur;
        }
    }

    return 0;
}
