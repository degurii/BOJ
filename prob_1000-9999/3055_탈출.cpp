/*
����
����� ������ ���� �̹����� ���� ���� ������ �տ� �־���, �� �ɷ��� �����غ��� ���� ��ó�� Ƽ������ ȫ���� ����Ű���� �Ѵ�.
�� ������ ����ġ�� �� ���� ��� �ִ�. ����ġ�� ���� ģ�� ģ���� ����� ���� ������ ���� ������ ȫ���� ���Ϸ��� �Ѵ�.
Ƽ������ ������ R�� C���� �̷���� �ִ�. ����ִ� ���� '.'�� ǥ�õǾ� �ְ�, ���� ���ִ� ������ '*', ���� 'X'�� ǥ�õǾ� �ִ�.
����� ���� 'D'��, ����ġ�� ��ġ�� 'S'�� ��Ÿ������ �ִ�.
�� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ �� �ϳ��� �̵��� �� �ִ�.
(��, �Ʒ�, ������, ����) ���� �� �и��� ����ִ� ĭ���� Ȯ���Ѵ�. ���� �ִ� ĭ�� �������ִ� ����ִ� ĭ(��� �� ���� ����)�� ���� ���� �ȴ�.
���� ����ġ�� ���� ����� �� ����. ��, ����ġ�� ���� ���ִ� �������� �̵��� �� ����, ���� ����� �ұ��� �̵��� �� ����.
Ƽ������ ������ �־����� ��, ����ġ�� �����ϰ� ����� ���� �̵��ϱ� ���� �ʿ��� �ּ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����ġ�� ���� �� ������ ĭ���� �̵��� �� ����.
��, ���� �ð��� ���� �� ������ ĭ���� ����ġ�� �̵��� �� ����. �̵��� �� ������ ����ġ�� ���� ������ �����̴�.

�Է�
ù° �ٿ� 50���� �۰ų� ���� �ڿ��� R�� C�� �־�����.
���� R�� �ٿ��� Ƽ������ ������ �־�����, �������� ������ ���ڸ� �־�����. 'D'�� 'S'�� �ϳ����� �־�����.

���
ù° �ٿ� ����ġ�� ����� ���� �̵��� �� �ִ� ���� ���� �ð��� ����Ѵ�. ����, �����ϰ� ����� ���� �̵��� �� ���ٸ�, "KAKTUS"�� ����Ѵ�.
*/


/*
solution:
bfs�� �ι� ������
ù��° bfs���� ���� ���°�� ������ �迭�� ����,
�ι�° bfs���� ���� ã�´�

Ǯ���� ���� Node structure�� ������ �ʰ� level�� dist�� �ذ��ص� �ƾ��ٴ� ������ ���
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
// -3�� ������, -2�� ����, -1���ʹ� ���� ���� �ð�
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