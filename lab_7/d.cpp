//233
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

double calc(string s){
	if(s == "A+") return 4.0;
	if(s == "A") return 3.75;
	if(s == "B+") return 3.50;
	if(s == "B") return 3.0;
	if(s == "C+") return 2.50;
	if(s == "C") return 2.0;
	if(s == "D+") return 1.50;
	if(s == "D") return 1.0;
	return 0.0; 
}

struct node{
	string firstName, lastName;
	double avgGPA;	
};

vector<node> a;

bool ch(node x, node y){
	if(x.avgGPA == y.avgGPA){
		if(x.lastName == y.lastName){
			return x.firstName <= y.firstName;
		}
		return x.lastName <= y.lastName;
	}
	return x.avgGPA <= y.avgGPA;
}

void merge(vector<node> &a, vector<node> &b, vector<node> &c){
	int i = 0, j = 0;
	
	while(i < sz(a) && j < sz(b)){
		if(ch(a[i], b[j])){
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

void merge_sort(vector<node> &v){
	if(sz(v) <= 1) return;
	
	int md = sz(v) / 2;
	vector<node> left(v.begin(), v.begin() + md);
	vector<node> right(v.begin() + md, v.end());
	
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
		string surname, name;
		cin >> surname >> name;
		
		int m;
		cin >> m;
		double avg = 0.0, sum = 0.0;
		while(m--){
			string score;
			cin >> score;
			
			int credit;
			cin >> credit;
			
			avg += (calc(score) * credit);
			sum += credit;
		}
		avg /= sum;
		
		a.pb({name, surname, avg});
	}
	
	merge_sort(a);
	
	for(int i = 0; i < sz(a); i++){
		cout << a[i].lastName << ' ' << a[i].firstName << ' ' << fixed << setprecision(3) << a[i].avgGPA << '\n';
	}
	
	ioi
}
