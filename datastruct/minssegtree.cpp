
struct mintree{
	vector<i64> p;
	vector<i64> ad;
	i64 n = 1;
	
	void initfrom(vector<i64> a){
		while(n < a.size())
			n*=2;
		
		p = vector<i64>(2*n, 999999999999LL);
		ad = vector<i64>(2*n, 0);
		for(int i = 0; i < a.size(); i++)
			p[i+n] = a[i];
		for(int i = n-1; i >= 0; i--)
			p[i] = min(p[i*2], p[i*2+1]);

	}

	void init(int nn){
		while(n < nn)
			n*=2;
		p = vector<i64>(2*n, 0);
		ad = vector<i64>(2*n, 0);
	}

	void add2(int idx, int a, int b, int l, int r, i64 x){
		if(a >= r || b <= l)
			return;
		else if(a >= l && b <= r){
			ad[idx]+=x;
			p[idx]+=x;
		}
		else{
			int m = (a+b)/2;
			add2(idx*2, a, m, l, r, x);
			add2(idx*2+1, m, b, l, r, x);
			p[idx] = min(p[idx*2], p[idx*2+1])+ad[idx];
		}
	}
	//closed range -> closed-open
	void add(int l, int r, i64 x){
		add2(1, 0, n, l, r+1, x);
	}
	i64 querysum2(int idx, int a, int b, int l, int r){
		if(a >= r || b <= l)
			return 99999999999999LL;
		else if(a >= l && b <= r){
			return p[idx];
		}
		else{
			int m = (a+b)/2;
			return min(querysum2(idx*2, a, m, l, r), querysum2(idx*2+1, m, b, l, r))+ad[idx];
		}
	}
	//closed range -> closed-open
	i64 querysum(int l, int r){
		return querysum2(1, 0, n, l, r+1);
	}

};
