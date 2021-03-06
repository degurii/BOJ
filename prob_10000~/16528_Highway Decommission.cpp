#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#define INF (1LL<< 61)
using namespace std;
using ll = long long;

int n, m;
struct Edge {
	int to, len, cost;
	Edge(int t = 0, int l = 0, int c = 0) :to(t), len(l), cost(c) {}
};
vector<vector<Edge>> p;
vector<bool> chk;
vector<ll> dist;
priority_queue<tuple<ll, ll, int>> q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	chk.resize(n + 1);
	dist.resize(n + 1, INF);
	for (int i = 0; i < m; i++) {
		int u, v, l, c;
		cin >> u >> v >> l >> c;
		p[u].emplace_back(v, l, c);
		p[v].emplace_back(u, l, c);
	}
	dist[1] = 0;
	ll ans = 0;
	q.push({ 0, 0, 1 });
	while (!q.empty()) {
		auto[_, c, now] = q.top();
		q.pop();
		if (chk[now]) continue;
		chk[now] = true;
		ans -= c;

		for (auto e : p[now]) {
			auto [next, nlen, ncost] = e;
			
			if (dist[next] >= dist[now] + nlen) {
				dist[next] = dist[now] + nlen;
				q.push({ -dist[next], -ncost, next });
			}
		}
	}
	cout << ans;
}