/*
	Description: -
	TODO Time: O(K)
	TODO Space: O(1)
*/

#define ll long long

factorial[0] = 1;
for (int i = 1; i <= MAXN; i++) {
	factorial[i] = factorial[i - 1] * i % m;
}
//solving for one inverse
long long binomial_coefficient(int n, int k) {
	return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}

//saving all inverse factorials
long long binomial_coefficient(int n, int k) {
	return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
}

//returns inverse of vector "a" 
std::vector<ll> inverse(const std::vector<ll> &a, ll m) {
	ll n = a.size();
	if (n == 0) return {};
	std::vector<ll> b(n), prem(n + 1, 1), sufm(n + 1, 1);
	ll all_m = 1;
	for (int i = 0; i < n; i++)
	{
		all_m = (a[i] * all_m) % m;
		prem[i + 1] = (prem[i] * a[i]) % m;
		sufm[i + 1] = (sufm[i] * a[n - i - 1]) % m;
	}
	all_m = inv(all_m, m);
	for (int i = 0; i < n; i++)
	{
		b[i] = ((prem[i] * sufm[n - i - 1]) % m * all_m) % m;
	}
	return b;
}