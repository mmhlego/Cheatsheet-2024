/*
	Description: Factorizes all numbers [2,n]
	Time: O(N)
	Space: O(N)
*/

void sieve_liner(int n) {
	vector<int> leastPrime(n + 1);
	vector<int> pr;

	for (int i = 2; i <= n; ++i) {
		if (leastPrime[i] == 0) {
			leastPrime[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= n; ++j) {
			leastPrime[i * pr[j]] = pr[j];
			if (pr[j] == leastPrime[i]) {
				break;
			}
		}
	}
}
