#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
	Description: -
	Time: O(sqrt(N))
	Space: O(1)
*/

ll mult(ll a, ll b, ll mod) {
	return (__int128)a * b % mod;
}

ll f(ll x, ll c, ll mod) {
	return (mult(x, x, mod) + c) % mod;
}

ll rho(ll n, ll x0 = 2, ll c = 1) {
	ll x = x0;
	ll y = x0;
	ll g = 1;

	while (g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		g = gcd(abs(x - y), n);
	}

	if (g == n) {
		return rho(n, x0 + 1, c);
	}

	return g;
}

int main() {
	cout << rho(2206637);
}