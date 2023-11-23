//1623
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

const int N = 1e6 + 7;

int h[N], pw[N];

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

int main(){
	
	NFS	
	
	string a, b;
	cin >> a >> b;

	int hs = calc(b);
	int mn = max(2, int(ceil((double)(sz(b) / sz(a)))) + 2);
	
	
	string s = "";
	while(mn--){	
		s += a;
	}
	
	pw[0] = 1;
	h[0] = (s[0] - 'a' + 1);
	int p = 31;
	for(int i = 1; i < sz(s); i++){
		h[i] = p * h[i - 1] + (s[i] - 'a' + 1);
		pw[i] = pw[i - 1] * p;
	}
	
	int ans = -1;
	for(int i = 0; i < sz(s); i++){
		if(i + sz(b) - 1 < sz(s) && geth(i, (i + sz(b) - 1)) == hs){
			ans = ceil((double)(i + sz(b)) / sz(a));
			break;
		}
	}
	
	cout << ans;
	
	ioi
}
