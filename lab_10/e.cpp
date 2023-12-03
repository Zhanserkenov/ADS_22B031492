//2183
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

const int N = 1000 + 7;

vector<int> g[N];

int main(){
	
	NFS	
	
	int n, q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			
			if(x == 1){
				g[i].pb(j);
			} 
		}
	}
	
	while(q--){
		int a, b, c;
		cin >> a >> b >> c;
		
		auto f = lower_bound(all(g[a]), b);
		auto s = lower_bound(all(g[a]), c);
		auto t = lower_bound(all(g[b]), c);
		
		int ff = *f, ss = *s, tt = *t;
		if(ff == b && ss == c && tt == c){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}
	
	ioi
}
