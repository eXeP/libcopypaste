#include <bits/stdc++.h>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;

struct stringhash{
	i64 A = 3371, B = 988943841;
	vector<i64> x, p;
	string s;
	void init(string ss){
		s = ss;
		x = vector<i64>(s.length(), 0);
		p = vector<i64>(s.length(), 0);
		x[0] = 1;
		p[0] = s[0];
		for(int i = 1; i < s.length(); i++){
			p[i] = (p[i-1]*A+s[i])%B;
			x[i] = (x[i-1]*A)%B;
		}
	}

	i64 gethash(int a, int b){
		i64 re = p[b];
		if(a > 0)
			re-=(p[a-1]*x[b-a+1])%B;
		re = (re%B+B)%B;
		return re;
	}
};
vector<string> lel;
stringhash hh[1000];
void comp(int l1, int r1, int l2, int r2){
	cout << lel[0].substr(l1, r1-l1+1) << " == " << lel[3].substr(l2, r2-l2+1) << endl;
	cout << hh[0].gethash(l1,r1) << " == " << hh[3].gethash(l2, r2) << endl;

}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	
	lel.push_back("lolok");
	lel.push_back("lelok");
	lel.push_back("wotokok");
	lel.push_back("loloklolok");
	
	for(int i = 0; i < lel.size(); i++){
		hh[i].init(lel[i]);
	}
	comp(0, 2, 5, 7);
	//cout << hh[0].gethash(0,2) << " == " << hh[3].gethash(5, 7) << endl;
	return 0;
}