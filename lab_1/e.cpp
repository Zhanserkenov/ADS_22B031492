//415 run ID
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

int main(){
	
	NFS
	
	deque<int> boris, nursik;
	
	for(int i = 1; i <= 5; i++){
		int x;
		cin >> x;
		boris.pb(x);
	}
	
	for(int i = 1; i <= 5; i++){
		int x;
		cin >> x;
		nursik.pb(x);
	}
	
	int cnt = 0;
	while(!boris.empty() && !nursik.empty()){
		int x = boris.front(), y = nursik.front(); 
		cnt++;
		if(x == y){
			cout << "blin nichya";
			ioi
		}
		if(x > y){
			if(x == 9 && y == 0){
				boris.pop_front();
				nursik.pop_front();
				nursik.pb(x);
				nursik.pb(y);
				continue;
			}
			boris.pop_front();
			nursik.pop_front();
			boris.pb(x);
			boris.pb(y);
		}
		else{
			if(x == 0 && y == 9){
				boris.pop_front();
				nursik.pop_front();
				boris.pb(x);
				boris.pb(y);
				continue;
			}
			boris.pop_front();
			nursik.pop_front();
			nursik.pb(x);
			nursik.pb(y);
		}
	}
	
	if(boris.empty()){
		cout << "Nursik" << ' ' << cnt;
	}
	else{
		cout << "Boris" << ' ' << cnt;
	}
	
	ioi
}
