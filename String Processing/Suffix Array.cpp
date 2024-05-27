/*
	Description: -
	TODO Time: O(max(N, M))
	TODO Space: O(max(N, M))
*/

vector<int> buildSuffixArray(vector<int>& s) {
	int n = s.size();
	vector<int> suffixArray(n), rank(n), temp(n);

	for (int i = 0; i < n; i++) {
		suffixArray[i] = i;
		rank[i] = s[i];
	}

	for (int k = 1; k < n; k *= 2) {
		auto cmp = [&](int i, int j) {
			if (rank[i] != rank[j]) return rank[i] < rank[j];
			int ri = (i + k < n) ? rank[i + k] : -1;
			int rj = (j + k < n) ? rank[j + k] : -1;
			return ri < rj;
			};
		sort(suffixArray.begin(), suffixArray.end(), cmp);

		temp[suffixArray[0]] = 0;
		for (int i = 1; i < n; i++) {
			temp[suffixArray[i]] = temp[suffixArray[i - 1]];
			if (cmp(suffixArray[i - 1], suffixArray[i])) {
				temp[suffixArray[i]]++;
			}
		}
		rank = temp;
	}

	return suffixArray;
}

// function to build LCP array
vector<int> buildLCPArray(vector<int> s, const vector<int>& suffixArray) {
	int n = s.size();
	vector<int> lcp(n, 0), rank(n, 0);

	for (int i = 0; i < n; i++) {
		rank[suffixArray[i]] = i;
	}

	int h = 0;
	for (int i = 0; i < n; i++) {
		if (rank[i] > 0) {
			int j = suffixArray[rank[i] - 1];
			while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
				h++;
			}
			lcp[rank[i]] = h;
			if (h > 0) h--;
		}
	}

	return lcp;
}

bool comp(const string& s, int i, const string& t, int k) {
	while (k + i < s.size() && k < t.size() && s[i + k] == t[k]) k++;
	if (k + i == s.size())return true;
	if (k == t.size())return false;
	return s[i + k] < t[k];

}


bool queryExists(const string& s, const string& subs, const vector<int>& suffixArray, vector<vector<int>>& lcpSparseTable) {
	int n = s.size(), l = 0, r = n - 1;
	while (l + 1 < r) {
		int g = (l + r) / 2;
		int k = querySparseTable(lcpSparseTable, l, r, min);
		bool b = comp(s, suffixArray[g], subs, k);

		if (b) l = g;
		else r = g;
	}
	int i = 0;
	while (suffixArray[l] + i < s.size() && i < subs.size() && s[suffixArray[l] + i] == subs[i])i++;
	return i == subs.size();
}




// between n strings s1,...,sn finds longest common between atleast k of them (undefined behavior k=1)
int longestCommonSubstring(const vector<string> strings, int k) {
	vector<int> s;

	int n = strings.size();
	for (int i = 0; i < strings.size();i++) {
		for (auto c : strings[i]) {
			s.push_back(c);
		}
		s.push_back(-i - 1);
	}
	auto suffixArray = buildSuffixArray(s);
	auto LCPArray = buildLCPArray(s, suffixArray);
	auto LCPSparseTable = buildSparseTable(LCPArray, min);
	vector<int> type(s.size());
	int j = 0, cnt = strings[0].size() + 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == cnt)
		{
			j += 1;
			cnt += strings[j].size() + 1;
		}
		type[i] = j;
	}
	int ans = 0;
	vector<int>freq(n, 0);
	int i = n, ii = n;
	cnt = 0;
	for (int i = n; i < s.size(); i++) {
		if (!freq[type[suffixArray[i]]])cnt++;
		freq[type[suffixArray[i]]]++;

		while (cnt >= k) {
			ans = max(ans, querySparseTable(LCPSparseTable, ii + 1, i, min));
			freq[type[suffixArray[ii]]]--;
			if (!freq[type[suffixArray[ii]]]) cnt--;
			ii++;
		}
	}
	return ans;
}

int countUniqueSubStrings(const vector<int>& lcpArray) {
	int n = lcpArray.size(), c = 0;
	for (int i = 0; i < n; i++) {
		c += lcpArray[i];
	}
	return n * (n + 1) / 2 - c;
}


// longest substring repeated in same string.
int longestRepeatedSubStrings(const vector<int>& lcpArray) {
	int n = lcpArray.size(), c = 0;
	for (int i = 0; i < n; i++) {
		c = max(c, lcpArray[i]);
	}
	return c;
}