/*
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 꼭지점끼리 연결되어 있어야 한다. 즉, 변과 꼭지점이 맞닿아있으면 안된다.
5가지가 있다.

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 써 있다.
테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
둘째 줄부터 N개의 줄에 종이에 써 있는 수가 주어진다.
i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 써 있는 수이다.
입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/





/*
solution:
어떤 칸부터 4칸째까지 dfs를 돌리면 ㅜ 모양을 제외한 모든 모양이 나온다.
ㅜ모양은 따로 처리한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p[501][501];
bool check[501][501];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int dfs(int x, int y, int dist, int cnt) {
	if (cnt == 3) return dist;
	check[x][y] = true;
	int d = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if(check[nx][ny] == false)
				d = max(d, dfs(nx, ny, dist + p[nx][ny], cnt + 1));
		}
	}
	check[x][y] = false;
	return d;
}

pair<int, int> t[4][4] = {
	{{0, 0}, {1, 0}, {1, 1}, {2, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {1, -1}, {2, 0}}
};
int foo(int x, int y) {
	int dist = 0;
	for (int i = 0; i < 4; i++) {
		int cur = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + t[i][j].first;
			int ny = y + t[i][j].second;
			if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) {
				cur = 0;
				break;
			}
			cur += p[nx][ny];
		}
		dist = max(dist, cur);
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, dfs(i, j, p[i][j], 0));
			ans = max(ans, foo(i, j));
		}
	}
	cout << ans;
}