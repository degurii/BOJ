#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	struct Edge {
		int to, cap;
		Edge *rev;
		Edge(int t = 0, int c = 0) : to(t), cap(c), rev(NULL) {}
	};
	
	int n, source, sink;
	vector<vector<Edge*>> p;
	MaxFlow(int n = 0, int source = 0, int sink = 0) : n(n), source(source), sink(sink) {
		p.resize(n);
	}
	
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		p[u].push_back(ori);
		p[v].push_back(rev);
	}
	
	int bfs() {
		vector<bool> check(n);
		vector<pair<int, Edge*>> from(n, { -1, 0 });
		queue<int> q;
		
		q.push(source);
		check[source] = true;

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto e : p[now]) {
				int next = e->to;
				int ncap = e->cap;
				
				if (ncap > 0 && !check[next]) {
					check[next] = true;
					q.push(next);
					from[next] = { now, e }; 
				}
			}
		}
		if (!check[sink])
			return 0;
		
		int c = INF;
		for (int now = sink; now != source; now = from[now].first) {
			c = min(c, from[now].second->cap);
		}
		
		for (int now = sink; now != source; now = from[now].first) {
			auto e = from[now].second;
			e->cap -= c;
			e->rev->cap += c;
		}

		return c;
	}

	int flow() {
		int ans = 0;
		int f = 0;

		while (f = bfs())
			ans += f;
		
		return ans;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m; /* n: 정점의 수, m: 간선의 수 */
	MaxFlow mf(n, 0, n - 1); /* source를 0으로, sink를 n-1 로 가정 */
	for (int i = 0; i < m; i++) {
		int u, v, cap;
		cin >> u >> v >> cap;
		mf.add_edge(u, v, cap);
		mf.add_edge(v, u, cap); /* 양방향 간선이라 가정, 단방향이면 해당 줄을 생략 */
	}
	cout << mf.flow();
}