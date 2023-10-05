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

struct node{
	int data;
	node* next;	
};

void insert(node*& head, int data){
	node* newnode = new node;
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}

void print(node* head){
	node* current = head;
	vector<int> v;
	while(current != nullptr){
		v.pb(current->data);
		current = current->next;
	}
	for(int i = sz(v) - 1; i >= 0; i--) cout << v[i] << ' ';
}

node* a = nullptr;

int main(){
	
	NFS
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		if(i % 2 != 0) insert(a, x);
	}
	
	print(a);
	
	ioi
}
