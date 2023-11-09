//2276
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

const int N = 1e6 + 7;

int h[N], pw[N];
vector<pair<int, int>> v;

int calc(string s){
	int hs = 0, p = 31;
	for(int i = 0; i < sz(s); i++){
		hs = p * hs + (s[i] - 'a' + 1);
	}
	return hs;
}

int geth(int l,int r){
    if(l == 0) return h[r];
    else return h[r] - h[l - 1] * pw[r - l + 1];

}

main(){
	
	NFS	
	
	string s;
	cin >> s;

	int tt;
	cin >> tt;
	while(tt--){
		string t;
		cin >> t;
		
		v.pb({calc(t), sz(t)});
	}
	
	pw[0] = 1;
	h[0] = (s[0] - 'a' + 1);
	int p = 31;
	for(int i = 1; i < sz(s); i++){
		h[i] = p * h[i - 1] + (s[i] - 'a' + 1);
		pw[i] = pw[i - 1] * p;
	}
	
	
	int last = -1;
	for(int i = 0; i < sz(s); i++){
		for(int j = 0; j < sz(v); j++){
			if(i + v[j].S - 1 >= sz(s)) continue;
			if(geth(i, i + v[j].S - 1) == v[j].F){
				last = max(last, i + v[j].S - 1);
			}
		}
		if(i > last){
			cout << "NO";
			ioi
		}
	}
	
	cout << "YES";
	
	ioi
}
