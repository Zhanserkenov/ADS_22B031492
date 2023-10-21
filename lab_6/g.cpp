//687
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

map<string, string> parent, ans;

int main(){
	
	NFS	
	
	int tt;
	cin >> tt;
	
	int cnt = 0;
	while(tt--){
		string s, t;
		cin >> s >> t;
		
		if(parent.find(s) == parent.end()){
			ans[s] = t;
			parent[t] = s;
			cnt++;
		}
		else{
			ans[parent[s]] = t;
			parent[t] = parent[s];
		}
	}
	
	cout << cnt << '\n';
	map<string, string>::iterator it;
   	for(it = ans.begin(); it != ans.end(); ++it){
   		cout << it->F << ' ' << it->S << '\n';
   	}
	
	ioi
}
