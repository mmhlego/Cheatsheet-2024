/*
	Description: -
	Time: O(N)
	Space: O(N)
*/

vector<ll> rolling_hash(vector<int> s, ll p = 53) {
	int n = s.size();
	vector<ll> rh(n + 1, 0);
	ll p_pow = 1;
	for (int i = 0; i < n; i++)
	{
		rh[i + 1] = (rh[i] + (s[i] * p_pow) % MOD) % MOD;
		p_pow = (p_pow * p) % MOD;
	}
	return rh;
}

// Description: -
// Time: O(log(s2 - s1))
// Space: O(1)
bool compare(vector<ll> rh, int s1, int e1, int s2, int e2, int p = 53) {
	if (s2 < s1) {
		swap(s1, s2);
		swap(e1, e2);
	}
	ll h1 = rh[e1 + 1] - rh[s1], h2 = rh[e2 + 1] - rh[s2];

	return(h1 * binpow(p, s2 - s1, MOD)) % MOD == h2;
}