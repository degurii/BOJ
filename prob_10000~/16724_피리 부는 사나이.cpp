/*
입력
첫 번째 줄에 지도의 행의 수를 나타내는 N(1 ≤ N ≤ 1,000)과 지도의 열의 수를 나타내는 M(1 ≤ M ≤ 1,000)이 주어진다.
두 번째 줄부터 N개의 줄에 지도의 정보를 나타내는 길이가 M인 문자열이 주어진다.
지도 밖으로 나가는 방향의 입력은 주어지지 않는다.

출력
첫 번째 줄에 ‘SAFE ZONE’의 최소 개수를 출력한다.
*/
#include <iostream>
using namespace std;

char dtoi[200];
int p[1001][1001], chk[1001][1001], n, m;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int dfs(int x, int y, int lev) {
	if (chk[x][y]) return chk[x][y];
	chk[x][y] = lev;
	return chk[x][y] = dfs(x + dx[p[x][y]], y + dy[p[x][y]], lev);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	dtoi['R'] = 0; dtoi['D'] = 1; dtoi['L'] = 2; dtoi['U'] = 3;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			p[i][j] = dtoi[x];
		}
	}
	int ans = 0, lev = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = dfs(i, j, lev); 
			if (x == lev) lev++;
		}
	}
	cout << lev - 1;
}
