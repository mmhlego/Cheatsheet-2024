/*
	Description: -
	Time: O(V * E)
	Space: O(V)
*/

vector<int> bellmanford(vector<tuple<int, int, int>> edges, int start, int n) {

	vector<int> ans(n, INT32_MAX);
	ans[start] = 0;
	bool change = true;

	for (int i = 0; i < n && change; i++) {
		change = false;
		for (auto e : edges) {
			if (ans[get<0>(e)] + get<2>(e) < ans[get<1>(e)]) {
				ans[get<1>(e)] = ans[get<0>(e)] + get<2>(e);
				change = true;
			}
		}
	}

	if (change)
		ans[start] = -1;

	return ans;
}