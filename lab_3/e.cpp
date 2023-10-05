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

struct node{
	int x, y, x1, y1;
};

int n, k;
vector<node> v;

bool ch(int q){
	int cnt = 0;
	for(int i = 0; i < sz(v); i++){
		if(max(v[i].x, v[i].x1) <= q && max(v[i].y, v[i].y1) <= q){
			cnt++;
		}
	}
	if(cnt < k) return 0;
	return 1;
}

int main(){
	
	NFS	
	
	cin >> n >> k;

	for(int i = 1; i <= n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		v.pb({a, b, c, d});
	}
	
	int l = 1, r = inf;
	while(l <= r){
		int md = (l + r) / 2;
		
		if(ch(md) == 1){
			r = md - 1;
		}
		else{
			l = md + 1;
		}
	}
	
	cout << r + 1;
	
	ioi
}
