/*
문제
홍익이는 사악한 마법사의 꾐에 속아 N x M 미로 (Hx, Hy) 위치에 떨어졌다.
다행히도 홍익이는 마법사가 만든 미로의 탈출 위치(Ex, Ey)를 알고 있다.
하지만 미로에는 곳곳에 마법사가 설치한 벽이 있어 홍익이가 탈출하기 어렵게 하고 있다.
홍익이는 마법사의 연구실에서 훔친 지팡이가 있어, 벽을 길로 만들 수 있다. 
렇지만, 안타깝게도 마법의 지팡이는 단 한 번만 사용할 수 있다.
이 때, 홍익이를 도와 미로에서 탈출할 수 있는지 알아보고, 할 수 있다면 가장 빠른 경로의 거리 D는 얼마인지 알아보자.

입력
N M
Hx Hy
Ex Ey
N X M 행렬
0 <= N <= 1000, 0 <= M <= 1000
1 <= Hx, Hy, Ex, Ey <= 1000
Hx ≠ Ex, Hy ≠ Ey
출력
D (탈출 할 수 없다면, -1을 출력한다.)
*/




/*
solution:
2206번 벽부수고이동하기와 같은 문제
조건만 문제에 맞게 적당히 바꿔준다
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