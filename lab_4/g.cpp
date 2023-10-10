//1409
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

#define int ll
 
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

int ans;

int dfs(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int left_depth = dfs(root->left);
    int right_depth = dfs(root->right);

    ans = max(ans, left_depth + right_depth + 1);
    
    return max(left_depth, right_depth) + 1;
}

main(){
	
	NFS	
	
	int n;
	cin >> n;
	
	Node* root = nullptr;
	map<int, bool> was;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		if(!was[x]){
			was[x] = 1;
			root = insert(root, x);
		}
	}
	
	int q = dfs(root);
	
	cout << ans;
	
	ioi
}
