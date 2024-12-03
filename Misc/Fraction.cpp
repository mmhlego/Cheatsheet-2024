struct fraction {
	long long x, y;

	fraction(long long a, long long b) {
		long long g = gcd(a, b);
		x = a / g;
		y = b / g;
	}

	bool operator < (const fraction& o) const {
		return (x * o.y < y * o.x);
	}
};
