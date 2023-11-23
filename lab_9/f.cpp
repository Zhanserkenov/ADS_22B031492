//1977
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

vector<int> ans;

void computeLPSArray(string pat, int M, int* lps){
	int len = 0;

	lps[0] = 0; 

	int i = 1;
	while(i < M){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0) {
				len = lps[len - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pat, string txt){
	int M = sz(pat);
	int N = sz(txt);

	int lps[M];

	computeLPSArray(pat, M, lps);
	
	int i = 0;
	int j = 0;
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			ans.pb(i - j + 1);
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

int main(){

	NFS
	
	string txt, pat;
	cin >> txt >> pat;
	KMPSearch(pat, txt);
	
	cout << sz(ans) << '\n';
	for(int i = 0; i < sz(ans); i++){
		cout << ans[i] << ' ';
	}
	
	ioi
}
