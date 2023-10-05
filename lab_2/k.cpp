//988 run ID
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

const int N = 30;

pair<int, int> cnt[N];

void solve(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < 26; i++) cnt[i].F = 0, cnt[i].S = 0;
	
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		
		cnt[c - 'a'].F++;
		if(cnt[c - 'a'].F == 1) cnt[c - 'a'].S = i;
		
		int id = inf;
		char ans = '#';
		for(int j = 0; j < 26; j++){
			if(cnt[j].F == 1){
				if(id > cnt[j].S){
					ans = j + 'a';
					id = cnt[j].S;
				}
			}
		}
		
		if(ans == '#'){
			cout << -1 << ' ';
			continue;
		}
		
		cout << ans << ' ';
	}
	
	cout << '\n';

}

int main(){
	
	NFS	
		
	int tt;
	cin >> tt;
	
	while(tt--){
		solve();
	}
	
	ioi
}
