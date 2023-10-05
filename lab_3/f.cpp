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

const int N = 1e6 + 7;

int n;
int a[N];
int pref[N];

int main(){
	
	NFS	
	
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + a[i];
	}
	
	int p;
	cin >> p;
	
	while(p--){
		int x;
		cin >> x;
		
		int l = 1, r = n;
		while(l <= r){
			int md = (l + r) / 2;
			
			if(x >= a[md]){
				l = md + 1;
			}
			else{
				r = md - 1;
			}
		}
		cout << (int)(l - 1) << ' ' << pref[l - 1] << '\n';
	}
	
	ioi
}
