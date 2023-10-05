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

const int N = 1e5 + 7;

int pref[N];

main(){
	
	NFS	
	
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		pref[i] = pref[i - 1] + x;
	}
	
	int ans = inf;
	for(int i = 1; i <= n; i++){
		int l =  i, r = n;
		while(l <= r){
			int md = (l + r) / 2;
			
			if(pref[md] - pref[i - 1] >= k){
				r = md - 1;
			}
			else{
				l = md + 1;
			}
		}
		if(r + 1 > n) continue;
		ans = min(ans, (r + 1) - i + 1);
	}
	
	cout << ans;
	
	ioi
}
