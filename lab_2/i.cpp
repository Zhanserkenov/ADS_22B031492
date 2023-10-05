#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* prev;
    Node* next;
    string val;

    Node(string _val) {
        prev = nullptr;
        next = nullptr;
        val = _val;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void add_back(string s) {
    Node* newNode = new Node(s);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void add_front(string s) {
    Node* newNode = new Node(s);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

bool empty() {
    return head == nullptr;
}

void erase_front() {
    if (empty()) {
        cout << "error" << endl;
        return;
    }
    cout << head->val << '\n';
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

void erase_back() {
    if (empty()) {
        cout << "error" << endl;
        return;
    }
    cout << head->val << '\n';
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

string front() {
    if (empty()) {
        return "error";
    }
    return head->val;
}

string back() {
    if (empty()) {
        return "error";
    }
    return tail->val;
}

void clear() {
    while (!empty()) {
        if(head == tail){
        	delete head;
        	head = tail = nullptr;	
        }
        else{
        	Node* temp = head;
        	head = head->next;
        	head->prev = nullptr;
        	delete temp;
        }
    }
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "add_front") {
            string t;
            cin >> t;
            add_front(t);
            cout << "ok" << endl;
        } else if (s == "add_back") {
            string t;
            cin >> t;
            add_back(t);
            cout << "ok" << endl;
        } else if (s == "erase_front") {
            erase_front();
        } else if (s == "erase_back") {
            erase_back();
        } else if (s == "front") {
            cout << front() << endl;
        } else if (s == "back") {
            cout << back() << endl;
        } else if (s == "clear") {
            clear();
            cout << "ok" << endl;
        } else if (s == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}
