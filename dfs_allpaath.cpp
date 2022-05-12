#include<iostream>
#include<vector>
using namespace std;
int n,m, a,b;
vector <vector<int>> adj;
vector <int> visited, path;
void dfs(int curr, int dest){
	if(curr == dest) {
		for(int i = 0; i < path.size(); i++) {
			cout << path[i] << ' ‘;
		}
		cout << dest << '\n’;
		return;
	}
	path.push_back(curr);
	visited[curr] = true;
	for (int i = 0; i < adj[curr].size(); ++i) {
		int now = adj[curr][i];
		if(!visited[now])
			dfs(now, dest);
	}
	path.pop_back();
	visited[curr] = false;
}
int main(){
	cin >> n >> m;
	adj = vector <vector <int>>(n);
	visited = vector <int> (n, 0);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<endl;
	dfs(0, 4);
	system("pause");
	return 0;
}
