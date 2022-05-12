#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;
vector<vi> adj;
vector<bool> visited;

void dfs(int u){
	visited[u] = true;
	for(int i =0; i< adj[u].size()); i++){
		int v = adj[u][i];
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	
	visited.assign(n,false());
	adj.assign(n,vi());
	int from, to;
	
	for(int i =0;i<m;i++){
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	dfs(0);
}
