//426 run ID
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

const int N = 10300;

bool used[N];
vector<int> ans;

void compute_primes(int n){
	for(int i = 2; i <= n; i++){
		used[i] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		if(used[i]){
			ans.pb(i);
		}
		for(int j = i; j <= n; j += i) used[j] = 0;
	}
}

int main(){
	
	NFS
	
	compute_primes(10000);
	
	int n;
	cin >> n;
	
	cout << ans[n - 1];

	ioi
}
