//521
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

const int N = 1e3 + 7;

struct node{
	int day, month, year;
};

node a[N];

bool ch(node x, node y, bool type){
	if(type == 0){
		if(x.year == y.year){
			if(x.month == y.month){
				return x.day <= y.day;
			}
			return x.month <= y.month;
		}
		return x.year <= y.year;
	}
	else{
		if(x.year == y.year){
			if(x.month == y.month){
				return x.day > y.day;
			}
			return x.month > y.month;
		}
		return x.year > y.year;
	}
}

int partition(node *a, int n){
	node pivot;
	pivot.day = a[0].day;
	pivot.month = a[0].month;
	pivot.year = a[0].year;
	int left = 1, right = n - 1;
	
	while(1){
		while(left < n && ch(a[left], pivot, 0)) left++;
		while(ch(a[right], pivot, 1)) right--;
		
		if(left < right) swap(a[left], a[right]);
		else break;
	}
	
	swap(a[0], a[right]);
	return right;
}

void quick_sort(node *a, int n){
	if(n <= 1) return;
	int p = partition(a, n);
	quick_sort(a, p);
	quick_sort(a + p + 1, n - p - 1);
}

int main(){
	
	NFS	
	
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		int d = 0, m = 0, y = (int)((s[6] - '0') * 1000) + ((s[7] - '0') * 100) + ((s[8] - '0') * 10) + (s[9] - '0');
		
		if(s[0] != '0'){
			d += (int)s[0] - '0';
			d *= 10;
		}
		
		if(s[3] != '0'){
			m += (int)s[3] - '0';
			m *= 10;
		}
		
		d += (int)s[1] - '0';
		m += (int)s[4] - '0';
	
		a[i].day = d;
		a[i].month = m;
		a[i].year = y;
	}
	
	quick_sort(a, n);
	
	for(int i = 0; i < n; i++){
		if(a[i].day < 10) cout << 0;
		cout << a[i].day << '-';
		if(a[i].month < 10) cout << 0;
		cout << a[i].month << '-';
		
		cout << a[i].year << '\n';
	}
	
	ioi
}
