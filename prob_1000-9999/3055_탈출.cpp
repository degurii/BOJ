/*
문제
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다.
이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.
티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다.
비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.
매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다.
(위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다.
물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.
티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.
고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다.
즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다.

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.
다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.
*/


/*
solution:
bfs를 두번 돌린다
첫번째 bfs에서 물이 몇분째에 차는지 배열에 저장,
두번째 bfs에서 답을 찾는다

풀고나니 굳이 Node structure를 만들지 않고 level을 dist로 해결해도 됐었다는 생각이 든다
*/
#include <iostream>
using namespace std;
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f

int r, c, p[51][51], dist[51][51];
int dx[] = { 0, 1, 0 , -1 }, dy[] = { 1, 0, -1, 0 };
bool check[51][51];
struct Node {
	int x, y, level;
	Node(int x, int y, int l) :x(x), y(y), level(l) {}
};
// -3은 도착지, -2는 바위, -1부터는 물이 차는 시간
int main() {
	cin >> r >> c;
	fill(&p[0][0], &p[0][0] + 51 * 51, INF);
	queue<Node> q;
	pair<int, int> start, end;
	for (int i = 1; i < r + 1; i++) {
		for (int j = 1; j < c + 1; j++) {
			char c;
			cin >> c;
			if (c == 'S') {
				start = { i, j };
			}
			else if (c == 'D') {
				p[i][j] = -3;
				end = { i, j };
			}
			else if (c == '*') {
				q.push(Node(i, j, -1));
				check[i][j] = true;
			}
			else if(c == 'X'){
				p[i][j] = -2;
			}
		}
	}
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		p[now.x][now.y] = now.level;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i];
			if (0 < nx && nx <= r && 0 < ny && ny <= c) {
				if (check[nx][ny] == false && p[nx][ny] == INF) {
					check[nx][ny] = true;
					q.push(Node(nx, ny, now.level + 1));
				}
			}
		}
	}
	memset(check, 0, sizeof(check));
	q.push(Node(start.first, start.second, 0));
	check[start.first][start.second] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (p[now.x][now.y] == -3) break;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i];
			if (0 < nx && nx <= r && 0 < ny && ny <= c) {
				if (check[nx][ny] == false && (p[nx][ny] > now.level || p[nx][ny] == -3)) {
					check[nx][ny] = true;
					dist[nx][ny] = dist[now.x][now.y] + 1;
					q.push(Node(nx, ny, now.level + 1));
				}
			}
		}
	}
	if (dist[end.first][end.second] == 0) cout << "KAKTUS";
	else cout << dist[end.first][end.second];
}