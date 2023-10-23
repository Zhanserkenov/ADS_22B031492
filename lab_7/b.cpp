//231
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

vector<int> v;

void merge(vector<int> &a, vector<int> &b, vector<int> &c){
	int i = 0, j = 0;
	
	while(i < sz(a) && j < sz(b)){
		if(a[i] <= b[j]){
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

void merge_sort(vector<int> &v){
	if(sz(v) <= 1) return;
	
	int md = sz(v) / 2;
	vector<int> left(v.begin(), v.begin() + md);
	vector<int> right(v.begin() + md, v.end());
	
	merge_sort(left);
	merge_sort(right);
	
	v.clear();
	merge(left, right, v);
}

int main(){
	
	NFS	
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		v.pb(x);
	}
	
	int m;
	cin >> m;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		
		v.pb(x);
	}
	
	merge_sort(v);
	
	for(int i = 0; i < sz(v); i++) cout << v[i] << ' '; 
	
	ioi
}
