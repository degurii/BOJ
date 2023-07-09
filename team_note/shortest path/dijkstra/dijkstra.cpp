#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

struct Edge {
	int to, cost;
	Edge(int t = 0, int c = 0) :to(t), cost(c) {};
};

int n, m;	//n: num of vertex, m: num of edge

vector<int> dijkstra(vector<vector<Edge> > &p, int now) {
	vector<int> dist(n + 1, INF);
	vector<bool> check(n + 1);
	priority_queue<pair<int, int> > q;

	dist[now] = 0;
	q.push({ 0, now });
	while (!q.empty()) {
		now = q.top().second;
		q.pop();

		if (check[now]) continue;
		check[now] = true;
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i].to;
			int ncost = p[now][i].cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<Edge> > p(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		p[u].push_back(Edge(v, w));
	}

	int start = 1;
	vector<int> dist = dijkstra(p, start); // assume that start node is 1
}