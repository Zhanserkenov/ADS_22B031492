//234
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);
 
#define inf (int)1e9+7
 
#define F first
#define S second
 
#define pb push_back
#define ppb pop_back
 
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
 
#define sz(x) x.size()
 
#define all(x) x.begin(),x.end()
 
#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int rowSum(const vector<int>& row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
}

bool compareRows(const vector<int>& row1, const vector<int>& row2) {

    int sum1 = rowSum(row1);
    int sum2 = rowSum(row2);
    if (sum1 != sum2) {
        return sum1 > sum2;
    }
    
    for (int i = 0; i < row1.size(); i++) {
        if (row1[i] != row2[i]) {
            return row1[i] < row2[i];
        }
    }

    return false;
}

int main() {

	NFS
	
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }

    sort(all(rows), compareRows);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rows[i][j] << ' ';
        }
        cout << '\n';
    }

    ioi
}
