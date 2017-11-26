/*
����
����̴� �������� �˼� �� ���� Ż�����Ѿ� �Ѵ�. �� ������ 1��¥�� �ǹ��̰�, ����̴� ��� ��鵵�� �����.
��鵵���� ��� ���� ���� ��Ÿ���ְ�, Ż�����Ѿ� �ϴ� �˼��� ��ġ�� ��Ÿ�� �ִ�. ������ ���� �������� �˼� �� ���� ������ �ִ� ������ ����̴�.
���� �߾� ����ǿ����� �� �� �ִ�. ����̴� Ư���� ����� �̿��� ������� ������ �ʰ� ���� ������ �Ѵ�. ������, ���� ������ �ð��� �ſ� ���� �ɸ���. �� �˼��� Ż����Ű�� ���ؼ� ����� �ϴ� ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� ���� 100���� ���� �ʴ´�.
ù° �ٿ��� ��鵵�� ���� h�� �ʺ� w�� �־�����. (2 �� h, w �� 100)
���� h�� �ٿ��� ������ ��鵵 ������ �־�����, �� ������ '.', ������ �� ���� ���� '*', ���� '#', �˼��� ��ġ�� '$'�̴�.
����̴� ���� ���� �����Ӱ� �̵��� �� �ְ�, ��鵵�� ǥ�õ� �˼��� ���� �׻� �� ���̴�.
�� �˼��� ������ �ٱ��� �����ϴ� ��ΰ� �׻� �����ϴ� ��츸 �Է����� �־�����.

���
�� �׽�Ʈ ���̽����� �� �˼��� Ż����Ű�� ���ؼ� ����� �ϴ� ���� �ּҰ��� ����Ѵ�.
*/

/*
solve:
bfs�� 3�� ������ ���������� ���� �� ������ �����Ѵ�
�ۿ�������, �˼�1����, �˼�2����

ans = min(��[i][j]+��1[i][j]+��2[i][j]) (0<=i<=h+1, 0<=j<=w+1)
��, �˼��� ������ �����ٸ�
������ ���� ���� �������� ������ 2�� ���ش�

**�׳� bfs�� ������ �ʰ�, ���� �̿��� ���� ���� �� ������ �湮�ϰ� �Ѵ� **
** �ִܰŸ��� ã�°� �ƴ϶� ���� ���� ���� ���°� ����Ʈ�̱⋚�� **

*/
#include <iostream>
using namespace std;
#include <queue>
#include <cstring>

int h, w, p[102][102], d1[102][102], d2[102][102], d[102][102];
//d: �ۿ������� bfs
//d1: �˼�1 bfs
//d2: �˼�2 bfs
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