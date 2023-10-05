//71 run ID
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

string a[N];
string ans[N];

int main(){
	
	NFS
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(i + k > n){
			ans[i] = a[(i + k) - n];
		}
		else{
			ans[i] = a[i + k];
		}
		cout << ans[i] << ' ';
	}
	
	ioi
}
