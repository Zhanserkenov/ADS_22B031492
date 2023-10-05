# include <iostream>
# include <algorithm>
# include <cassert>

#define inf (int)(1e9+7)

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
	
	int ans = -inf;
	Node* l = head;
	for(int i = 0; i < n; i++){
		int sum = 0, summax = -inf;
		Node* r = l;
		for(int j = i; j < n; j++){
			sum += r->val;
			summax = max(summax, sum);
			if(r->next != NULL) r = r->next;
		}
		ans = max(ans, summax);
		if(l->next != NULL) l = l->next;
	}
	
	return ans;

}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
