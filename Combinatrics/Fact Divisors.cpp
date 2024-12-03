/*
	Description: -
	Time: O(log_k(n))
	Space: O(1)
*/

int fact_pow(int n, int k) {
	int res = 0;
	while (n) {
		n /= k;
		res += n;
	}
	return res;
}

// TODO
