/*
����
ȫ���̴� ����� �������� �տ� �Ӿ� N x M �̷� (Hx, Hy) ��ġ�� ��������.
�������� ȫ���̴� �����簡 ���� �̷��� Ż�� ��ġ(Ex, Ey)�� �˰� �ִ�.
������ �̷ο��� ������ �����簡 ��ġ�� ���� �־� ȫ���̰� Ż���ϱ� ��ư� �ϰ� �ִ�.
ȫ���̴� �������� �����ǿ��� ��ģ �����̰� �־�, ���� ��� ���� �� �ִ�. 
������, ��Ÿ���Ե� ������ �����̴� �� �� ���� ����� �� �ִ�.
�� ��, ȫ���̸� ���� �̷ο��� Ż���� �� �ִ��� �˾ƺ���, �� �� �ִٸ� ���� ���� ����� �Ÿ� D�� ������ �˾ƺ���.

�Է�
N M
Hx Hy
Ex Ey
N X M ���
0 <= N <= 1000, 0 <= M <= 1000
1 <= Hx, Hy, Ex, Ey <= 1000
Hx �� Ex, Hy �� Ey
���
D (Ż�� �� �� ���ٸ�, -1�� ����Ѵ�.)
*/




/*
solution:
2206�� ���μ����̵��ϱ�� ���� ����
���Ǹ� ������ �°� ������ �ٲ��ش�
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m, p[1002][1002], dist[1002][1002][2];
int sx, sy, ex, ey;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
struct Node {
	int x, y, b;
	Node(int x, int y, int b) :x(x), y(y), b(b) {}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> sx >> sy >> ex >> ey;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cin >> p[i][j];
		}
	}
	dist[sx][sy][0] = 1;
	queue<Node> q;
	q.push(Node(sx, sy, 0));
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int x = now.x;
		int y = now.y;
		int b = now.b;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 < nx && nx <= n && 0 < ny && ny <= m) {
				if (p[nx][ny] == 0 && dist[nx][ny][b] == 0) {
					dist[nx][ny][b] = dist[x][y][b] + 1;
					q.push(Node(nx, ny, b));
				}
				if (b == 0 && p[nx][ny] == 1 && dist[nx][ny][1] == 0) {
					dist[nx][ny][1] = dist[x][y][0] + 1;
					q.push(Node(nx, ny, 1));
				}
			}
		}
	}
	
	int &d1 = dist[ex][ey][0], &d2 = dist[ex][ey][1];
	int ans = 0;
	if (d1 != 0 && d2 != 0) {
		ans = (d1 < d2) ? d1 : d2;
	}
	else if (d1) {
		ans = d1;
	}
	else if (d2) {
		ans = d2;
	}
	cout << ans - 1;
}