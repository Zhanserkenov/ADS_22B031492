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

const int N = 1000 + 7;

int cnt[N];
bool used[N];
int mx;

struct node{
	int data;
	node* next;	
};

void insert(node*& head, int data){
	node* newnode = new node;
	newnode->data = data;
	cnt[newnode->data]++;
	mx = max(mx, cnt[newnode->data]);
	newnode->next = head;
	head = newnode;
}

void print(node* head){
	node* current = head;
	vector<int> v;
	while(current != nullptr){
		if(mx == cnt[current->data] && used[current->data] == 0){
			v.pb(current->data);
			used[current->data] = 1;
		}
		current = current->next;
	}
	sort(all(v));
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
		
		insert(a, x);
	}

	print(a);
	
	ioi
}
