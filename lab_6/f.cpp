//526
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

node a[N];

bool ch(node x, node y, bool type){
	if(type == 0){
		if(x.avgGPA == y.avgGPA){
			if(x.lastName == y.lastName){
				return x.firstName <= y.firstName;
			}
			return x.lastName <= y.lastName;
		}
		return x.avgGPA <= y.avgGPA;
	}
	else{
		if(x.avgGPA == y.avgGPA){
			if(x.lastName == y.lastName){
				return x.firstName > y.firstName;
			}
			return x.lastName > y.lastName;
		}
		return x.avgGPA > y.avgGPA;
	}
}

int partition(node *a, int n){
	node pivot;
	pivot.lastName = a[0].lastName;
	pivot.firstName = a[0].firstName;
	pivot.avgGPA = a[0].avgGPA;
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
		
		a[i - 1].lastName = surname;
		a[i - 1].firstName = name;
		a[i - 1].avgGPA = avg;
	}
	
	quick_sort(a, n);
	
	for(int i = 0; i < n; i++){
		cout << a[i].lastName << ' ' << a[i].firstName << ' ' << fixed << setprecision(3) << a[i].avgGPA << '\n';
	}
	
	ioi
}
