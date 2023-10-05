//740 run ID
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

const int N = 1e5 + 7;

int n, f;
int a[N];

bool ch(int x){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += ceil((double)a[i] / x);
		
	}
	
	if(cnt <= f) return 1;
	return 0;
}

int main(){
	
	NFS	
	
	cin >> n >> f;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int l = 1, r = 1e9;
	while(l <= r){
		int md = (l + r) / 2;
		
		if(ch(md) == 1){
			r = md - 1;
		}
		else{
			l = md + 1;
		}
	}
	
	cout << r + 1;
	
	ioi
}
