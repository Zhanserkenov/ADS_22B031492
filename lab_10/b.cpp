//2102
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

const int N = 100 + 7;

vector<int> g[N];
int dst[N];
bool used[N];

int main(){
	
	NFS	
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++) dst[i] = -1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			bool x;
			cin >> x;
			
			if(x == 1){
				g[i].pb(j);
			}
		}
	}
	
	int x, y;
	cin >> x >> y;
	
	queue<int> q;
	q.push(x);
	used[x] = 1;
	dst[x] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		
		for(int i = 0; i < sz(g[v]); i++){
			if(!used[g[v][i]]){
				q.push(g[v][i]);
				used[g[v][i]] = 1;
				dst[g[v][i]] = dst[v] + 1;
			}
		}
	}
	
	cout << dst[y];
	
	ioi
}
