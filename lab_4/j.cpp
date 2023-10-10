//1422
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

vector<int> v;

struct Node {
    int val;
    Node* left;
    Node* right;
};
Node* sortedArrayToBST(vector<int>& nums)
{
    // if the array is empty return NULL
    if (nums.empty()) {
        return NULL;
    }
 
    int n = nums.size();
    int mid = n / 2;
    Node* root = new Node{ nums[mid], NULL, NULL };
    // initializing queue
    queue<pair<Node*, pair<int, int> > > q;
    // push the root and its indices to the queue
    q.push({ root, { 0, mid - 1 } });
    q.push({ root, { mid + 1, n - 1 } });
 
    while (!q.empty()) {
        // get the front element from the queue
        pair<Node*, pair<int, int> > curr = q.front();
        q.pop();
 
        // get the parent node and its indices
        Node* parent = curr.first;
        int left = curr.second.first;
        int right = curr.second.second;
 
        // if there are elements to process and parent node
        // is not NULL
        if (left <= right && parent != NULL) {
            int mid = (left + right) / 2;
            Node* child = new Node{ nums[mid], NULL, NULL };
 
            // set the child node as left or right child of
            // the parent node
            if (nums[mid] < parent->val) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
 
            // push the left and right child and their
            // indices to the queue
            q.push({ child, { left, mid - 1 } });
            q.push({ child, { mid + 1, right } });
        }
    }
 
    return root;
}

void printBST(Node* root){
    if (root == nullptr)
        return;
 
    cout << root->val << ' ';
    printBST(root->left);
    printBST(root->right);
}

int main(){
	
	NFS	
	
	int n;
	cin >> n;
	
	n = (1 << n) - 1;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		v.pb(x);
	}
	
	sort(all(v));
	
	Node* root = sortedArrayToBST(v);
	
	  printBST(root);
	
	ioi
}
