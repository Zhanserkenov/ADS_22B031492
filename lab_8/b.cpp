//2153
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);

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

const int N = 2000000 + 7;

int h[N], h2[N], h3[N];
int pw[N];

int geth(int l,int r){

    if(l==0)
        return h[r];
    else return h[r]-h[l-1]*pw[r-l+1];

}

int geth2(int l,int r){

    if(l==0)
        return h2[r];
    else return h2[r]-h2[l-1]*pw[r-l+1];

}

main(){
	
	NFS	
	
	string s1, s2, t;
	cin >> s1 >> s2 >> t;
	
	pw[0] = 1;
	h[0] = (s1[0] - 'a' + 1);
	h2[0] = (s2[0] - 'a' + 1);
	h3[0] = (t[0] - 'a' + 1);
	
	int p = 31;
	for(int i = 1; i < sz(s1); i++){
		h[i] = h[i - 1] * p + (s1[i] - 'a' + 1);
		pw[i] = pw[i - 1] * p;
	}
	
	for(int i = 1; i < sz(s2); i++){
		h2[i] = h2[i - 1] * p + (s2[i] - 'a' + 1);
	}
	
	int hs = 0;
	for(int i = 1; i < sz(t); i++){
		h3[i] = h3[i - 1] * p + (t[i] - 'a' + 1);
	}
	
	int ans = 0;
	for(int i = 0; i < sz(s1); i++){
		if(i + sz(t) > sz(s1)) break;
		if(geth(i, i + sz(t) - 1) == geth2(i, i + sz(t) - 1) && geth(i, i + sz(t) - 1) == h3[sz(t) - 1]) ans++;
	}
	
	cout << ans;
	
	ioi
}
