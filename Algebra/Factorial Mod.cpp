/*
	Description: -
	Time: O(N * log(P))
	Space: O(N)
	https://cp-algorithms.com/algebra/factorial-modulo.html
*/

vector<int> f;

// O(p)
int calc_once(ll n, ll p) {
	f.push_back(1);
	for (int i = 1; i < p; i++)
		f.push_back(f[i - 1] * i % p);

	factorial_mod(n, p);
}

// O(N * log(P))
int factorial_mod(ll n, ll p) {
	// p must be prime
	ll res = 1;
	while (n > 1) {
		if ((n / p) % 2)
			res = p - res;
		res = res * f[n % p] % p;
		n /= p;
	}
	return res;
}
