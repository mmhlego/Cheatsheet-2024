/*
	Description: -
	Time: Construction: O(N * log(N))
		  Query: O(1)
	Space: O(N)
*/

vector<vector<ll>>buildSparseTable(vector<ll> array, const ll& (*func)(const ll&, const ll&)) {
	vector<vector<ll>> sparseTable;
	sparseTable.push_back(array);
	ll n = array.size(), j = 1;

	while ((1 << j) <= n) {
		sparseTable.push_back(vector<ll>());
		for (ll i = 0; i < n - (1 << j) + 1; i++) {
			sparseTable[j].push_back(func(sparseTable[j - 1][i], sparseTable[j - 1][i + (1 << (j - 1))]));
		}
		j++;
	}

	return sparseTable;
}

ll querySparseTable(vector<vector<ll>>& st, ll i, ll j, const ll& (*func)(const ll&, const ll&)) {
	ll l = j - i + 1, k = 0;
	while ((1 << (k + 1)) <= l)k += 1;

	return func(st[k][i], st[k][j - (1 << k) + 1]);
}

int main() {
	vector<ll> arr = { 1,2,3,4,5 };
	auto st = buildSparseTable(arr, max);
	int i = 0, j = 4;
	querySparseTable(st, i, j, max);
}