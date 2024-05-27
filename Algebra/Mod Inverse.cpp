/*
	Description: -
	TODO: Time: O(?)
	TODO: Space: O(?)
*/

// Import
ll binary_power(ll a, ll b, ll m);
ll phi(ll n);

// O(log(m))
ll mod_inv(ll num, ll mod) {
	return binary_power(num, phi(mod) - 1, mod);
}
