/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이 때 최단 경로로 이동하려 한다.
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이 때 시작하는 칸과 끝나는 칸도 포함해서 센다.
만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.
맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤1,000), M(1≤M≤1,000)이 주어진다.
다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/
/*
벽을 부순상태, 안부순상태로 나눈다
안부순상태 -> 안부수고 0으로, 부수고 1로 가능
부순상태 -> 안부수고 0으로만 가능
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m, p[1001][1001], dist[1001][1001][2];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
struct Node {
	int x, y, b;
	Node(int x, int y, int b) :x(x), y(y), b(b) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			char c;
			cin >> c;
			p[i][j] = c - '0';
		}
	}
	queue<Node> q;
	q.push(Node(1, 1, 0));
	dist[1][1][0] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i], b = now.b;
			if (0 < nx && nx <= n && 0 < ny && ny <= m) {
				if (p[nx][ny] == 0 && dist[nx][ny][b] == 0) {
					q.push(Node(nx, ny, b));
					dist[nx][ny][b] = dist[now.x][now.y][b] + 1;
				}
				if (b == 0 && p[nx][ny] == 1 && dist[nx][ny][1] == 0) {
					dist[nx][ny][1] = dist[now.x][now.y][0] + 1;
					q.push(Node(nx, ny, 1));
				}
			}
		}
	}
	int ans = 0;
	int &d1 = dist[n][m][0], &d2 = dist[n][m][1];
	
	if (d1 == 0 && d2 == 0) {
		ans = -1;
	}
	else if (d1 != 0 && d2 != 0) {
		ans = (d1 < d2) ? d1 : d2;
	}
	else if (!d2) {
		ans = d1;
	}
	else if (!d1) {
		ans = d2;
	}
	cout << ans;
}