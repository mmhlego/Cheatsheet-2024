/*
	Description: Returns x for which ((a^x = b mod m)), a and m are co-prime
	Time: O(sqrt(m) * log(m))
	Space: O(sqrt(m))
*/

ll binary_power(ll a, ll b, ll m);

ll discrete_log(ll a, ll b, ll m) {
	a %= m, b %= m;
	ll n = sqrt(m) + 1;
	map<ll, ll> vals; // saves only a single value, map<ll, vector<ll>> 

	for (ll p = 1; p <= n; ++p)
		vals[binary_power(a, p * n, m)] = p;

	for (ll q = 0; q <= n; ++q) {
		ll cur = binary_power(a, q, m) * b % m;
		if (vals.count(cur)) {
			ll ans = vals[cur] * n - q;
			return ans;
		}
	}

	return -1;
}

// calculate minimum x by mod phi(m)