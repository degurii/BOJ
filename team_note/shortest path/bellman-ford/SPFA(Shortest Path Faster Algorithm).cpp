#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;

struct Edge {
	int to, cost;
	Edge(int t = 0, int c = 0) :to(t), cost(c) {}
};
int n, m;	// n: num of vertex, m: num of edge
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<Edge> > p(n + 1);
	vector<int> dist(n + 1, inf), cnt(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		p[u].push_back(Edge(v, w));
	}
	vector<bool> check(n + 1);
	queue<int> q;
	
	check[1] = true;	// assume that the start node is 1
	q.push(1);
	dist[1] = 0;
	bool cycle = false;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt[now]++;
		if (cnt[now] == n) { // visiting a vertex n times means that a negative cycle exists
			cycle = true;
			break;
		}
		check[now] = false;
		for (Edge &e : p[now]) {
			int next = e.to;
			int ncost = e.cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				if (!check[next]) {
					check[next] = true;
					q.push(next);
				}
			}
		}
	}

	if (cycle);	// case that negative cycle exists
	else;		// else
}