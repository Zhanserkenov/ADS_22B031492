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

string last;
vector<string> v;

struct Node{
	string data;
	Node* next;
};

void insert(Node*& head, string data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void ans(Node* head){
	Node* current = head;
	while(current != nullptr){
		if(current->data != last){
			last = current->data;
			v.pb(current->data);
		}
		current = current->next;
	}
}

Node* a = nullptr;

int main(){
	
	NFS
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		string x;
		cin >> x;
		
		insert(a, x);
	}
	
	ans(a);
	
	cout << "All in all: " << sz(v) << '\n';
	cout << "Students:" << '\n';
	for(int i = 0; i < sz(v); i++){
		cout << v[i] << '\n';
	} 
	
	ioi
}
