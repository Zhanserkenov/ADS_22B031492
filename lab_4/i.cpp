//1416
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

Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int val) {
    if (root == nullptr) {
        return root;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int ans;
void dfs(Node* root, int val){
	if(root == nullptr){
		return;
	}
	if(val < root->data){
		dfs(root->left, val);
	}
	else{
		if(val == root->data) ans++;
		dfs(root->right, val);
	}
}

int main(){
	
	NFS	
	
	int q;
	cin >> q;

	Node* root = nullptr;
	while(q--){
		string s;
		int val;
		cin >> s >> val;
		
		if(s[0] == 'i'){
			root = insert(root, val);
		}
		if(s[0] == 'd'){
			root = deleteNode(root, val);
		}
		if(s[0] == 'c'){
			ans = 0;
			dfs(root, val);
			cout << ans << '\n';
		}
	}
	
	ioi
}
