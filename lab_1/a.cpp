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

const int N = 1000 + 7;

bool used[N];

void solve(){
	
	int n;
	cin >> n;
	vector<int> ans(n,-1);

        queue<int> q;

        for(int i = 0; i<n ; i++){

            q.push(i);

        }

        for(int i = 1; i<=n ; i++){

            for(int j = 0; j< (i%q.size()) ; j++){

                q.push(q.front());

                q.pop();

            }

            ans[q.front()] = i;

            q.pop();

        }
	
        for(int i = 0; i < sz(ans); i++) cout << ans[i] << ' ';
        
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
