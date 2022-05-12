class DisjoinSet{
	private:
		vector<int> p, rank;
	public:
		DisjoinSet(int n){
			rank.assign(n, 0);
			p.assign(n, 0);
			for (int i = 0; i < n; i++){
				p[i] = i;
			}
		}
		int find_set(int i){
			return (p[i]==i) ? i : (p[i] = find_set(p[i]));
		}
		bool is_same_set(int i, int j){
			return find_set(i) == find_set(j);
		}
		void union_set(int i, int j){
			if(!is_same_set(i, j)){
				int x = find_set(i), y = find_set(j);
				if(rank[x] > rank[y])
					p[y] = x;
				else{
					p[x] = y;
					if(rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
};


vector<pair<int, pair<int,int>>> adj;
int kruskal(int n){
	int cost = 0;
	DisjoinSet* DS = new DisjoinSet(n);
	sort(adj.begin(), adj.end());
	for (int i = 0; i < adj.size(); i++){
		auto edge = adj[i];
		if(! DS->is_same_set( edge.second.first, edge.second.second)){
			cost += edge.first;
			DS->union_set(edge.second.first, edge.second.second);
		}
	}
	return cost;
}


