//737 run ID
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

int n, k;
int a[N];

bool ch(int x){
	int cnt = k, sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
		if(sum > x){
			sum = a[i];
			cnt--;
		}
	}
	//cerr << "FOUND " << cnt << ' ' << sum << endl;
	if(sum != 0) cnt--;
	if(cnt < 0) return 0;
	return 1; 
} 

main(){
	
	NFS	
	
	int mx=0;
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	
	int l = mx, r = 1e15;
	while(l <= r){
		
		int md = (l + r) / 2;
		
		int x = ch(md);
		
		//cerr << x << ' ' << md << endl;
		
		if(x == 1){
			r = md - 1;
		}
		else{
			l = md + 1;
		}
	}
	
	cout << r + 1;
	
	ioi
 }
