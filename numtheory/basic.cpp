i64 gcd(i64 u, i64 v) {
  i64 t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; /* abs(u) */
}
