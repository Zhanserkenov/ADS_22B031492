//1352
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

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

Node* a[N];
int depth[N], cnt[N];

void insert(Node* root, int val, int pos){
	if(pos == 0){
		root->left = new Node(val);
		a[val] = root->left;
		depth[val] = depth[root->data] + 1;
		cnt[depth[val]]++;
	}
	else{ 
		root->right = new Node(val);
		a[val] = root->right;
		depth[val] = depth[root->data] + 1;
		cnt[depth[val]]++;
	}
}

int main(){
	
	NFS	
	
	int n;
	cin >> n;

	Node* root = new Node(1);
	a[1] = root;
	depth[1] = 1;
	cnt[1] = 1;
	for(int i = 1; i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		
		insert(a[x], y, z);
	}
	
	int mx = -inf;
	for(int i = 1; i <= 10000; i++){
		mx = max(mx, cnt[i]);
	}
	
	cout << mx << '\n';
	
	ioi
}
