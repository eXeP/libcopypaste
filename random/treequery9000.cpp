#include <bits/stdc++.h>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define ld long double
#define defmod 1000000007

#define mati64(a,b) vector<vector<i64>>(a, vector<i64>(b, 0));
using namespace std;
const int p = 1<<21;
int a[p];
int n, q;

struct node{
	node* l = nullptr;
	node* r = nullptr;
	int sisu = 0, su = 0;
};

int sum(node* t){
	if(t == nullptr)
		return 0;
	return t->su;
}
node* cp(node* lol){
	if(lol == nullptr){
		return new node();
	}
	node* nn = new node();
	nn->l = lol->l;
	nn->r = lol->r;
	nn->su = lol->su;
	nn->sisu = lol->sisu;
	return nn;
}
vector<int> v[505050];

node* add(node* cur, int a, int b, int l, int r, int v){
	//cout << a << "-" << b << " mid "<< (a+b)/2 << " " << l<< "-" << r << endl;
	//int lol; cin >> lol;
	if(a >= r || b <= l){
		//cout << "v1" << endl;
		return cur;
	}
	else if(a >= l && b <= r){
		//cout << "v2" << endl;
		cur = cp(cur);
		cur->sisu+=v;
		cur->su+=(b-a)*v;
		return cur;
	}

	//cout << "v3" << endl;
	int m = (a+b)/2;
	cur = cp(cur);
	cur->l = add(cur->l, a, m, l, r, v);
	cur->r = add(cur->r, m, b, l, r, v);
	cur->su = sum(cur->l)+sum(cur->r)+(b-a)*cur->sisu;
	return cur;
}

node* r[505050];
int dfspos[505050], d[505050];
vector<pii> dfs, puu(2*p, {99999999, 0});
int pa[505050];
pii pmin(pii a, pii b){
	if(a.first < b.first)
		return a;
	return b;
}
void qaq(int cur, int par){
	dfspos[cur] = dfs.size();
	dfs.push_back({d[cur], cur});
	pa[cur] = par;
	for(auto f: v[cur]){
		if(f == par)
			continue;
		r[f] = add(r[cur], 0, p, a[f], a[f]+1, 1);
		d[f] = d[cur]+1;
		qaq(f, cur);
		dfs.push_back({d[cur], cur});
	}
}

pii lca(int i, int a, int b, int l, int r){
	if(a >= r || b <= l)
		return {99999999, 0};
	else if(a >= l && b <= r){
		return puu[i];
	}
	int m = (a+b)/2;
	return pmin(lca(i*2, a, m, l, r), lca(i*2+1, m, b, l, r));
}

node* gl(node* t){
	if(t == nullptr)
		return nullptr;
	return t->l;
}
node* gr(node* t){
	if(t == nullptr)
		return nullptr;
	return t->r;
}
int ks(node* lcy, node* lc, node* a, node* b, int l, int r, int k, int cs){

	int ls = sum(gl(a))+sum(gl(b))-sum(gl(lc))-sum(gl(lcy));
	//cout << l << "-" << r << " " << ls+cs << endl;
	int m = (l+r)/2;
	if(r == l+1)
		return l;
	if(ls+cs < k)
		return ks(gr(lcy), gr(lc), gr(a), gr(b), m, r, k, cs+ls);
	else
		return ks(gl(lcy), gl(lc), gl(a), gl(b), l, m, k, cs);

}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
  cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 0; i < n-1; ++i){
		int a, b, c; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	r[0] = nullptr;
	r[1] = add(nullptr, 0, p, a[1], a[1]+1, 1);
	qaq(1, 0);
	//cout << "taalla" << endl;
	for(int i = 0; i < dfs.size(); ++i){
		puu[i+p] = dfs[i];
		//cout << i+p << " vs " << puu.size() << endl;
	}
	for(int i = p-1; i >= 0; --i)
		puu[i] = pmin(puu[i*2], puu[i*2+1]);
	//cout << "taalla2" << endl;
	while(q--){
		int a, b, c; cin >> a >> b >> c;
		int lc = lca(1, 0, p, min(dfspos[a], dfspos[b]), max(dfspos[a], dfspos[b])+1).second;
		cout << ks(r[pa[lc]] ,r[lc], r[a], r[b], 0, p, c, 0) << endl;

	}
	return 0;
}