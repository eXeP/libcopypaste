
bool sieve[1010101] = {0};
void eratosthenes(int n)
{
  
  sieve[0] = 1; sieve[1] = 1;
  int m = (int) sqrt((double) n);

  for(int i = 0; i <= m; i++) {
    if(!sieve[i]) {
      for (int j = i*i; j <= n; j += i)
        sieve[j] = 1;
    }
  }
  
}


