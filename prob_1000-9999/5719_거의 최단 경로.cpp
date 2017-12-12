/*
문제
거의 최단 경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것을 말한다.
거의 최단 경로는 여러 개 존재할 수도 있다. 또, 거의 최단 경로가 없는 경우도 있다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 10^4)가 주어진다.
장소는 0부터 N-1번까지 번호가 매겨져 있다.
둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N)
다음 M개 줄에는 도로의 정보 U, V, P가 주어진다. (U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 10^3)
이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다.
U에서 V로 가는 도로는 최대 한 개이다. 또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 거의 최단 경로의 길이를 출력한다. 만약, 거의 최단 경로가 없는 경우에는 -1을 출력한다.
*/







/*
solution:
원래 그래프는를 ori, 모든 간선을 반대방향으로 뒤집은 그래프를 rev라 한다.
ori에서 다익스트라(s에서 시작)를 이용해 s에서 각 노드까지의 최단거리를 구할 수 있다.
이 최단거리 집합을 dist1이라 한다.
rev에서 다익스트라(d에서 시작)를 이용해 각 노드에서 d까지의 최단거리를 구할 수 있다.
이 최단거리 집합을 dist2라 한다.
앞으로 rev는 쓰이지 않는다.

s에서부터 bfs를 돌린다
한 정점 u에서 다음 정점 v를 확인할 때,
dist1[v]+dist2[v] == (s->d까지의 최단거리)이면 간선 (u, v)는 최단경로에 포합된 경로이므로 체크해둔다.

그래프를 처음부터 확인하면서 체크돼있지 않은 간선만 모아 새로 그래프를 만든다.
이 때, 새로운 그래프의 s에서 d까지의 최단거리가 답이 된다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int> >;
using vvb = vector<vector<bool> >;

int n, m;
int s, d;
struct Node {
	int u, w;
	Node(int u = 0, int w = 0) :u(u), w(w) {}
};

vector<int> dijkstra(vector<vector<Node> > &p, int now) {
	vb check(n);
	vi dist(n, INF);
	priority_queue<pair<int, int> > q;
	dist[now] = 0;
	q.push({ 0, now });
	while (!q.empty()) {
		now = q.top().second;
		q.pop();
		if (check[now]) continue;
		check[now] = true;
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i].u;
			int ncost = p[now][i].w;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist;
}

void rm_e(vector<vector<Node> > &p, vvb &e, vi &d1, vi &d2, int mind) {
	vb check(n);
	queue<int> q;
	check[s] = true;
	q.push(s);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i].u;
			
			if (d1[next] + d2[next] == mind) {	
				if (check[next] == false) {
					check[next] = true;
					q.push(next);
				}
				e[now][next] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m, (n != 0 & m != 0)) {
		vector<vector<Node> > ori(n), rev(n);
		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			ori[u].push_back(Node(v, w));
			rev[v].push_back(Node(u, w));
		}

		vi dist1 = dijkstra(ori, s);
		vi dist2 = dijkstra(rev, d);
		if (dist1[d] == INF) {
			cout << -1 << '\n';
			continue;
		}
		vvb check(n, vb(n));
		rm_e(ori, check, dist1, dist2, dist1[d]);
		
		vector<vector<Node> > p(n);
		for (int now = 0; now < n; now++) {
			for (int j = 0, l = ori[now].size(); j < l; j++) {
				int next = ori[now][j].u;
				int ncost = ori[now][j].w;
				if (!check[now][next]) {
					p[now].push_back(Node(next, ncost));
				}
			}
		}
		vi ans = dijkstra(p, s);
		if (ans[d] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << ans[d] << '\n';
		}
	}
}