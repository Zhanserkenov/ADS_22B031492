//2013
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);
 
#define inf (ll)1e9+7
 
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

string calc(string s){
	int h = 0, pw = 1;
	for(int i = 0; i < sz(s); i++){
		h += (s[i] - 47) * pw;
		h %= inf;
		pw *= 11;
		pw %= inf;
	}
	return to_string(h);
}

set<string> hashes;
vector<pair<string, string>> v;

main(){
	
	NFS	
	
	int n;
	cin >> n;

	int tt = n * 2;
	while(tt--){
		string s;
		cin >> s;
		
		string h = calc(s);
		v.pb({h, s});
		hashes.insert(s);
	}
	
	int q = 0;
	for(int i = 0; i < sz(v); i++){
		set<string>::iterator it = hashes.find(v[i].F);
		if(it != hashes.end()){
			cout << "Hash of string \"" << v[i].S << "\" is " << v[i].F << "\n";
			q++;
			if(q == n) break;
		}
	}
	
	ioi
}
