//2279
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
 
#define int ll

using namespace std;

const int N = 50 + 7;

main(){
	
	NFS	
	
	int n;
	cin >> n;
	
	string ans = "";
	int pw = 1, hs = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		
		char c = (char)((hs + x) / (1LL << i) + 97);
		hs = -x;
		ans += c;
	}
	
	cout << ans;
	
	ioi
}
