#include <iostream>
#include <vector>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;

//This file contains implementations of rmq in different time complexities
//first off O(nlogn) build time and memory, O(1) query

struct rmq1{
	int n, k;
	vector<vector<i64>> m, m2;

	void init(vector<i64> a){
		n = a.size();
		for(int i = 0; i < 30; ++i){
			if(((1<<i) <= n))
				k = i;
		}
		m = vector<vector<i64>>(k+1, vector<i64>(n, 0));
		m2 = vector<vector<i64>>(k+1, vector<i64>(n, 0));
		for(int i = 0; i < n; ++i){
			m[0][i] = a[i];
			m2[0][i] = a[i];
		}
		for(int j = 0; j < k; ++j){
			for(int i = 0; i < n; ++i){
				m[j+1][i] = min(m[j][i], m[j][min(n-1, i+(1<<j))]);
				m2[j+1][i] = min(m2[j][i], m2[j][max(0, i-(1<<j))]);
			}
		}
	}

	i64 query(int a, int b){
		int bi = 0;
		while(a+(1<<(bi+1)) <= b)
			++bi;
		return min(m[bi][a], m2[bi][b]);
	}
};


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int n = 14;
	vector<i64> lul;
	for(int i = 0; i < n; ++i){
		lul.push_back(rand()%20);
		cout << lul.back() << " ";
	}
	cout << endl;
	rmq1 rmq;
	rmq.init(lul);
	for(int i = 0; i < 20; ++i){
		int a = rand()%n, b = rand()%n;
		if(a > b)
			swap(a, b);
		for(int j = a; j <= b; ++j)
			cout << lul[j] << " ";
		cout << " pienin " << rmq.query(a, b) << endl;
	}

	
	return 0;
}