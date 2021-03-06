/*
문제
N개의 도시가 P개의 양방향 길로 연결되어 있다. 이석원은 1번 도시와 2번 도시 사이를 오가며 워해머를 한다.
성실한 이석원은 두 도시 사이를 최대한 많이 왔다 갔다 하려 하는데, 이 때 한 번 방문했던 도시(1, 2번 도시 제외)를 두 번 이상 방문하지 않으려 한다.
한 번 1번 도시와 2번 도시 사이를 오갈 때, 반드시 한 개 이상의 도시를 중간에 거쳐야 한다. 입력에는 1번 도시와 2번 도시를 연결하는 길은 없다.

입력
첫째 줄에 두 정수 N(3≤N≤400), P(1≤P≤10,000)이 주어진다.
다음 P개의 줄에는 각 길이 연결하는 서로 다른 두 도시의 번호가 주어진다.

출력
첫째 줄에 왔다 갔다 할 수 있는 최대 회수를 출력한다.1
*/


/*
solution:
각 정점을 한번만 지나야 하므로, 한 정점을 들어오는 정점과 나가는 정점으로 쪼개
그 사이의 용량을 1로 제한하여 연결한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct MaxFlow {
	struct Edge {
		int to, capacity;
		Edge *rev;
		Edge(int t = 0, int c = 0) :to(t), capacity(c), rev(NULL) {}
	};

	int n, source, sink;
	vector<vector<Edge*>> p;
	MaxFlow(int n, int source, int sink) :n(n), source(source), sink(sink) {
		p.resize(n * 2);
		for (int i = 0; i < n; i++) {
			int u = i * 2, v = i * 2 + 1;
			Edge *in = new Edge(v, 1), *out = new Edge(u);
			in->rev = out;
			out->rev = in;
			p[u].push_back(in);
			p[v].push_back(out);
		}
	}

	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, 1);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = rev;
		p[u].push_back(ori);
		p[v].push_back(rev);
	}

	int bfs() {
		vector<bool> check(2 * n);
		vector<pair<int, Edge*>> from(2 * n, { -1, 0 });
		queue<int> q;
		q.push(source);
		check[source] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (auto e : p[now]) {
				int next = e->to;
				int ncap = e->capacity;

				if (ncap > 0 && !check[next]) {
					check[next] = true;
					q.push(next);
					from[next] = { now, e };
				}
			}
		}
		if (!check[sink]) return 0;

		int x = from[sink].first;
		int c = from[sink].second->capacity;
		for (; from[x].first != -1; x = from[x].first) {
			c = min(c, from[x].second->capacity);
		}

		x = sink;
		for (; from[x].first != -1; x = from[x].first) {
			auto e = from[x].second;
			e->capacity -= c;
			e->rev->capacity += c;
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

	int n, p;
	cin >> n >> p;
	MaxFlow mf(n, 1, 2); // 0_out, 1_in
	for (int i = 0; i < p; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int u_in = u * 2, u_out = u * 2 + 1;
		int v_in = v * 2, v_out = v * 2 + 1;
		mf.add_edge(u_out, v_in, 1);
		mf.add_edge(v_out, u_in, 1);
	}
	cout << mf.flow();
}
		