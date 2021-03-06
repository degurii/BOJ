/*
여러분은 입력 데이터에 표시된 도로망을 읽고, 류원룡이 한 도로를 막고 검색함으로써 지연시킬 수 있는 최대시간을 정수로 출력하여야한다.
만일 지연효과가 없으면 0을 출력해야하고, 도시를 빠져나가지 못하게 만들 수 있으면(지연시간이 무한대) -1을 출력해야 한다.

입력
첫 줄에는 지점의 수를 나타내는 정수  N(6<=N<=1000)과 도로의 수 M(6<=M<=5000)이 주어진다.
그 다음 이어 나오는 M개의 각 줄에는 도로(a,b)와 그 통과시간 t가 a b t 로 표시된다. 단 이 경우 a < b 이고 1<=t<=10000이다.

출력
경찰이 하나의 도로를 막음으로써 지연시킬 수 있는 최대 시간을 정수로 출력한다. (단, 그 지연시간이 무한대이면 -1을 출력해야 한다.)
*/



/*
solution:
다익스트라의 시간복잡도가 O(ElogV)이므로
각 간선을 한번식 제외시키면서 다익스트라를 돌리면
O(E^2 logV)로 제한시간안에 가능하다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

struct Edge {
	int v, c;
	Edge(int v = 0, int c = 0) :v(v), c(c) {}
};
int n, m;
vector<vector<Edge> > p;
vector<pair<int, int> > edge;

int dijkstra(int u, int v) {
	vector<int> dist(n + 1, INF);
	vector<bool> check(n + 1);
	
	dist[1] = 0;
	priority_queue<pair<int, int> > q;
	q.push({ 0, 1 });
	while (!q.empty()) {
		int now = q.top().second;
		q.pop();

		if (check[now]) continue;
		check[now] = true;
		
		for (auto it : p[now]) {
			int next = it.v;
			int ncost = it.c;
			if ((now == u && next == v) || (now == v && next == u))
				continue;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		p[u].push_back(Edge(v, c));
		p[v].push_back(Edge(u, c));
		edge.push_back({ u, v });
	}

	
	int mind = dijkstra(-1, -1);
	int x = -0x3f3f3f3f;
	for (auto it : edge) {
		x = max(x, dijkstra(it.first, it.second));
	}
	if (x == INF) {
		cout << -1;
	}
	else if (x - mind < 0) {
		cout << 0;
	}
	else {
		cout << x - mind;
	}
}