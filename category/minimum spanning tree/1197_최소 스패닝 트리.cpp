/*
문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1≤V≤10,000)와 간선의 개수 E(1≤E≤100,000)가 주어진다.
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다.
C는 음수일 수도 있으며, 절대값이 1,000,000을 넘지 않는다.

출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.
*/




/*
solution:

기초 mst문제
kruskal이나 prim이용
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include <functional>

int n, m;
struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w= 0) :u(u), v(v), w(w) {}
	bool operator < (const Edge& e) const{
		return (w > e.w);
	}
};
int p[10001];
int Find(int x) {
	if (x == p[x])
		return x;
	else {
		return p[x] = Find(p[x]);
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		p[i] = i;
	}
	priority_queue<Edge> pq;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push(Edge(u, v, w));
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		hi:
		Edge e = pq.top();
		pq.pop();

		int u = Find(e.u);
		int v = Find(e.v);
		if (u == v) goto hi;
		
		ans += e.w;
		Union(u, v);
	}
	cout << ans;
}