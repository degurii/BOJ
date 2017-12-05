/*
지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.

입력
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다.
그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다.

출력
첫째 줄에 가장 짧은 다리의 길이를 출력한다.
*/





/*
solution:
대륙마다 그룹으로 구분하고, 번호를 붙인다.
모든 땅을 queue에 넣고 확장시키면서 grouping을 하고, 땅으로부터 거리를 저장한다
인접한 노드와 다른 그룹이면서 거리의 합이 최소인 답을 찾는다.
*/
#include <iostream>
#include <queue>
using namespace std;
#include <cstring>

int ori[101][101], group[101][101], dist[101][101];
int n;
bool check[101][101];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
void bfs(int x, int y, int g) {
	check[x][y] = true;
	queue<pair<int, int> > q;
	q.push({ x, y });
	group[x][y] = g;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x, ny = dy[i] + y;
			if (0 < nx && nx <= n && 0 < ny && ny <= n) {
				if (check[nx][ny] == false && ori[nx][ny] == 1) {
					group[nx][ny] = g;
					check[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> ori[i][j];
		}
	}
	
	int gnum = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (check[i][j] == false) {
				bfs(i, j, ++gnum);
			}
		}
	}
	memset(check, 0, sizeof(check));
	queue<pair<int, int> > q;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (ori[i][j] == 1) {
				check[i][j] = true;
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (0 < nx && nx <= n && 0 < ny && ny <= n) {
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					group[nx][ny] = group[x][y];
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = dx[k] + i;
				int ny = dy[k] + j;
				if (0 < nx && nx <= n && 0 < ny && ny <= n) {
					if (group[i][j] != group[nx][ny] && ans > dist[i][j] + dist[nx][ny])
						ans = dist[i][j] + dist[nx][ny];
				}
			}
		}
	}
	cout << ans;
}