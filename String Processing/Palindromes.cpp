/*
	Description: -
	Time: O(N)
	Space: O(N)
*/

vector<int> odd_palindromes(vector<int> s) {
	int n = s.size();
	vector<int> oddP(n, 0);
	int L = -1, R = -1;
	for (int i = 0; i < n; i++)
	{
		if (i < R) {
			oddP[i] = min(R - i, oddP[L + R - i]);
		}
		int left = i - oddP[i] - 1, right = i + oddP[i] + 1;
		while (left >= 0 && right < n && s[left] == s[right]) {
			oddP[i]++;
			right++;
			left--;
		}
		if (i + oddP[i] > R)
		{
			L = i - oddP[i];R = i + oddP[i];
		}
	}
	return oddP;
}

vector<int> even_palindromes(vector<int> s) {
	int n = s.size();
	vector<int> evenP(n - 1, 0);
	int L = -1, R = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (i < R) {
			evenP[i] = min(R - i, evenP[L + R - i - 1]);
		}
		int left = i - evenP[i], right = i + evenP[i] + 1;
		while (left >= 0 && right < n && s[left] == s[right]) {
			evenP[i]++;
			right++;
			left--;
		}
		if (i + evenP[i] > R)
		{
			L = i - evenP[i] + 1;R = i + evenP[i];
		}
	}
	return evenP;
}