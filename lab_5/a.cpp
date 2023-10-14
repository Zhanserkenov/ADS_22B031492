//483
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
	
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		pq.push(x);
	}
	
	int sum = 0, ok = 0, ans = 0;
	while(!pq.empty()){
		sum += pq.top();
		pq.pop();
		ok++;
		if(ok == 2){
			ans += sum;
			pq.push(sum);
			sum = 0;
			ok = 0;
		}
	}
	
	cout << ans;
	
	ioi
}
