#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 500; // Max number of vertices

vector<int> graph[N]; // Adjacency list representation
int match[N]; // Stores the matching
bool vis[N]; // Visited array

// Find an augmenting path
bool dfs(int u) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			vis[v] = true;
			if (match[v] == -1 || dfs(match[v])) {
				match[u] = v;
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Blossom algorithm
int blossom(int n) {
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (match[i] == -1) {
			memset(vis, false, sizeof(vis));
			if (dfs(i)) {
				++ans;
			}
		}
	}
	return ans;
}

int main() {
	// Example usage
	int n, m; // Number of vertices and edges
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; // Edge (u, v)
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int maxMatching = blossom(n);
	cout << "Maximum matching size: " << maxMatching << endl;
	return 0;
}
