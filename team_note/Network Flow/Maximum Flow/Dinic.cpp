#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

struct MaxFlow {
	struct Edge {
		int to, cap;
		Edge *rev;
		Edge(int t = 0, int c = 0) :to(t), cap(c), rev(NULL) {}
	};
	
	int n, source, sink;
	vector<vector<Edge*>> p;
	vector<int> level, work;
	MaxFlow(int n, int source, int sink) :n(n), source(source), sink(sink) {
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

	bool bfs() {
		level = vector<int>(n, -1);
		queue<int> q;
		q.push(source);
		level[source] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto e : p[now]) {
				int next = e->to;
				int ncap = e->cap;
				if (ncap > 0 && level[next] == -1) {
					level[next] = level[now] + 1;
					q.push(next);
				}
			}
		}
		
		return (level[sink] != -1);
	}

	int dfs(int now, int c) {
		if (now == sink)
			return c;
		for (int &i = work[now]; i < p[now].size(); i++) {
			auto e = p[now][i];
			int next = e->to;
			int ncap = e->cap;

			if(level[next] == level[now] + 1 && ncap > 0){
				ncap = min(c, ncap);
				int f = dfs(next, ncap);
				if (f > 0) {
					e->cap -= f;
					e->rev->cap += f;
					return f;
				}
			}
		}

		return 0;
	}
	
	int flow() {
		int ans = 0;
		while (bfs()) {
			work = vector<int>(n);
			int f = 0;
			while (f = dfs(source, INF)) {
				ans += f;
			}
		}

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