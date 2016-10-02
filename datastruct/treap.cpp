#include <bits/stdc++.h>

#define u64 unsigned long long
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int prior, size;
	int value;
  u64 su = 0;
	u64 val = 0;
  u64 lazy = 0;
  bool rev = false;
	Node(int v) {
		left = nullptr;
		right = nullptr;
		size = 1;
		prior = rand();
		value = v;
	}
};

// Returns the size of the subtree t
int cnt(Node* t) {
	if (t == nullptr) return 0;
	return t->size;
}

u64 sum(Node* t){
  if(t == nullptr) return 0;
  return t->su;
}
// Updates the size of the subtree t
void upd(Node* t) {
	if (t == nullptr) return;
	t->size = cnt(t->left) + 1 + cnt(t->right);
  t->su = sum(t->left) + t->val + t->lazy*t->size + sum(t->right);
}

// Put lazy updates here
void push(Node* t) {
	if (t == nullptr) return;
	// Do lazy update
  if(t->rev){
    swap(t->left, t->right);
    if(t->left)
      t->left->rev ^= 1;
    if(t->right)
      t->right->rev ^= 1;
    t->rev = 0;
  }
  if(t->lazy){
    if(t->left)
      t->left->lazy += t->lazy;
    if(t->right)
      t->right->lazy += t->lazy;
    t->val+=t->lazy;
    t->lazy = 0;
  }
	upd(t->left);
	upd(t->right);
	upd(t);
}

// Merges trees left and right into tree t
void merge(Node*& t, Node* left, Node* right) {
	push(left);
	push(right);
	if (left == nullptr) t = right;
	else if(right == nullptr) t = left;
	else {
		if (left->prior > right->prior) {
			merge(left->right, left->right, right);
			t = left;
		}
		else {
			merge(right->left, left, right->left);
			t = right;
		}
	}
	upd(t);
}

// Splits tree t into trees left and right
// Size of tree left will be k
void split(Node* t, Node*& left, Node*& right, int k) {
	if (t == nullptr) {
		left = nullptr;
		right = nullptr;
		return;
	}
	else {
		push(t);
		if (cnt(t->left) >= k) {
			split(t->left, left, t->left, k);
			right = t;
		}
		else {
			split(t->right, t->right, right, k - cnt(t->left) - 1);
			left = t;
		}
	}
	upd(t);
}
void pr(Node* t){
	if(t == nullptr)
		return;
	pr(t->left);
	cout << t->value << " ";
	pr(t->right);
}
Node* rip;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
  int n, q; cin >> n >> q;
  rip = new Node(1);
  for(int i = 2; i <= n; ++i){
    merge(rip, rip, new Node(i));
  }
  while(q--){
		
    char type; cin >> type;
    if(type == 'S'){
      int a, b; cin >> a >> b;
      Node* t1 = nullptr;
      Node* t2 = nullptr;
      Node* t3 = nullptr;
      split(rip, t2, t3, b);
      split(t2, t1, t2, a-1);

      cout << sum(t2) << endl;
      merge(rip, t1, t2);
      merge(rip, rip, t3);
    }
    else if(type == 'R'){
      int a, b; cin >> a >> b;
      Node* t1 = nullptr;
      Node* t2 = nullptr;
      Node* t3 = nullptr;
      split(rip, t2, t3, b);
      split(t2, t1, t2, a-1);
      t2->rev ^= 1;
      merge(rip, t1, t2);
      merge(rip, rip, t3);
    }
    else if(type == 'A'){
      int a, b; u64 d; cin >> a >> b >> d;
      Node* t1 = nullptr;
      Node* t2 = nullptr;
      Node* t3 = nullptr;
      split(rip, t2, t3, b);
      split(t2, t1, t2, a-1);
      t2->lazy += d;
      merge(rip, t1, t2);
      merge(rip, rip, t3);
    }
  }
  return 0;
}