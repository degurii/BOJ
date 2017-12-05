/*
����
������ �־����� ��� ������ ���ؼ� ��ǥ���������� �Ÿ��� ���Ͽ���.
������ ���� ����� ���� ���� ���ο� ���ηθ� ������ �� �ִٰ� ����.

�Է�
������ ũ�� n�� m�� �־�����. n�� ������ ũ��, m�� ������ ũ���.(2��n��1000, 2��m��1000)
���� n���� �ٿ� m���� ���ڰ� �־�����. 0�� �� �� ���� ���̰� 1�� �� �� �ִ� ��, 2�� ��ǥ�����̴�. �Է¿��� 2�� �� �Ѱ��̴�.

���
�� �������� ��ǥ���������� �Ÿ��� ����Ѵ�. ���� ���� ��ġ�� 0�� ����ϰ�, ���� ���� �κ� �߿��� ������ �� ���� ��ġ�� -1�� ����Ѵ�.
*/




/*
solution:
�⺻����
*/
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
#include <queue>

int n, m, p[1001][1001], d[1001][1001];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
bool check[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int sx, sy;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			cin >> p[i][j];
			if (p[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}

	queue<pair<int, int> > q;
	q.push({ sx, sy });
	check[sx][sy] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i], ny = now.second + dy[i];
			if (0 < nx&& nx <= n && 0 < ny && ny <= m) {
				if (check[nx][ny] == false && p[nx][ny] != 0) {
					check[nx][ny] = true;
					d[nx][ny] = d[now.first][now.second] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (d[i][j] == 0 && p[i][j] == 1)
				cout << -1 << ' ';
			else
				cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}