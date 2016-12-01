#include <iostream>
#include <math.h>
#include <algorithm>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;

__int128_t g(__int128_t x, __int128_t n){
	return (x*x+1)%n;
}

__int128_t abs(__int128_t n){
	if(n < 0)
		return -n;
	return n;
}

__int128_t gcd(__int128_t a, __int128_t b){
  __int128_t c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

i64 rho(i64 tn, i64 sx){
	__int128_t n = tn, x = sx, y = sx, fac = 1;
	while(fac == 1){
		x = g(x, n);
		y = g(g(y, n), n);
		fac = gcd(abs(x-y), n);
	}
	
	return (i64)fac;

}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	i64 n; cin >> n;
	
	i64 p = n, sx = 2;
	while(p == n || p == 1){
		p = rho(n, sx);
		sx++;
	}
	cout << min(p, n/p) << " " << max(p, n/p) << endl;
	return 0;
}
