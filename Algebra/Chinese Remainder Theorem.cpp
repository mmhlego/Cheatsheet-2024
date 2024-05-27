#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
	Description: -
	Time: O(M)
	Space: O(1)
*/

// Import
ll gcd_extended(ll a, ll b, ll& x, ll& y);

pair<ll, ll> chinese_remainder_theorem(vector<pair<ll, ll>> congruences) {
	// congruences = [(a1,m1),(a2,m2),...]

	ll p, q;
	auto [a, m] = congruences.back();
	congruences.pop_back();
	while (!congruences.empty())
	{
		auto [ta, tm] = congruences.back();
		congruences.pop_back();
		ll g = gcd_extended(m, tm, p, q);
		if ((a - ta) % g != 0)
		{
			return { -1,-1 };
		}

		ll nm = m / g * tm;
		a = ((a * (tm / g) * q) % nm) + ((ta * (m / g) * p) % nm);
		a = (a + nm + nm) % nm;
		m = nm;
	}

	return { a, m };
}

int main() {
	vector<pair<ll, ll>> congruences;
	congruences.push_back({ 11,23 });
	congruences.push_back({ 1,81 });
	congruences.push_back({ 9,97 });

	auto x = chinese_remainder_theorem(congruences);
	for (auto y : congruences) {
		cout << x.first << " % " << y.second << " = " << x.first % y.second << endl;
	}
}