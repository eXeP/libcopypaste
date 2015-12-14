struct segtree{
	vector<ll> p;
	vector<ll> ad;
	ll n = 1;
	
	void initfrom(vector<ll> a){
		while(n < a.size())
			n*=2;
		
		p = vector<ll>(2*n, 0);
		ad = vector<ll>(2*n, 0);
		for(int i = 0; i < a.size(); i++)
			p[i+n] = a[i];
		for(int i = n-1; i >= 0; i--)
			p[i] = p[i*2]+p[i*2+1];

	}

	void init(int nn){
		while(n < nn)
			n*=2;
		p = vector<ll>(2*n, 0);
		ad = vector<ll>(2*n, 0);
	}

	void add2(int idx, int a, int b, int l, int r, ll x){
		if(a >= r || b <= l)
			return;
		else if(a >= l && b <= r){
			ad[idx]+=x;
			p[idx]+=(b-a)*x;
		}
		else{
			int m = (a+b)/2;
			add2(idx*2, a, m, l, r, x);
			add2(idx*2+1, m, b, l, r, x);
			p[idx] = p[idx*2]+p[idx*2+1]+(b-a)*ad[idx];
		}
	}
	//closed range -> closed-open
	void add(int l, int r, ll x){
		add2(1, 0, n, l, r+1, x);
	}
	ll querysum2(int idx, int a, int b, int l, int r, i64 ad2){
		if(a >= r || b <= l)
			return 0;
		else if(a >= l && b <= r){
			return p[idx]+(b-a)*ad2;
		}
		else{
			int m = (a+b)/2;
			return querysum2(idx*2, a, m, l, r, ad2+ad[idx])+querysum2(idx*2+1, m, b, l, r, ad2+ad[idx]);
		}
	}
	//closed range -> closed-open
	ll querysum(int l, int r){
		return querysum2(1, 0, n, l, r+1, 0);
	}

};
