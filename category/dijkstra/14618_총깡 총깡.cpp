/*
입력
입력의 첫번째 줄에 전체 집의 수 N과 집과 집사이를 연결하는 도로 M이 공백으로 주어진다.
(3≤N≤5,000, 3≤M≤20,000)
입력의 둘째 줄에 진서의 집 J가 주어진다 (1≤J≤N)
입력의 셋째 줄에 종류별 동물의 수 K가 주어진다. (2*K≤N)
입력의 넷째 줄에 K개의 A형 집이 공백으로 구분되어 주어진다.
입력의 다섯번째 줄에 K개의 B형 집이 공백으로 구분되어 주어진다.
이후 M개의 줄에 X Y Z(1≤X, Y≤N, 1≤Z≤100)가 주어진다. 이는 X번 집과 Y번 집 사이에 Z의 길이를 가지는 도로가 존재한다는 것이다.

출력
총깡총깡 뛰는 동물이 살게 될 집의 종류를 말한 뒤 다음줄에 거리를 출력한다.
( A형 집에서만 진서의 집에 갈 수 있는 경우 A를 출력한 뒤 다음 줄에 거리를 출력,
B형 집에서만 진서의 집에 갈 수 있는 경우 B를 출력한 뒤 다음 줄에 거리를 출력, A형 집, B형 집 둘다 진서의 집에 갈 수 없는 경우에는 –1을 출력한다. )
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
	int zip, dist;
	Node(int z = 0) :zip(-1), dist(0) {}
	bool operator < (const Node &o) {
		if (dist == o.dist)
			return zip < o.zip;
		return dist < o.dist;
	}
}d[5001];
struct Edge {
	int to, cost;
	Edge(int t = 0, int c = 0) :to(t), cost(c) {}
};
int n, m, j, k;
bool check[5001];
vector<vector<Edge>> p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> j >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		d[x].zip = 0;
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		d[x].zip = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		d[i].dist = INF;
	}
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		p[u].push_back(Edge(v, w));
		p[v].push_back(Edge(u, w));
	}
	
	priority_queue<pair<int, int>> q;
	d[j].dist = 0;
	q.push({ 0, j });

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();
		if (check[now]) continue;
		check[now] = true;
		for (auto e : p[now]) {
			int next = e.to;
			int ncost = e.cost;
			if (d[next].dist > d[now].dist + ncost) {
				d[next].dist = d[now].dist + ncost;
				q.push({ -d[next].dist, next });
			}
		}
	}
	sort(d + 1, d + n + 1);
	for (int i = 1; i < n + 1; i++) {
		if (d[i].zip >= 0) {
			if (d[i].dist == INF) {
				cout << -1;
				return 0;
			}
			else {
				cout << (char)('A' + d[i].zip) << '\n' << d[i].dist;
				return 0;
			}
		}
	}
	cout << -1;
}