//522
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

int a[N][N];
int b[N];

int partition(int *a, int n){
	int pivot = a[0];
	int left = 1, right = n - 1;
	
	while(1){
		while(left < n && a[left] <= pivot) left++;
		while(a[right] > pivot) right--;
		
		if(left < right) swap(a[left], a[right]);
		else break;
	}
	
	swap(a[0], a[right]);
	return right;
}

void quick_sort(int *a, int n){
	if(n <= 1) return;
	int p = partition(a, n);
	quick_sort(a, p);
	quick_sort(a + p + 1, n - p - 1);
}

int main(){
	
	NFS	
	
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			b[i - 1] = a[i][j];
		}
		quick_sort(b, n);
		
		for(int i = 1; i <= n; i++){
			a[i][j] = b[i - 1];
		}
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	ioi
}
