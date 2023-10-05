//742 run ID
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

const int N = 2e5 + 7;

int pref[N];

main(){
	
	NFS	
	
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		pref[i] = pref[i - 1] + x;
	}
	
	while(m--){
		int x;
		cin >> x;
		
		int l = 1, r = n;
		while(l <= r){
			int md = (l + r) / 2;
			if(pref[md] >= x){
				r = md - 1;
			}
			else{
				l = md + 1;
			}
		}
		cout << r + 1 << '\n';
	}
	
	ioi
}
