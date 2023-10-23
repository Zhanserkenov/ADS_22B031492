//230
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

void merge(vector<string> &a, vector<string> &b, vector<string> &c){
	int i = 0, j = 0;
	
	while(i < sz(a) && j < sz(b)){
		if(sz(a[i]) <= sz(b[j])){
			c.pb(a[i]);
			i++;
		}
		else{
			c.pb(b[j]);
			j++;
		}
	}
	
	while(i < sz(a)){
		c.pb(a[i]);
		i++;
	}
	
	while(j < sz(b)){
		c.pb(b[j]);
		j++;
	}
}

void merge_sort(vector<string> &v){
	if(sz(v) <= 1) return;
	
	int md = sz(v) / 2;
	vector<string> left(v.begin(), v.begin() + md);
	vector<string> right(v.begin() + md, v.end());
	
	merge_sort(left);
	merge_sort(right);
	
	v.clear();
	merge(left, right, v);
}

int main(){
	
	NFS	
	
	int tt;
	cin >> tt;

	cin.ignore();
	while(tt--){
		string s;
		getline(cin, s);
		
		string t = "";
		vector<string> v;
		for(int i = 0; i < sz(s); i++){
			if(s[i] >= 'a' && s[i] <= 'z') t += s[i];
			else{
				v.pb(t);
				t = "";
			}
		}
		if(sz(t) > 0) v.pb(t);
		
		merge_sort(v);
		
		for(int i = 0; i < sz(v); i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	
	ioi
}
