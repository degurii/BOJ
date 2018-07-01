/*
문제
상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 한다. 상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 있다.
빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요하다.
상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있다.
상근이가 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.
각 테스트 케이스의 첫째 줄에는 지도의 높이와 너비 h와 w (2 ≤ h, w ≤ 100)가 주어진다.
다음 h개 줄에는 빌딩을 나타내는 w개의 문자가 주어지며, 각 문자는 다음 중 하나이다.

'.'는 빈 공간을 나타낸다.
'*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
'$'는 상근이가 훔쳐야하는 문서이다.
알파벳 대문자는 문을 나타낸다.
알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.
마지막 줄에는 상근이가 이미 가지고 있는 열쇠가 공백없이 주어진다. 만약, 열쇠를 하나도 가지고 있지 않는 경우에는 "0"이 주어진다.

상근이는 빌딩 밖으로 나갈 수 있다.
각각의 문에 대해서, 그 문을 열 수 잇는 열쇠의 개수는 0개, 1개, 또는 그 이상이고,
각각의 열쇠에 대해서, 그 열쇠로 열 수 있는 문의 개수도 0개, 1개, 또는 그 이상이다.
열쇠는 여러 번 사용할 수 있다.

출력
각 테스트 케이스 마다, 상근이가 훔칠 수 있는 문서의 최대 개수를 출력한다.
*/





/*
코드짜다 지침
ac받긴 했으나 나중에 다시 짜볼 예정

solution:
각 문마다 queue를 배정한다.
배열의 테두리에서 입구를 찾고
bfs를 돌리다가 열쇠가 없는 문을 찾으면
그 문의 queue에 좌표를 저장, 
일반 q의 bfs가 끝나면 열쇠가 있는 모든 문의 queue의 좌표를 일반 queue에 push
반복해서 일반 queue에 데이터가 없으면 종료한다


key체크는 bitmask를 이용
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#include <string>

int t;
int h, w, p[101][101], ky, ans;
bool check[101][101];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
queue<pair<int, int> > q, door[26];

void init1(int c) {
	for (int i = 1; i <= h; i++) {
		if (p[i][c] == -1)continue;
		
		check[i][c] = true;

		if (p[i][c] == 0) {
			q.push({ i, c });
		}
		else if (p[i][c] == 1) {
			ans++;
			q.push({ i, c });
		}
		else if ('A' <= p[i][c] && p[i][c] <= 'Z') {
			if (ky & (1 << (p[i][c] - 'A'))) 
				q.push({ i, c });
			else
				door[p[i][c] - 'A'].push({ i, c });
		}
		else if('a' <= p[i][c] && p[i][c] <= 'Z') {
			ky |= (1 << (p[i][c] - 'a'));
			q.push({ i, c });
		}
	}
}
void init2(int r) {
	for (int j = 2; j <= w - 1; j++) {
		if (p[r][j] == -1) continue;

		check[r][j] = true;
		if (p[r][j] == 0) {
			q.push({ r, j });
		}
		else if (p[r][j] == 1) {
			ans++;
			q.push({ r, j });
		}
		else if ('A' <= p[r][j] && p[r][j] <= 'Z') {
			if (ky & (1 << (p[r][j] - 'A')))
				q.push({ r, j });
			else
				door[p[r][j] - 'A'].push({ r, j });
		}
		else if ('a' <= p[r][j] && p[r][j] <= 'Z') {
			ky |= (1 << (p[r][j] - 'a'));
			q.push({ r, j });
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		queue<pair<int, int> > empty1, empty2[26];
		q = empty1;
		for (int i = 0; i < 26; i++)door[i] = empty2[i];
		h = w = ky = ans = 0;
		memset(p, 0, sizeof(p));
		memset(check, 0, sizeof(check));
		cin >> h >> w;
		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				char c;
				cin >> c;
				if (c == '*')
					p[i][j] = -1;
				else if (c == '$')
					p[i][j] = 1;
				else if (c == '.');
				else {
					p[i][j] = c;
				}
			}
		}
		string keyy;
		cin >> keyy;
		for (auto it : keyy) {
			ky |= (1 << (it - 'a'));
		}
		
		init1(1);
		init1(w);
		init2(1);
		init2(h);

		while (!q.empty()) {
			while (!q.empty()) {
				auto now = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = now.first + dx[i], ny = now.second + dy[i];
					if (0 < nx && nx <= h && 0 < ny && ny <= w) {
						if (p[nx][ny] == -1) continue;
						if (check[nx][ny] == false) {
							check[nx][ny] = true;
							int &next = p[nx][ny];
							if (next == 0) {
								q.push({ nx, ny });
							}
							else if (next == 1) {
								q.push({ nx, ny });
								ans++;
							}
							else if ('A' <= next && next <= 'Z') {
								if (ky & (1 << (p[nx][ny] - 'A'))) {
									q.push({ nx, ny });
								}
								else {
									door[next - 'A'].push({ nx, ny });
								}
							}
							else if ('a' <= next && next <= 'z') {
								ky |= (1 << (next - 'a'));
								q.push({ nx, ny });
							}
						}
					}
				}
			}

			for (int i = 0; i < 26; i++) {
				if (ky & (1 << i)) {
					while (!door[i].empty()) {
						q.push(door[i].front());
						door[i].pop();
					}
				}
			}
		}
		cout << ans << '\n';
	}
}