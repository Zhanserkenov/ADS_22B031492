//2115
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

const int N = 5000 + 7;

vector<int> g[N];
bool red[N], used[N];
int dst[N];

int main(){
	
	NFS	
	
	int n, m, q;
	cin >> n >> m >> q;

	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		
		g[x].pb(y);
		g[y].pb(x);
	}
	
	bool ch = 0;
	while(q--){
		int type, v;
		cin >> type >> v;
		
		if(type == 1){
			red[v] = 1;
			ch = 1;
		}
		else{
			if(red[v] == 1){
				cout << 0 << '\n';
			}
			else if(ch == 0){
				cout << -1 << '\n';
			}
			else{
				for(int i = 1; i <= n; i++){
					used[i] = 0;
					dst[i] = 0;
				}
				queue<int> q;
				q.push(v);
				used[v] = 1;
				bool che = 0;
				
				while(!q.empty()){
					int x = q.front();
					q.pop();
					
					if(red[x] == 1){
						cout << dst[x] << '\n';
						che = 1;
						break;
					}
					
					for(auto to : g[x]){
						if(!used[to]){
							used[to] = 1;
							q.push(to);
							dst[to] = dst[x] + 1;
						}
					}
				}
				if(che == 0) cout << -1 << '\n';
			}
		}
	}
	
	ioi
}
