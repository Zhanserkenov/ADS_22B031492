//377 run ID
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

const int N = 1e5 + 7;

int a[N];

int main(){
	
	NFS
	
	int n;
	cin >> n;
	
	stack<int> s;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		int ans = -1;
		while(!s.empty()){
			if(s.top() > x){
				s.pop();
			}
			else{
				ans = s.top();
				break;
			}
		}
		s.push(x);
		cout << ans << ' ';
	}
	
	ioi
}
