/*
	Description: -
	Time: O(V + E)
	Space: O(V)
*/

ll n; // number of nodes
vector<vector<ll>> adj; // adjacency list of graph
vector<bool> visited;

void dfs(ll node) {
	visited[node] = true;

	// Code ...

	for (auto x : adj[node]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}