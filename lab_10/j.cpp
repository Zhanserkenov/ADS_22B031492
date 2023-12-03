//2202
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

const int N = 1e5 + 7;

int ans;
bool used[N];
vector<int> g[N];

void dfs(int v){
	used[v] = 1;
	
	for(auto to : g[v]){
		if(!used[to]){
			if(sz(g[v]) < sz(g[to])) ans++;
			dfs(to);
		}
	}
}

int main(){
	
	NFS	
	
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		
		g[x].pb(y);
		//g[y].pb(x);
	}
	
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			ans++;
			dfs(i);
		}
	}
	
	cout << ans;
	
	ioi
}
