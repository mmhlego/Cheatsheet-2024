/*
	Description: -
	Time: O(K)
	Space: O(1)
*/

int Binomial_Coefficient(int n, int k) {
	double res = 1;
	for (int i = 1; i <= k; ++i)
		res = res * (n - k + i) / i;
	return (int)(res + 0.01);
}