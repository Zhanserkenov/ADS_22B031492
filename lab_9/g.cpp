//1979
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

vector<int> compute_prefix_function(const string& s) {
    int n = s.length();
    vector<int> prefix_function(n, 0);

    for (int i = 1; i < n; ++i) {
        int j = prefix_function[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = prefix_function[j - 1];
        }

        if (s[i] == s[j]) {
            ++j;
        }

        prefix_function[i] = j;
    }

    return prefix_function;
}

int main(){
    NFS
    
    string s;
    cin >> s;

    vector<int> prefix_function = compute_prefix_function(s);

    int len = s.length() - prefix_function[s.length() - 1];
    cout << len;

    ioi
}
