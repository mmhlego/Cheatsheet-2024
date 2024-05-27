// TODO

#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll lsb(ll x) { return x & -x; }

int main() {
	ll n = 9;
	ll a[n] = { 0,2,6,2,5,3,1,4,6 };

	ll fenwick[n];
	memcpy(fenwick, a, n);

	for (int i = 1;i < n;i++) {
		ll j = i + lsb(i);

		if (j <= n) fenwick[j] += fenwick[i];
	}
}
