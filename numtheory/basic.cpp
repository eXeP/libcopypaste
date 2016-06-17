i64 gcd(i64 u, i64 v) {
  i64 t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; /* abs(u) */
}

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
