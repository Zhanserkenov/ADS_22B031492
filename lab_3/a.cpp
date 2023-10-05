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

const int N = 10000 + 7;

struct node{
	int val, posx, posy;
};

int a[N];
vector<node> v;

bool cmp(node i, node j){
	return i.val < j.val;
}

int main(){
	
	NFS	
	
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cin >> a[i];
	}
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x;
			cin >> x;
			
			v.pb({x, i, j});
		}
	}
	
	sort(all(v), cmp);
	
	for(int i = 1; i <= t; i++){
		int l = 0, r = sz(v) - 1;
		bool ok = 0;
		while(l <= r){
			int md = (l + r) / 2;
			if(v[md].val == a[i]){
				cout << v[md].posx - 1 << ' ' << v[md].posy - 1 << '\n';
				ok = 1;
				break;
			}
			if(v[md].val > a[i]){
				r = md - 1;
			}
			else{
				l = md + 1;
			}
		}
		if(ok == 0){
			cout << -1 << '\n';
		}
	}
	
	ioi
}
