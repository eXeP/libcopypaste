int e[1010101];
int smax = 1000000;
void sieve(){
	for(int i = 2; i < smax; i+=2)
		e[i] = 2;
	for(i64 i = 3; i <= smax; i+=2){
		if(!e[i]){
			e[i] = i;
			for(i64 j = i; j*i <= smax; j+=2){
				if(!e[j*i])
					e[j*i] = i;
			}
		}
	}
}

