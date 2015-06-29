#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;

ll
gcd(ll u, ll v) {
  ll t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; /* abs(u) */
}

int main(){

	return 0;
}