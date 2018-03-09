/*
문제
모눈종이의 맨 가장자리에는 치즈가 놓이지 않는 것으로 가정한다.
입력으로 주어진 치즈가 모두 녹 아 없어지는데 걸리는 정확한 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 모눈종이의 크기를 나타내는 두 개의 정수 N, M (5≤N, M≤100)이 주어진다.
그 다음 N 줄에는 모눈종이 위의 격자에 치즈가 있는 부분은 1로 표시되 고, 치즈가 없는 부분은 0으로 표시된다.
또한, 각 0과 1은 하나의 공백으로 분리되어 있다.

출력
출력으로는 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 정수로 첫 줄에 출력한다.
*/


/*
solution:
내부 공기는 무시해야 하므로
치즈에서 bfs를 돌리지 않고
바깥 공기에서부터 bfs를 돌린다
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