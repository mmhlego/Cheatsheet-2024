typedef vector<int> vi;

class SegmentTree {
private:
	int n;
	vi A, st, lazy;
	// OOP style
	// n = (int)A.size()
	// the arrays
	int l(int p) { return p << 1; }
	int r(int p) { return (p << 1) + 1; }
	// go to left child
	// go to right child
	int conquer(int a, int b) {
		if (a == -1) return b;
		if (b == -1) return a;
		return min(a, b);
	}
	// corner case
	// RMQ
	void build(int p, int L, int R) {
		if (L == R)
			st[p] = A[L];
		else {
			int m = (L + R) / 2;
			build(l(p), L, m);
			build(r(p), m + 1, R);
			st[p] = conquer(st[l(p)], st[r(p)]);
		}
	}
	void propagate(int p, int L, int R) {
		if (lazy[p] != -1) {
			st[p] = lazy[p];
			if (L != R)
				lazy[l(p)] = lazy[r(p)] = lazy[p];
			else
				A[L] = lazy[p];
			lazy[p] = -1;
		}
	}
	// O(n)
	// base case
	// has a lazy flag
	// [L..R] has same value
	// not a leaf
	// propagate downwards
	// L == R, a single index
	// time to update this
	// erase lazy flag
	int RMQ(int p, int L, int R, int i, int j) {
		// O(log n)
		propagate(p, L, R);
		// lazy propagation
		if (i > j) return -1;
		// infeasible
		if ((L >= i) && (R <= j)) return st[p];
		// found the segment
		int m = (L + R) / 2;
		return conquer(RMQ(l(p), L, m, i
			, min(m, j)),
			RMQ(r(p), m + 1, R, max(i, m + 1), j
			));
	}
	void update(int p, int L, int R, int i, int j, int val) { // O(log n)
		propagate(p, L, R);
		// lazy propagation
		if (i > j) return;
		if ((L >= i) && (R <= j)) {
			// found the segment
			lazy[p] = val;
			// update this
			propagate(p, L, R);
			// lazy propagation
		} else {
			int m = (L + R) / 2;
			update(l(p), L, m, i
				, min(m, j), val);
			update(r(p), m + 1, R, max(i, m + 1), j
				, val);
			int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
			int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
			st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
		}
	}
public:
	SegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}
	SegmentTree(const vi& initialA) : SegmentTree((int)initialA.size()) {
		A = initialA;
		build(1, 0, n - 1);
	}
	void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }
	int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

int main() {
	vi A = { 18, 17, 13, 19, 15, 11, 20, 99 };
	SegmentTree st(A);
	printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));
	// remains 13
	printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));
	// now 15
	printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));
	// remains 15
}