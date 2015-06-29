#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

char* eratosthenes(int n)
{
  char* sieve = calloc(n+1,sizeof(char));
  sieve[0] = 1; sieve[1] = 1;
  int m = (int) sqrt((double) n);

  for(int i = 0; i <= m; i++) {
    if(!sieve[i]) {
      for (int j = i*i; j <= n; j += i)
        sieve[j] = 1;
    }
  }
  return sieve;
}

int main() {
  char* lol = eratosthenes(1000000020);

    int loll;
    cin >> loll;
    if(!lol[1000000007])
    cout << "ebin" << endl;
    else
        cout << "eibin" << endl;
}
