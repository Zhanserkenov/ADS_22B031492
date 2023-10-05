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

const int N = 2e5 + 7;

bool used[N];

int main(){
	
	NFS
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	stack<char> st;
	
	while(1){
		bool ok = 0, ok1 = 0;
		for(int i = 0; i < sz(s); i++){
			if(used[i] == 0){
				if(s[i] != 'K') ok = 1;
				if(s[i] != 'S') ok1 = 1;
			}
		}
		
		if(ok == 0){
			cout << "KATSURAGI";
			ioi
		}
		
		if(ok1 == 0){
			cout << "SAKAYANAGI";
			ioi
		}
		
		for(int i = 0; i < sz(s); i++){
			if(st.empty() && used[i] == 0){
				st.push(s[i]);
			}
			else if(used[i] == 0){
				if(st.top() != s[i]){
					st.pop();
					used[i] = 1;
				}
				else{
					st.push(s[i]);
				}
			}
		}
	}

	ioi
}
