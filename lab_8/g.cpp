//2292
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

const int N = 2000 + 7;

int h[N], pw[N];

int geth(int l,int r){
    if(l == 0) return h[r];
    else return h[r] - h[l - 1] * pw[r - l + 1];

}

main(){
	
	NFS	
	
	string s;
	cin >> s;
	
	pw[0] = 1;
	h[0] = (s[0] - 'a' + 1);
	int p = 31;
	for(int i = 1; i < sz(s); i++){
		h[i] = p * h[i - 1] + (s[i] - 'a' + 1);
		pw[i] = pw[i - 1] * p;
	}
	
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		
		int cnt = 0;
		int ans = geth(x - 1, y - 1);
		for(int i = 0; i < sz(s); i++){
			if(i + (y - x) >= sz(s)) continue;
			if(ans == geth(i, i + (y - x))) cnt++;
		}
		
		cout << cnt << '\n';
	}
	
	
	ioi
}
