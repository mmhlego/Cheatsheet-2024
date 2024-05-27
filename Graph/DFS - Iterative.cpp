/*
	Description: -
	Time: O(V + E)
	Space: O(V)
*/

ll n; // Number of nodes
vector<vector<ll>> adj; // Adjacency list of graph
vector<bool> visited;

void dfs() {
	ll start = 0;

	stack<ll> st;
	st.push(start);
	visited[node] = true;

	while (!st.empty()) {
		ll top = st.top();
		// Code ...
	}
}