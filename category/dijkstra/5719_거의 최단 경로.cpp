/*
입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 104)가 주어진다. 장소는 0부터 N-1번까지 번호가 매겨져 있다.
둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N)
다음 M개 줄에는 도로의 정보 U, V, P가 주어진다. (U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103) 이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다.
U에서 V로 가는 도로는 최대 한 개이다. 또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 거의 최단 경로의 길이를 출력한다.
만약, 거의 최단 경로가 없는 경우에는 -1을 출력한다.
*/


/*
solution:
어떤 간선 u->v가 원래 최단경로에 포함되는 간선인지 확인해야 한다.
이는 (최단거리[시작점 -> u] + 거리[u->v] + 최단거리[v -> 도착점])이 최단거리[시작점 - 도착점]과 판단하면 된다.
어떤 점점 v에서 도착점까지의 거리는
그래프의 간선 방향을 거꾸로한 역그래프에서 도착점에서부터 다익스트라를 돌리면 구할 수 있다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int n, m;
int s, d;
struct Edge {
	int to, cost;
	bool used;
	Edge(int t = 0, int c = 0) :to(t), cost(c), used(false){}
};
vector<vector<Edge>> ori, rev;
vector<int> dijkstra(vector<vector<Edge>> &p, int now) {
	vector<bool>check(n + 1);
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> q;
	q.push({ 0, now });
	dist[now] = 0;
	while (!q.empty()) {
		int now = q.top().second;
		q.pop();
		if (check[now]) continue;
		check[now] = true;

		for (auto e : p[now]) {
			if (e.used) continue;
			int next = e.to;
			int ncost = e.cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist;
}
void bfs(vector<int> &dist1, vector<int> &dist2, int now) {
	queue<int> q;
	vector<bool> check(n+1);
	q.push(now);
	check[now] = true;

	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (auto &e : ori[now]) {
			int next = e.to;
			int ncost = e.cost;
			if (dist1[now] + ncost + dist2[next] == dist1[d]) {
				e.used = true;
			}

			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m, n != 0) {
		cin >> s >> d;
		ori = rev = vector<vector<Edge>>(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			ori[u].emplace_back(v, c);
			rev[v].emplace_back(u, c);
		}
		vector<int> dist1 = dijkstra(ori, s);
		vector<int> dist2 = dijkstra(rev, d);
		bfs(dist1, dist2, s);
		dist1 = dijkstra(ori, s);

		if (dist1[d] == INF)
			cout << "-1\n";
		else
			cout << dist1[d] << '\n';
	}
}