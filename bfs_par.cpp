#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef vector<int> vi;
vector<vi> adj;
vector<bool> visited;
vector<int> par;
vector<int> dist;

int main(){
	int n,m;
	cin>>n>>m;
	visited.assign(n, false());
	par.assign(n, int());
	dist.assign(n, int());
	adj.assign(n, vi());
	int from, to;
	for (int i = 0; i < m; i++){
		cin>>from>>to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	cout<<endl;
	bfs(0);
	print_path(7);
	system("pause");
	return 0;
}

void bfs(int s){
	dist[s] = 0;
	par[s] = -1;
	visited[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
				if(!visited[v]){
				dist[v] = dist[u] + 1;
				par[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}
void print_path(int to){
	if(!visited[to])
		cout<<"there is no path to: "<<to<<endl;
	else{
		vector<int> path;
		for (int i = to; i != -1; i = par[i]){
			path.push_back(i);
		}
		reverse(path.begin(), path.end());
		cout<<"path: ";
		for (int i = 0; i < path.size(); i++)
			cout<<path[i]<<" ";
	}
}

