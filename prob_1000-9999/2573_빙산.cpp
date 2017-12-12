/*
�Է�
ù �ٿ��� ������ �迭�� ���� ������ ���� ������ ��Ÿ���� �� ���� N�� M�� �� ���� ��ĭ�� ���̿� �ΰ� �־�����.
N�� M�� 3 �̻� 300 �����̴�.
�� ���� N���� �ٿ��� �� �ٸ��� �迭�� �� ���� ��Ÿ���� M���� ������ �� ���� �� ĭ�� ���̿� �ΰ� �־�����.
�� ĭ�� ���� ���� 0 �̻� 10 �����̴�.
�迭���� ������ �����ϴ� ĭ�� ����, ��, 1 �̻��� ������ ���� ĭ�� ������ 10,000 �� �����̴�.
�迭�� ù ��° ��� ��, ������ ��� ������ �׻� 0���� ä������.

���
ù �ٿ� ������ �и��Ǵ� ������ �ð�(��)�� ����Ѵ�.
���� ������ �� ���� ������ �и����� ������ 0�� ����Ѵ�.
*/





/*
solution:
�ΰ� �̻��� ������Ʈ�� ���� ������ ���� �������� bfs�� ������.
bfs�� �����鼭 �������� �����¿쿡 �ٴٰ� �ִٸ� ���� ���� ���ش�.


���� �������� �ص� �ǰ� �ٴٸ� �������� �ص� �Ǵµ�,
���� ������ �������Ƿ� ���� �������� �Ѵ�.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int p[301][301];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
bool check[301][301];

bool component() {
	memset(check, 0, sizeof(check));
	bool ok = false;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (check[i][j] == false && p[i][j] > 0) {
				if (ok) return ok;
				else ok = true;

				queue<pair<int, int> > q;
				q.push({ i, j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = dx[i] + x;
						int ny = dy[i] + y;
						if (0 < nx && nx <= n && 0 < ny && ny <= m) {
							if (check[nx][ny] == false && p[nx][ny] > 0) {
								check[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			int x;
			cin >> x;
			if (x == 0)p[i][j] = -1;
			else p[i][j] = x;
		}
	}
	int ans = 0;
	while (!component()) {
		ans++;
		memset(check, 0, sizeof(check));
		queue<pair<int, int> > q;
		
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (p[i][j] > 0) {
					check[i][j] = true;
					q.push({ i, j });
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 < nx && nx <= n && 0 < ny && ny <= m) {
					if (p[nx][ny] < 0) {
						if (p[x][y] > 0)
							p[x][y]--;
					}
					else if (p[nx][ny] > 0 && check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}
		bool k = false;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (p[i][j] == 0)p[i][j] = -1;
				else if (p[i][j] > 0)k = true;
			}
		}
		if (!k) {
			cout << 0;
			return 0;
		}
	}
	cout << ans;
}