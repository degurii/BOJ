/*
����
�������� �� �����ڸ����� ġ� ������ �ʴ� ������ �����Ѵ�.
�Է����� �־��� ġ� ��� �� �� �������µ� �ɸ��� ��Ȯ�� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �������� ũ�⸦ ��Ÿ���� �� ���� ���� N, M (5��N, M��100)�� �־�����.
�� ���� N �ٿ��� ������ ���� ���ڿ� ġ� �ִ� �κ��� 1�� ǥ�õ� ��, ġ� ���� �κ��� 0���� ǥ�õȴ�.
����, �� 0�� 1�� �ϳ��� �������� �и��Ǿ� �ִ�.

���
������δ� �־��� ġ� ��� ��� �������µ� �ɸ��� ��Ȯ�� �ð��� ������ ù �ٿ� ����Ѵ�.
*/


/*
solution:
���� ����� �����ؾ� �ϹǷ�
ġ��� bfs�� ������ �ʰ�
�ٱ� ���⿡������ bfs�� ������
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, p[101][101];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
bool check[101][101];

bool empty() {
	bool ok = true;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (p[i][j] != 0) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	return ok;
}
void bfs() {
	memset(check, 0, sizeof(check));
	queue<pair<int, int> > q;
	q.push({ 1, 1 });
	check[1][1] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 < nx && nx < n + 1 && 0 < ny && ny < m + 1) {
				if (p[nx][ny] == 1) {
					if (!check[nx][ny])
						check[nx][ny] = true;
					else
						p[nx][ny] = -1;
				}
				else if (p[nx][ny] == 0 && check[nx][ny] == false) {
					q.push({ nx, ny });
					check[nx][ny] = true;
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (p[i][j] == -1) p[i][j] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cin >> p[i][j];
		}
	}
	
	int ans = 0;
	for (; !empty(); ans++) {
		bfs();
	}
	cout << ans;
}