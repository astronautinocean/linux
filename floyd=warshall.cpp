
#include <iostream>
using namespace std;
const int INF = 1e9 + 7;
int dp[1000][1000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		dp[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		u--, v--;
		dp[u][v] = dp[v][u] = len;
	}
	for (int k = 0; k < n; k++) { //current node
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
//dp updated with shortest paths
}

