//349 run ID
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

int n;
vector<int> v;

struct Node{
	int data;
	Node* next;
};

void insert(Node*& head, int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void add(Node*& head, int data, int pos){
 	while(pos != n){
 		n--;
 		head = head->next;
 	}
 	Node* newNode = new Node;
 	newNode->data = head->data;
 	newNode->next = head->next;
 	head->data = data;
 	head->next = newNode;
}

void print(Node* head){
	Node* current = head;
	while(current != nullptr){
		v.pb(current->data);
		current = current->next;
	}
}

Node* a = nullptr;

int main(){
	
	NFS
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		
		insert(a, x);
	}
	n--;
	
	int data, pos;
	cin >> data >> pos;
	
	Node* b = a;
	if(pos != 0)
		add(a, data, pos - 1);
	a = b;
	
	print(a);
	
	reverse(all(v));
	for(int i = 0; i < sz(v); i++){
		if(pos == 0 && i == 0){
			cout << data << ' ';
		
		}
		cout << v[i] << ' ';
	}
	
	ioi
}
