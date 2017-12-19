/*
����
N���� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� ������ M�� �ִ�.
�� ������ A, B, C�� ��Ÿ�� �� �ִµ�, A�� ���۵���, B�� ��������, C�� ������ Ÿ�� �̵��ϴµ� �ɸ��� �ð��̴�.
�ð� C�� ����� �ƴ� ��찡 �ִ�. C = 0�� ���� ���� �̵��� �ϴ� ���, C < 0�� ���� Ÿ�Ӹӽ����� �ð��� �ǵ��ư��� ����̴�.
1�� ���ÿ��� ����ؼ� ������ ���÷� ���� ���� ���� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 500), ���� �뼱�� ���� M (1 �� M �� 6,000)�� �־�����.
��° �ٺ��� M���� �ٿ��� ���� �뼱�� ���� A, B, C (1 �� A, B �� N, -10,000 �� C �� 10,000)�� �־�����.

���
ù° �ٿ��� 2�� ���ñ��� ���� ���� ���� �ð�, ..., N-1��° �ٿ��� N�� ���ñ��� ���� ���� ���� �ð��� ����Ѵ�.
� ���÷� ���� ���� ���� �ð��� ���� ��쿡�� -1�� ����Ѵ�.
����, ���������� ���� ������ Ÿ�Ӹӽ����� �Ǿ��ִ� ����Ŭ�� ������ 1�� ���ÿ��� ������ ���÷� ���� ���� ���� �ð��� �������� �ʴ� ��쿡�� -1�� ����Ѵ�.
*/





/*
solution:
�⺻ ����-���� �˰��� ����
*/
#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;

int n, m;
struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) :u(u), v(v), w(w) {}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<int> dist(n + 1, inf);
	vector<Edge> p;
	dist[1] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		p.push_back(Edge(u, v, w));
	}
	bool cycle = false;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			Edge e = p[j];
			if (dist[e.v] > dist[e.u] + e.w) {
				dist[e.v] = dist[e.u] + e.w;
				if (i == n) {
					cycle = true;
					break;
				}
			}
		}
	}
	if (cycle) {
		cout << -1;
		return 0;
	}
	for (int i = 2; i < n + 1; i++) {
		if (dist[i] == inf) cout << -1;
		else cout << dist[i];
		cout << '\n';
	}
}