//490
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

main(){
	
	NFS	
	
	int n, x;
	cin >> n >> x;

	priority_queue<int> pq;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		
		pq.push(a);
	}
	
	int ans = 0;
	while(x--){
		ans += pq.top();
		pq.push(pq.top() - 1);
		pq.pop();
	}
	
	cout << ans;
	
	ioi
}
