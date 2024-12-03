#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update
> ordered_set;

int main() {
	ordered_set tree;

	tree.insert(3);
	tree.order_of_key(1);
	tree.find_by_order(1);
	tree.size();
	tree.max_size();
	*tree.lower_bound(0);
	*tree.upper_bound(4);
}

