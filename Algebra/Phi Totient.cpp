/*
	Description: -
	TODO: Time: O(?)
	TODO: Space: O(?)
*/

ll phi(ll n) {
	ll result = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

// TODO
1_to_n(int n) {
	vector<int> phi_vec(n + 1);
	for (int i = 0; i <= n; i++)
		phi_vec[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi_vec[i] == i) {
			for (int j = i; j <= n; j += i)
				phi_vec[j] -= phi_vec[j] / i;
		}
	}
}