/*
	Description: Calculate the nth number in fibonacci sequence
	Time: O(log(N))
	Space: O(1)
*/

pair<int, int> fib(int n) {
	// returns F_n and F_n+1

	if (n == 0)
		return { 0, 1 };

	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;
	if (n & 1)
		return { d, c + d };
	else
		return { c, d };
}
