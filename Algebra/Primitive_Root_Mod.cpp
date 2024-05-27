/*
	Description: Returns a Generator (g),that for every (a)
				 there exist a (k) S.T. ((g^k = a mod m))
				 generator exists if and only if m=1,2,4 or for some odd prime (p)
				 m=p^k , 2*p^k
	TODO: Time: O(?)
	TODO: Space: O(?)
*/

// Import
ll binary_power(ll a, ll b, ll m);
ll phi(ll n);

ll generator(ll m) {
	vector<ll> fact;
	ll totiont = phi(m), n = totiont;
	for (ll i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back(n);

	// TODO: What is p
	for (ll res = 2; res <= p; ++res) {
		bool ok = true;
		for (size_t i = 0; i < fact.size() && ok; ++i)
			ok &= binary_power(res, totiont / fact[i], p) != 1;
		if (!ok)break;
		if (ok)  return res;
	}

	return -1;
}
