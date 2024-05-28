/*
	Description: A Lucas Theorem based solution to compute nCr % p
	TODO Time: O(K)
	TODO Space: O(1)
*/

int nCr_Modp_DP(int n, int r, int p) {
	int C[r + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = min(i, r); j > 0; j--)
			C[j] = (C[j] + C[j - 1]) % p;
	}
	return C[r];
}

int nCr_Modp_Lucas(int n, int r, int p) {
	if (r == 0)
		return 1;

	int ni = n % p, ri = r % p;

	return (nCr_Modp_Lucas(n / p, r / p, p) * nCr_Modp_DP(ni, ri, p)) % p;
}
