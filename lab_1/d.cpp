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

const int N = 26 + 7;

int main(){
	
	NFS
	
	string s;
	cin >> s;
	stack<int> st;
	
	for(int i = 0; i < sz(s); i++){
		if(st.empty()){
			st.push(s[i]);
			continue;
		}
		if(st.top() == s[i]){
			st.pop();
		}
		else{
			st.push(s[i]);
		}
	}
	
	if(!st.empty()) cout << "NO";
	else cout << "YES";
	
	ioi
}
