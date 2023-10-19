//482
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

const int N = 1e5 + 7;

char a[N];

bool ch(char x){
	return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int partition(char *a, int n){
	int pivot = a[0];
	int left = 1, right = n - 1;
	
	while(1){
		while(left < n){
			if(!ch(pivot) && ch(a[left])){
				left++;
				continue;
			}
			if(a[left] <= pivot && ch(pivot) == ch(a[left])){
				left++;
				continue;
			}
			break;
		}
		while(1){
			if(ch(pivot) && !ch(a[right])){
				right--;
				continue;
			}
			if(a[right] > pivot && ch(a[right]) == ch(pivot)){
				right--;
				continue;
			}
			break;
		}
		
		//cerr << left << ' ' << right << '\n';
		
		if(left < right) swap(a[left], a[right]);
		else break;
	}
	
	swap(a[0], a[right]);
	return right;
}

void quick_sort(char *a, int n){
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
		cin >> a[i];
	}
	
	quick_sort(a, n);
	
	for(int i = 0; i < n; i++) cout << a[i];
	
	ioi
}
