/*
입력
첫 번째 줄에 성원이의 현재 위치 좌표 (Xs, Ys)를 나타내는 정수 2개가 주어진다.
두 번째 줄에 성원이가 더위를 버틸 수 있는 시간 T(1 ≤ T ≤ 200)가 주어진다.
세 번째 줄에 집의 위치 좌표 (Xh, Yh)를 나타내는 정수 2개가 주어진다.
네 번째 줄에 장애물의 개수 N(0 ≤ N ≤ 100,000)이 주어진다.
그 이후 N개의 줄에 걸쳐 각 줄에 장애물의 위치 좌표 (Xi, Yi)를 나타내는 정수 2개가 주어진다.

주어지는 모든 좌표는 -100,000 이상 100,000 이하의 정수이며 미터 단위이다. 또한 주어지는 모든 좌표의 위치는 서로 다르다.

출력
첫 번째 줄에 성원이가 T초 이내에 집에 도착하는 경우의 수를 109+7로 나눈 나머지를 출력한다.
*/
#include <iostream>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int sx, sy, ex, ey, _time, n;
ll d[401][401][201];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
map<pair<int, int>, bool> p;

ll go(int x, int y, int sec) {
	int rx = sx + x, ry = sy + y;
	if (rx == ex && ry == ey) return 1;
	if (abs(ex - rx) + abs(ey - ry) > _time - sec) return 0;
	if (sec == _time) return 0;

	ll &val = d[x + 200][y + 200][sec];
	if (val != -1) return val;
	val = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		rx = sx + nx, ry = sy + ny;
		if (!p[{rx, ry}])
			val = (val + go(nx, ny, sec + 1) % MOD) % MOD;
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(d, -1, sizeof(d));
	cin >> sx >> sy >> _time >> ex >> ey >> n;
	sx += 100000;
	sy += 100000;
	ex += 100000;
	ey += 100000;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		x += 100000;
		y += 100000;
		p[{x, y}] = true;
	}
	cout << go(0, 0, 0) % MOD;
}