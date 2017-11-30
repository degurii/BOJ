/*
����
�����̰� ���� �� �ִ� �������� �ִ� ������ �˷�����.

�Է�
ù° �ٿ��� ������ ���� n (1 �� n �� 100)�� �������� �������� m (1 �� m �� 15), ���� ���� r (1 �� r �� 100)�� �־�����.
��° �ٿ��� n���� ���ڰ� ���ʴ��  �� ������ �ִ� �������� �� t (1 �� t �� 30)�� �˷��ش�.
����° �ٺ��� r+2��° �� ���� �� �� ���� �����ϴ� ������ ��ȣ a, b, �׸��� ���� ���� l (1 �� l �� 15)�� �־�����.

���
�����̰� ���� �� �ִ� �ִ� ������ ������ ����Ѵ�.
*/








/*
solve:
ó���� �ܼ� bfs�� ��� ��忡�� ������ -> Ʋ�ȴ�
�� �� �����غ���, ��� ��忡�� ����������ŭ ���� ���д�Ʈ���� ���� -> Ʋ�ȴ�
�������̽� ��� ���� ��, ��� �ؾ��ϳ� �����غ�
-> n������ 100�̹Ƿ� floyd-warshall�� ���� ���ؼ� �ϳ��ϳ� ���غ��� �Ǵ°ſ���
���� �׷������� �ʹ� ���ѵ���
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n, m, r;
int d[101][101], items[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> m;
	for (int i = 1; i < n + 1; i++)
		cin >> items[i];
	fill(&d[0][0], &d[0][0] + 101 * 101, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (d[u][v]) {
			d[u][v] = min(d[u][v], w);
			d[v][u] = min(d[v][u], w);
		}
		else {
			d[u][v] = w;
			d[v][u] = w;
		}
	}
	for (int i = 1; i < n + 1; i++)d[i][i] = 0;
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = 0;
	
	for (int u = 1; u < n + 1; u++) {
		int res = 0;
		for (int v = 1; v < n + 1; v++) {
			if (d[u][v] <= r)
				res += items[v];
		}
		ans = max(ans, res);
	}
	cout << ans;
}