//1976
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

vector<int> prefix_function(string s) { 
  vector<int> pr(s.length());
  for(int i = 1; i < s.length(); i++) {
    int j = pr[i - 1];
    while(j > 0 && s[i] != s[j]) j = pr[j - 1];
    if (s[i] == s[j]) j++;
    pr[i] = j;
  }
  return pr;
}

int main() {

	NFS
	      
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int k;
        cin >> s >> k;
        vector<int> pi = prefix_function(s);
        int last = pi[s.size() - 1];
        cout << (sz(s) - last )* k + last << endl;
    }
    
    ioi
}
