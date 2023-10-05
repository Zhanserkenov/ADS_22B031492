//657 run ID
#include <iostream>

#define endl '\n'
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* newNode, int p) {
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
 
Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* current = head;
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return head;
}

void dfs(Node* node, int depth){
	if(depth == 0)return;
	dfs(node->next,depth-1);
	node->next->val=node->val;
}
 
Node* replace(Node* head, int x1, int x2) {
    if (!head || x1 == x2) {
        return head; // No need to make any changes
    }

    //Node dummy(0);
    //dummy.next = head;
    Node* prev_x1 = head;
    Node* prev_x2 = head;
    //Node* current = head;

    // Traverse the list to find the x1-th and x2-th nodes
    for (int i = 0; i < x1; ++i) {
        prev_x1 = prev_x1->next;
    }
    
    for (int i = 0; i < x2; ++i) {
        prev_x2 = prev_x2->next;
    }
    
    if(x1 < x2) {
    	int val=prev_x1->val;
    	while (x1 != x2) {
    		prev_x1->val = prev_x1->next->val;
    		prev_x1 = prev_x1->next;
    		x1++;
    	}
    	prev_x1->val = val;
    }
    else {
    	int val=prev_x1->val;
    	Node* temp = prev_x2;
    	dfs(temp,x1-x2);
    	prev_x2->val=val;
    }

    return head;
}
 
void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << ' ';
        current = current->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
 
// Function to cyclically move the linked list to the right
Node* cyclicMoveRight(Node* head, int k) {
    if (!head || k <= 0) {
        return head;
    }

    int length = 1;
    Node* tail = head;

    // Calculate the length of the linked list and find the tail node
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length; // Handle cases where k is larger than the length

    if (k == 0) {
        return head; // No need to move
    }

    Node* newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

// Function to cyclically move the linked list to the left
Node* cyclicMoveLeft(Node* head, int k) {
    if (!head || k <= 0) {
        return head;
    }

    int length = 1;
    Node* tail = head;

    // Calculate the length of the linked list and find the tail node
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length; // Handle cases where k is larger than the length

    if (k == 0) {
        return head; // No need to move
    }

    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}
 
int n;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
            n++;
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
            n--;
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            x%=n;
            head=cyclicMoveLeft(head, x);
            //while(x--)head = replace(head, 0, n-1);
        }else if (command == 7){
            int x; cin >> x;
            x%=n;
            head=cyclicMoveRight(head, x);
            //while(x--)head = replace(head, n-1, 0);
        }   
    }
    return 0;
}
