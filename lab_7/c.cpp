//232
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

map<int, int> mp;

int main(){
	
	NFS	
	
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(m);

	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < m; i++){
		cin >> b[i];
		mp[b[i]]++;
	}
	
	merge_sort(a);
	merge_sort(b);
	
	for(int i = 0; i < n; i++){
		if(mp[a[i]] != 0){
			cout << a[i] << ' ';
			mp[a[i]]--;
		}
	}
	
	ioi
}
