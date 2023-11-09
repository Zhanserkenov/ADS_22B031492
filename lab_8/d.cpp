//2335
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

const int N = 1e6 + 7;
const int d = 31;

int search(const string& pat, const string& txt, int q = INT_MAX)
{
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
	int ans = 0;
    
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M)
                ans++;
        }

        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
    return ans;
}

main(){
	
	NFS	
	
	int n;
	while(cin >> n){
		if(n == 0) break;
		
		vector<string> v;
		while(n--){
			string s;
			cin >> s;
			
			v.pb(s);
		}
		
		string s;
		cin >> s;
		
		int mx = -inf;
		for(int i = 0; i < sz(v); i++){
			mx = max(mx, search(v[i], s));
		}
		
		cout << mx << '\n';
		for(int i = 0; i < sz(v); i++){
			if(mx == search(v[i], s)){
				cout << v[i] << '\n';
			}
		}
	}	
	
	ioi
}
