#include <bits/stdc++.h>
using namespace std;

#define MAXN 200013
#define MAXM 200013
#define INF 1123456

int N, M, K, Q;
int ufd[MAXN];
pair<int, pair<int, int>> edges[MAXM];
map<int, int> adj[MAXN];
vector<int> orderbyrow[MAXN];
vector<int> order;
int i2pos[MAXN], il[MAXN], ir[MAXN];
int parent[MAXN];
int depth[MAXN];
int C[MAXN];
int st2[4 * MAXN];

map<int, set<int> > colors[MAXN];
set<int> best[MAXN];

// Union-Find data structure
void ufd_init() {
	for (int i = 0; i < N; i++) {
		ufd[i] = i;
	}
}

int ufd_find(int x) {
	if (ufd[x] == x) return x;
	return (ufd[x] = ufd_find(ufd[x]));
}

void ufd_union(int x, int y) {
	x = ufd_find(x);
	y = ufd_find(y);
	ufd[y] = x;
}

void dfs(int n, int p=0) {
	parent[n] = p;
	depth[n] = depth[p] + 1;
	vector<pair<int, int> > v;
	for (auto c : adj[n]) {
		if (c.first != p) {
			v.push_back({c.second, c.first});
		}
	}
	sort(v.begin(), v.end());
	for (auto c : v) {
		orderbyrow[depth[n]].push_back(c.second);
		dfs(c.second, n);
	}
}

// Min-SegTree for tracking the global minimum from each vertex-local heap.
void update2(int i, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (i > hi || i < lo) return;
	if (lo == hi) { st2[node] = x; return; }
	int mid = (lo + hi) / 2;
	update2(i, x, lo, mid, 2 * node + 1);
	update2(i, x, mid + 1, hi, 2 * node + 2);
	st2[node] = min(st2[2 * node + 1], st2[2 * node + 2]);
}

int query2(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return INF;
	if (lo >= s && hi <= e) return st2[node];
	int mid = (lo + hi) / 2;
	auto p1 = query2(s, e, lo, mid, 2 * node + 1);
	auto p2 = query2(s, e, mid + 1, hi, 2 * node + 2);
	return min(p1, p2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);

	cin >> N >> M >> K >> Q;
	for (int i = 0; i < M; i++) {
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
		edges[i].second.first--;
		edges[i].second.second--;
	}

	// Lemma: In a cycle, the highest-length edge will never be the answer.
	// Proof: If that edge changes color, then another edge in the same cycle must change color ==> it is better.
	// ---
	// If we keep removing highest-length edges until we get a tree, then we can get to any MST just fine.
	// (We definitely can't get anything besides an MST, as that leads to a contradiction).
	// THUS: We use Kruskal and only keep the MST edges.
	ufd_init();
	sort(edges, edges + M);
	for (auto p : edges) {
		int u = p.second.first;
		int v = p.second.second;
		if (ufd_find(u) != ufd_find(v)) {
			ufd_union(u, v);
			adj[u][v] = p.first;
			adj[v][u] = p.first;
		}
	}

	// Now we reorder/relabel the nodes from 0..N-1 maintaining the following property:
	// For every node n, the new label of n is i2pos[n]. Furthermore, the labels
	// of n's children form a contiguous interval from [il[n]..ir[n]], and they satisfy
	// the property that the children with the highest-weight edge to n have the highest label.
	dfs(0);
	orderbyrow[0].push_back(0);
	for (int row = 0; row <= N; row++) {
		order.insert(order.end(), orderbyrow[row].begin(), orderbyrow[row].end());
	}
	assert(order.size() == N);

	memset(il, -1, sizeof il);
	memset(ir, -1, sizeof ir);
	for (int i = 0; i < order.size(); i++) {
		i2pos[order[i]] = i;
		if (order[i]) {
			if (il[parent[order[i]]] == -1) il[parent[order[i]]] = order[i];
			ir[parent[order[i]]] = order[i];
		}
	}

	// We're done with initial preprocessing; now we will start working with the nodes' colors.
	// At every vertex v, we will maintain an array of sets colors[v][c] that stores the weights
	// of the edges to all the children of v of color c. We also maintain a set best[v] that
	// stores all the minimum values of colors[v][c] for all values of c.
	// 
	// Lastly, we keep a Min-Segment Tree of size N that stores the lowest-weight edge from
	// v to a differently colored child of v for each node v. We can get the final answer by
	// querying the segment tree from [0..N-1].
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int n = 0; n < N; n++) {
		// Initialize the data structures using the initial types of grass (colors).
		if (il[n] == -1) {
			update2(i2pos[n], INF);
			continue;
		}

		for (int c = i2pos[il[n]]; c <= i2pos[ir[n]]; c++) {
			colors[n][C[order[c]]].insert(c);
		}

		for (auto& p : colors[n]) {
			best[n].insert(*p.second.begin());
		}

		auto it = best[n].begin();
		if (C[order[*it]] == C[n]) it++;
		if (it == best[n].end()) {
			update2(i2pos[n], INF);
		}
		else {
			update2(i2pos[n], adj[n][order[*it]]);
		}
	}
	for (int q = 0; q < Q; q++) {
		int A, B;
		cin >> A >> B;
		A--;
		int PB = C[A];
		C[A] = B;

		if (A) {
			// If A is not the root, then we update A's parent to reflect A's change in color.
			int n = parent[A];
			if (best[n].count(i2pos[A])) {
				best[n].erase(i2pos[A]);
				if (colors[n][PB].size() > 1) {
					best[n].insert(*(++colors[n][PB].begin()));
				}
			}
			
			if (colors[n][B].size() && i2pos[A] < *colors[n][B].begin()) {
				best[n].erase(*colors[n][B].begin());
				best[n].insert(i2pos[A]);
			}
			else if (colors[n][B].empty()) {
				best[n].insert(i2pos[A]);
			}
			colors[n][PB].erase(i2pos[A]);
			colors[n][B].insert(i2pos[A]);
			
			auto it = best[n].begin();
			if (C[order[*it]] == C[n]) {
				it++;
			}

			// Finally, update the segment tree at A's parent.
			if (it == best[n].end()) {
				update2(i2pos[n], INF);
			}
			else {
				update2(i2pos[n], adj[n][order[*it]]);
			}
		}

		if (~il[A]) {
			// If A has children (il[A] != -1), then we update A as well.
			auto it = best[A].begin();
			if (C[order[*it]] == C[A]) it++;

			// Update the segment tree at A.
			if (it == best[A].end()) {
				update2(i2pos[A], INF);
			}
			else {
				update2(i2pos[A], adj[A][order[*it]]);
			}
		}

		// Our final answer is the global minimum of the segment tree.
		cout << query2(0, N - 1) << '\n';
	}

	cout.flush();
	return 0;
}
