struct MaxFlow{
	vector<vector<pair<pair<int, int64_t>, int>>> v;
	void addEdge(int a, int b, int64_t c){
		v[a].push_back({{b, c}, v[b].size()});
		v[b].push_back({{a, 0}, v[a].size()-1});
	}

	vector<int> d;
	vector<pair<int, int>> la;
	int64_t path(int cur, int goal, int64_t cc){
		queue<int> q;
		q.push(cur);
		int st = cur;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(cur == goal)
				break;
			d[cur] = cc;
			for(int i = 0; i < v[cur].size(); ++i){
				auto f = v[cur][i];
				if(d[f.first.first] != cc && f.first.second > 0){
					d[f.first.first] = cc;
					la[f.first.first] = {cur, i};
					q.push(f.first.first);
				}
			}
		}
		if(d[goal] != cc)
			return 0;
		int nn = goal;
		int64_t flo = 1L<<61;
		while(nn != st){
			flo = min(flo, v[la[nn].first][la[nn].second].first.second);
			nn = la[nn].first;
		}
		nn = goal;
		while(nn != st){
			v[la[nn].first][la[nn].second].first.second-=flo;
			v[nn][v[la[nn].first][la[nn].second].second].first.second+=flo;
			nn = la[nn].first;
		}
		return flo;
	}

	int64_t flow(int source, int sink){
		int64_t flow = 0;
		int cc = 0;
		while(true){
			++cc;
			int64_t ad = path(source, sink, cc);
			if(ad == 0)
				break;
			flow+=ad;
		}
		return flow;
	}
	MaxFlow(int n) : la(n+1), d(n+1), v(n+1){}
};
