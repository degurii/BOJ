/*
입력
첫째 줄에 정보섬 2층의 크기 n과 m이 주어진다. (1 ≤ n,m ≤ 3000, 4 ≤ n×m ≤ 9×10^6)
이후 n행 m열에 걸쳐 0, 1, 2, 3, 4, 5로만 구성된 Ai,j가 주어진다. Ai,j와 Ai,j+1사이에 공백은 주어지지 않는다.
2, 3, 4, 5는 반드시 하나씩 존재하며 2, 3, 4, 5가 아닌 나머지는 0 또는 1이다.

출력
첫째 줄에 "TAK"(폴란드어로 YES를 의미)을 출력하고, 둘째 줄에 현위치에서 가장 빨리 도착할 수 있는 음식까지의 최단 거리를 출력한다.
아무 음식도 먹을 수 없으면 "NIE"(폴란드어로 NO를 의미)를 출력한다. 이외의 출력은 하지 않는다.
TAK과 NIE를 출력할 때 따옴표는 출력하지 않으며 반드시 대문자로 출력한다.
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int p[4000][4000], dist[4000][4000];
bool chk[4000][4000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	queue<pair<int, int>> q;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			p[i][j] = s[j]-'0';
			if (p[i][j] == 2) q.push({ i, j }), chk[i][j] = true;
		}
	}

	
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (p[x][y] > 2) {
			cout << "TAK\n" << dist[x][y];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];	
			if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
			if (p[nx][ny] == 1 || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	cout << "NIE";
}