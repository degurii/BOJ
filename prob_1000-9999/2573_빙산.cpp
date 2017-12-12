/*
입력
첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다.
N과 M은 3 이상 300 이하이다.
그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다.
각 칸에 들어가는 값은 0 이상 10 이하이다.
배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다.
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

출력
첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다.
만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
*/





/*
solution:
두개 이상의 컴포넌트가 생길 때까지 땅을 기준으로 bfs를 돌린다.
bfs를 돌리면서 현재노드의 상하좌우에 바다가 있다면 각각 값을 빼준다.


땅을 기준으로 해도 되고 바다를 기준으로 해도 되는데,
땅이 갈수록 적어지므로 땅을 기준으로 한다.
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