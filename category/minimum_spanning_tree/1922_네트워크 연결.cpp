/*
���� �� ��ǻ�͸� �����ϴµ� �ʿ��� ����� �־����� �� ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ����϶�.
��� ��ǻ�͸� ������ �� ���� ���� ����.

�Է�
ù° �ٿ� ��ǻ���� ��(1<=N<=1000)�� �־�����.
��° �ٿ��� ������ �� �ִ� ���� ��(1<=M<=100,000)�� �־�����.
��° �ٺ��� M+2��° �ٱ��� �� M���� �ٿ� �� ��ǻ�͸� �����ϴµ� ��� ����� �־�����.
�� ����� ������ �� ���� ������ �־����µ�, ���࿡ a b c �� �־��� �ִٰ� �ϸ� a��ǻ�Ϳ� b��ǻ�͸� �����ϴµ� ����� c��ŭ ��ٴ� ���� �ǹ��Ѵ�.

���
��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ù° �ٿ� ����Ѵ�.
*/




/*
solution:
�������� mst�����̴�
kruskal �����
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