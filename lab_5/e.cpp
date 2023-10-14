//521
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
	
	int q, k;
	cin >> q >> k;

	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	while(q--){
		string 	s;
		cin >> s;
		
		if(s[0] == 'p'){
			cout << sum << '\n';
		}
		else{
			int val;
			cin >> val;
			
			if(sz(pq) < k){
				pq.push(val);
				sum += val;
			}
			else if(pq.top() < val){
				sum -= pq.top();
				sum += val;
				pq.pop();
				pq.push(val);
			}
		}
	}
	
	ioi
}
