/*
이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라.
모든 컴퓨터를 연결할 수 없는 경우는 없다.

입력
첫째 줄에 컴퓨터의 수(1<=N<=1000)가 주어진다.
둘째 줄에는 연결할 수 있는 선의 수(1<=M<=100,000)가 주어진다.
셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다.
이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c만큼 든다는 것을 의미한다.

출력
모든 컴퓨터를 연결하는데 필요한 최소비용을 첫째 줄에 출력한다.
*/




/*
solution:
기초적인 mst문제이다
kruskal 사용함
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m;
struct Edge {
	int u, v, w;
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}
	bool operator < (const Edge &e)const {
		return (w > e.w);
	}
};
int p[1001];
int Find(int x) {
	if (x == p[x])
		return x;
	else {
		return p[x] = Find(p[x]);
	}
}
void Union(int x, int y) {
	p[Find(x)] = Find(y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)p[i] = i;
	priority_queue<Edge> pq;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push(Edge(u, v, w));
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		Edge e = Edge(0, 0, 0);
		int r1, r2;
		do {
			e = pq.top();
			pq.pop();
			r1 = Find(e.u);
			r2 = Find(e.v);
		} while (r1 == r2);
		Union(r1, r2);
		ans += e.w;
	}
	cout << ans;
}