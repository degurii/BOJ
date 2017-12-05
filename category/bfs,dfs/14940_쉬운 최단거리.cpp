/*
문제
지도가 주어지면 모든 지점에 대해서 목표지점까지의 거리를 구하여라.
문제를 쉽게 만들기 위해 오직 가로와 세로로만 움직일 수 있다고 하자.

입력
지도의 크기 n과 m이 주어진다. n은 세로의 크기, m은 가로의 크기다.(2≤n≤1000, 2≤m≤1000)
다음 n개의 줄에 m개의 숫자가 주어진다. 0은 갈 수 없는 땅이고 1은 갈 수 있는 땅, 2는 목표지점이다. 입력에서 2는 단 한개이다.

출력
각 지점에서 목표지점까지의 거리를 출력한다. 원래 벽인 위치는 0을 출력하고, 원래 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.
*/




/*
solution:
기본문제
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