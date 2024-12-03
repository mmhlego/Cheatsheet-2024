/*
	Description: -
	Time: O(log(m))
	Space: O(1)
*/

// Import
ll binary_power(ll a, ll b, ll m);
ll phi(ll n);

ll mod_inv(ll num, ll mod) {
	return binary_power(num, phi(mod) - 1, mod);
}
