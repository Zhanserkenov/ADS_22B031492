#include <bits/stdc++.h>
 
#define ll long long
#define ld long double`
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

int main(){
	
	NFS
	
	string s, t;
	cin >> s >> t;
	
	int cnt = 0;
	string new_str = "";
	for(int i = sz(s) - 1; i >= 0; i--){
		if(s[i] == '#') cnt++;
		else{
			if(cnt != 0){
				cnt--;
				continue;
			}
			new_str += s[i];
		}
	}
	
	s = new_str;
	
	cnt = 0;
	new_str = "";
	for(int i = sz(t) - 1; i >= 0; i--){
		if(t[i] == '#') cnt++;
		else{
			if(cnt != 0){
				cnt--;
				continue;
			}
			new_str += t[i];
		}
	}
	
	t = new_str;
	
//	cout << s << ' ' << t << '\n';
	
	if(t == s){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	
	ioi
}
