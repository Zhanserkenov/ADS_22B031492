//688
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

char a[N];

int main(){
	
	NFS	
	
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	char c;
	cin >> c;
	for(int i = 1; i <= n; i++){
		if(c < a[i]){
			cout << a[i];
			ioi
		}
	}
	
	cout << a[1];
	
	ioi
}
