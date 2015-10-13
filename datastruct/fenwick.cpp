#include <bits/stdc++.h>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;

struct fenwick{
	vector<i64> p;
	int n;
	void init(int n2){
		n = n2;
		p = vector<i64>(n+1, 0);
	}

	void set(int idx, i64 x){
		idx++;
		while(idx <= n){
			p[idx]+=x;
			idx+=idx&(-idx);
		}
	}

	i64 query(int idx){
		idx++;
		i64 re = 0;
		while(idx > 0){
			re+=p[idx];
			idx-=idx&(-idx);
		}
		return re;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> lol;
	int n = 42;
	for(int i = 0; i < n; i++)
		lol.push_back(2);
	fenwick ft;
	ft.init(n);
	for(int i = 0; i < n; i++){
		ft.set(i, lol[i]);
	}
	cout << ft.query(40) << endl;

	return 0;
}