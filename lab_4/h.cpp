//1414
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

const int N = 2e5 + 7;

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

Node* insert(Node* root, int val){
	if(root == nullptr){
		return new Node(val);
	}
	if(val < root->data){
		root->left = insert(root->left, val);
	}
	else{
		root->right = insert(root->right, val);
	}
	return root;
}

vector<int> v;
int sum = 0;
map<int, bool> was;

void dfs(Node* root){
	if(root == nullptr){
		return;
	}
	dfs(root->right);
	if(!was[root->data]){
		was[root->data] = 1;
		sum += root->data;
		v.pb(sum);
	}
	dfs(root->left);
	if(!was[root->data]){
		was[root->data] = 1;
		sum += root->data;
		v.pb(sum);
	}
}

main(){
	
	NFS	
	
	int n;
	cin >> n;
	
	Node* root = nullptr;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		root = insert(root, x);
	}
	
	dfs(root);
	
	for(int i = 0; i < sz(v); i++){
		cout << v[i] << ' ';
	}
	
	ioi
}
