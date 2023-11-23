//1663
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
	
	string s;
	cin >> s;
	int k;
	cin >> k;

	string t;
	cin >> t;
	
	int hs = calc(s);
		
	pw[0] = 1;
	h[0] = (s[0] - 'a' + 1);
	int p = 31;
	for(int i = 1; i < sz(t); i++){
		h[i] = p * h[i - 1] + (t[i] - 'a' + 1);
		pw[i] = pw[i - 1] * p;
	}
	
	for(int i = 0; i < sz(t); i++){
		if(i + sz(s) - 1 < sz(t) && geth(i, i + sz(s) - 1) == hs){
			k--;
			i = i + sz(s) - 1;
			if(k == 0){
				cout << "YES";
				ioi
			}
		}
	}
	
	cout << "NO";
	
	ioi
}
