/*
	Description: -
	Time: Processing: O(N * log(N))
		  Query: O(N)
	Space: O(N + E)
*/

// read this https://www.topcoder.com/thrive/articles/Range%20Minimum%20Query%20and%20Lowest%20Common%20Ancestor
// please read it ffs.  <O(N), O(1)> ALGORITHM FOR THE RESTRICTED RMQ and how to be used in LCA

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (int u : adj[v]) {
		if (u != p)
			dfs(u, v);
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root) {
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dfs(root, root);
}
