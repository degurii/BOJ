/*
����
�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿��� �� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.

�Է�
ù° �ٿ� ������ ���� V(1��V��10,000)�� ������ ���� E(1��E��100,000)�� �־�����.
���� E���� �ٿ��� �� ������ ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����.
�̴� A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ� �ִٴ� �ǹ��̴�.
C�� ������ ���� ������, ���밪�� 1,000,000�� ���� �ʴ´�.

���
ù° �ٿ� �ּ� ���д� Ʈ���� ����ġ�� ����Ѵ�.
*/




/*
solution:

���� mst����
kruskal�̳� prim�̿�
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