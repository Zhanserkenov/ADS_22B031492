//485
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
	
	int n;
	cin >> n;

	priority_queue<int> pq;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		pq.push(x);
	}
	
	int ok = 0, save = -1;
	while(1){
		if(sz(pq) <= 1 && ok == 0) break;
		if(ok == 0){
			save = pq.top();
			pq.pop();
			ok++;
			continue;
		}
		if(ok == 1){
			if(save != pq.top()){
				save = save - pq.top();
				pq.pop();
				pq.push(save);
			}
			else{
				pq.pop();
			}
			ok = 0;
		}
	}
	
	if(pq.empty()) cout << 0;
	else cout << pq.top();
	
	ioi
}
