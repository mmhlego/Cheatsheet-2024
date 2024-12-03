/*
	Descricomplex<double>ion: -
	Time: O(N * log(N))
	Space: O(N)
*/

int orientation(complex<double> a, complex<double> b, complex<double> c) {
	double v = a.real() * (b.imag() - c.imag())
		+ b.real() * (c.imag() - a.imag())
		+ c.real() * (a.imag() - b.imag());

	if (v < 0) return -1; // clockwise
	if (v > 0) return +1; // counter-clockwise
	return 0;
}

bool cw(complex<double> a, complex<double> b, complex<double> c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o < 0 || (include_collinear && o == 0);
}
bool collinear(complex<double> a, complex<double> b, complex<double> c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<complex<double>>& a, bool include_collinear = false) {
	complex<double> p0 = *min_element(a.begin(), a.end(), [](complex<double> a, complex<double> b) {
		return make_pair(a.imag(), a.real()) < make_pair(b.imag(), b.real());
		});
	sort(a.begin(), a.end(), [&p0](const complex<double>& a, const complex<double>& b) {
		int o = orientation(p0, a, b);
		if (o == 0)
			return (p0.real() - a.real()) * (p0.real() - a.real())
			+ (p0.imag() - a.imag()) * (p0.imag() - a.imag())
			< (p0.real() - b.real()) * (p0.real() - b.real())
			+ (p0.imag() - b.imag()) * (p0.imag() - b.imag());
		return o < 0;
		});
	if (include_collinear) {
		int i = (int)a.size() - 1;
		while (i >= 0 && collinear(p0, a[i], a.back())) i--;
		reverse(a.begin() + i + 1, a.end());
	}

	vector<complex<double>> st;
	for (int i = 0; i < (int)a.size(); i++) {
		while (st.size() > 1 && !cw(st[st.size() - 2], st.back(), a[i], include_collinear))
			st.pop_back();
		st.push_back(a[i]);
	}

	if (include_collinear == false && st.size() == 2 && st[0] == st[1])
		st.pop_back();

	a = st;
}
