#include<iostream>
#include<queue>
using namespace std;
int adj[128][128];
int n,m;
bool visited[128];
void bfs(int i){
	visited[i] = true;
	queue<int> q;
	q.push(i);
	while (!q.empty()){
		int u = q.front(); q.pop();
		cout<<u<<" ";
		for (int v = 0; v < n; v++){
			if( !visited[v] && adj[u][v]){
			visited[v] = true;
			q.push(v);
			}
		}
	}
}


int main(){
	memset(adj, 0, sizeof(adj));
	memset(visited, false, sizeof(visited));
	cin>>n>>m;
	int from, to;
	for (int i = 0; i < m; i++){
		cin>>from>>to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}
	cout<<endl;
	bfs(0);
	system("pause");
	return 0;
}
