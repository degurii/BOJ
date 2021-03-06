/*
문제
어떤 플로우 그래프가 주어졌을때, 한 간선의 용량이 1줄면 최대 유량도 1이 줄어드는 경우 그 간선을 완전 중요한 간선이라고 부른다. 그래프가 주어진 경우 완전 중요한 간선의 개수를 세어보자!

입력
입력은 여러개의 테스트케이스로 이뤄진다. 첫째 줄에는 테스트케이스의 수 K (1<=K<=15)가 주어진다.
각 테스트 케이스에는 N, M (2 <= N <= 300; 2 <= M <= 5,000)가 주어지고 각각 정점의 수와 간선의 수를 뜻한다. 1번 정점은 source를 N번 정점은 sink를 뜻한다.
다음 M줄에 걸쳐서는 세개의 정수 f, t, b가 주어지는데 f에서 t로 가는 간선의 용량이 b(<1000)라는 뜻이다. 모든 유량의 합은 20,000을 넘지 않는다.

출력
각 테스트케이스마다 한줄씩 완전 중요한 간선의 수를 출력한다.
*/


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
	vector<pair<int, int>> edges;
	bool d[301][301];

	MaxFlow(int n, int src, int sink) :n(n), source(src), sink(sink) {
		p.resize(n);
		fill(&d[0][0], &d[0][0] + 301 * 301, 0);
		for (int i = 0; i < n; i++)
			d[i][i] = true;
	}

	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		p[u].push_back(ori);
		p[v].push_back(rev);
		edges.push_back({ u, v });
	}

	bool bfs() {
		level = vector<int>(n, -1);
		queue<int> q;
		level[source] = 0;
		q.push(source);

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
		if (now == sink) return c;
		for (int &i = work[now]; i < p[now].size(); i++) {
			auto e = p[now][i];
			int next = e->to;
			int ncap = e->cap;
			if (ncap > 0 && level[next] == level[now] + 1) {
				int f = dfs(next, min(c, ncap));
				if (f) {
					e->cap -= f;
					e->rev->cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	
	void flow() {
		while (bfs()) {
			work = vector<int>(n);
			while (dfs(source, INF));
		}
	}
	
	int numCrucial() {
		flow();
		for (int i = 1; i < n; i++) {
			for (auto e : p[i]) {
				if (e->cap > 0) {
					d[i][e->to] = true;
				}
			}
		}
		
		for (int k = 1; k < n; k++) {
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < n; j++) {
					if (d[i][k] && d[k][j])
						d[i][j] = true;
				}
			}
		}
		int ans = 0;

		for (auto i : edges) {
			int u = i.first, v = i.second;
			if (!d[u][v]) ans++;
		}
		return ans;
	}
	~MaxFlow() {
		for (auto &i : p) {
			for (int j = 0; j < i.size(); j++) {
				auto &e = i.back();
				delete e;
				i.pop_back();
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		MaxFlow mf(n + 1, 1, n);
		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			mf.add_edge(u, v, c);
		}
		cout << mf.numCrucial() << '\n';
	}
}