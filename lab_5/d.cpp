//514
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

int main(){
	
	NFS	
	
	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		pq.push(x);
	}
	
	int ans = 0, save = -1;
	while(1){
		if(pq.top() >= m){
			cout << ans;
			ioi
		}
		if(sz(pq) <= 1 && save == -1 || sz(pq) <= 1) break;
		if(save != -1){
			pq.push(save + pq.top() * 2);
			pq.pop();
			save = -1;
			continue;
		}
		if(pq.top() < m){
			save = pq.top();
			pq.pop();
			ans++;
		}
	}
	
	cout << -1;
	
	ioi
}
