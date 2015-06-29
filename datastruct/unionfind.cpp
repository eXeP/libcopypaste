
struct unionfind{
	vector<int> p, r, s;
	void ufinit(int n){
		p = vector<int>(n+1, 0);
		r = vector<int>(n+1, 0);
		s = vector<int>(n+1, 1);
		for(int i = 0; i <= n; i++){
			r[i] = i;
		}
	}

	int uffind(int x){
		if(p[x]!=x)
			p[x] = find(p[x]);
		return p[x];
	}

	void ufunion(int x, int y){
		int xr = uffind(x), yr = uffind(y);
		if(xr==yr)
			return;
		if(r[xr] < r[yr]){
			p[xr] = yr;
			s[yr]+=s[xr];
		}
		else if(r[xr] > r[yr]){
			p[yr] = xr;
			s[xr]+=s[yr];
		}
		else{
			p[yr] = xr;
			s[yr]+=s[xr];
			r[xr]++;
		}
	}
};