i64 gcd(i64 u, i64 v) {
  i64 t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; /* abs(u) */
}

i64 phi(i64 n){
	i64 ans = n;
	for(i64 i = 2; i * i <= n; ++i){
		if(n%i == 0)
			ans-=ans/i;
		while(n%i == 0)
			n/=i;
	}
	if(n > 1)
		ans-=ans/n;
	return ans;
}

//b^e%m
i64 powmod(i64 b, i64 e, i64 m){
	b%=m;
	i64 re = 1LL;
	while(e){
		if(e&1)
			re = (re*b)%m;
		b = (b*b)%m;
		e>>=1;
	}
	return re;
}

//Binomial coefficient
i64 k[1010101];
void precbin(){
	k[0] = 1;
	for(i64 i = 1; i <= 1000000; ++i){
		k[i] = (k[i-1]*i)%defmod;
	}
}
i64 ncr(i64 a, i64 b){
	i64 y = k[a];
	i64 al = (k[b]*(k[a-b]))%defmod;
	return (y*powmod(al, defmod-2, defmod))%defmod;
}
