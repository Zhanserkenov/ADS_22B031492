//461 run ID
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

const int N = 10300;

int main(){
	
	NFS
	
	char c;
	deque<int> d;
	
	while(cin >> c){
		if(c == '!') ioi
		if(c == '*'){
			if(d.empty()){
				cout << "error" << '\n';
				continue;
			}
			int sum = d.front() + d.back();
			d.ppb();
			if(!d.empty()) d.pop_front();
			cout << sum << '\n';
			continue;
		}
		int k;
		cin >> k;
		
		if(c == '+') d.push_front(k);
		else d.pb(k);
	}	

	ioi
}
