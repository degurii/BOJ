/*
문제
상근이는 감옥에서 죄수 두 명을 탈옥시켜야 한다. 이 감옥은 1층짜리 건물이고, 상근이는 방금 평면도를 얻었다.
평면도에는 모든 벽과 문이 나타나있고, 탈옥시켜야 하는 죄수의 위치도 나타나 있다. 감옥은 무인 감옥으로 죄수 두 명이 감옥에 있는 유일한 사람이다.
문은 중앙 제어실에서만 열 수 있다. 상근이는 특별한 기술을 이용해 제어실을 통하지 않고 문을 열려고 한다. 하지만, 문을 열려면 시간이 매우 많이 걸린다. 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.
첫째 줄에는 평면도의 높이 h와 너비 w가 주어진다. (2 ≤ h, w ≤ 100)
다음 h개 줄에는 감옥의 평면도 정보가 주어지며, 빈 공간은 '.', 지나갈 수 없는 벽은 '*', 문은 '#', 죄수의 위치는 '$'이다.
상근이는 감옥 밖을 자유롭게 이동할 수 있고, 평면도에 표시된 죄수의 수는 항상 두 명이다.
각 죄수와 감옥의 바깥을 연결하는 경로가 항상 존재하는 경우만 입력으로 주어진다.

출력
각 테스트 케이스마다 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 최소값을 출력한다.
*/

/*
solve:
bfs를 3번 돌리고 시작점부터 문을 연 개수를 저장한다
밖에서부터, 죄수1부터, 죄수2부터

ans = min(밖[i][j]+죄1[i][j]+죄2[i][j]) (0<=i<=h+1, 0<=j<=w+1)
단, 죄수가 문에서 만난다면
만나는 문이 세번 더해지기 때문에 2를 빼준다

**그냥 bfs를 돌리지 않고, 덱을 이용해 문을 적게 연 노드부터 방문하게 한다 **
** 최단거리를 찾는게 아니라 문을 가장 적게 여는게 포인트이기떄문 **

*/
#include <iostream>
using namespace std;
#include <queue>
#include <cstring>

int h, w, p[102][102], d1[102][102], d2[102][102], d[102][102];
//d: 밖에서부터 bfs
//d1: 죄수1 bfs
//d2: 죄수2 bfs
pair<int, int> s1, s2;
bool check[102][102];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

void bfs(int dd[][102], pair<int, int> s) {
	deque<pair<int, int> > q;
	memset(check, 0, sizeof(check));

	q.push_front(s);
	check[s.first][s.second] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i], ny = now.second + dy[i];
			if (0 <= nx && nx <= h + 1 && 0 <= ny && ny <= w + 1) {
				if (check[nx][ny] == false && p[nx][ny] >= 0) {
					check[nx][ny] = true;
					dd[nx][ny] = dd[now.first][now.second];
					if (p[nx][ny] == 1) {
						dd[nx][ny]++;
						q.push_back({ nx, ny });
					}
					else {
						q.push_front({ nx, ny });
					}
				}
			}
		}
	}
}
int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		s1 = s2 = { 0, 0 };
		h = w = 0;
		memset(p, 0, sizeof(p));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		memset(d, 0, sizeof(d));
		memset(check, 0, sizeof(check));

		cin >> h >> w;
		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				char c;
				cin >> c;
				if (c == '*') p[i][j] = -1;
				else if (c == '#') p[i][j] = 1;
				else if (c == '$') {
					if (s1.first)
						s2 = { i, j };
					else
						s1 = { i, j };
				}
			}
		}
		
		bfs(d, { 0, 0 });
		bfs(d1, s1);
		bfs(d2, s2);
		int ans = 0x3f3f3f3f;
		
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (p[i][j] == -1) continue;
				int a = d[i][j] + d1[i][j] + d2[i][j];
				if (p[i][j] == 1)
					a -= 2;
				ans = (ans < a) ? ans : a;
			}
		}
		cout << ans << '\n';
	}
}