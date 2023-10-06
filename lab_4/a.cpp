//464 run ID
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

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* insert(TreeNode* root, int val){
	if(root == nullptr){
		return new TreeNode(val);
	}
	if(val < root->data){
		root->left = insert(root->left, val);
	}
	else{
		root->right = insert(root->right, val);
	}
	return root;
}

int main(){
	
	NFS	
	
	int n, m;
	cin >> n >> m;
	
	TreeNode* root = nullptr;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		root = insert(root, x);
	}
	
	while(m--){
		string s;
		cin >> s;
		
		bool ok = 0;
		TreeNode* cur = root;
		for(int i = 0; i < sz(s); i++){
			if(s[i] == 'L'){
				if(cur->left == nullptr){
					ok = 1;
					break;
				}
				cur = cur->left;
			}
			else{
				if(cur->right == nullptr){
					ok = 1;
					break;
				}
				cur = cur->right;
			}
		}
		if(ok) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	
	ioi
}
