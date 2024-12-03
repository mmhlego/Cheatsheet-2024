// Decompose graph to a set of discount paths

vector<vi> AL;
vi par, heavy;// undirected tree
int heavy_light(int x) {
	int size = 1;
	int max_child_size = 0;
	for (auto& y : AL[x]) {
		if (y == par[x]) continue;
		par[y] = x;
		int child_size = heavy_light(y);
		if (child_size > max_child_size) {
			max_child_size = child_size;
			heavy[x] = y;
		}
		size += child_size;
	}
	return size;
}

vi group;
void decompose(int x, int p) {
	group[x] = p;
	for (auto& y : AL[x]) {
		if (y == par[x]) continue;
		if (y == heavy[x])
			decompose(y, p);
		else
			decompose(y, y);
	}
}
