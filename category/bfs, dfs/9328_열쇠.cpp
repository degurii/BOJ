/*
����
����̴� 1�� ������ ħ���� �ſ� �߿��� ������ ���Ŀ����� �Ѵ�. ����̰� ������ �ִ� ��鵵���� ������ ��ġ�� ��� ��Ÿ�� �ִ�.
������ ���� ��� ����ֱ� ������, ���� ������ ���谡 �ʿ��ϴ�.
����̴� �Ϻ� ���踦 �̹� ������ �ְ�, �Ϻ� ����� ������ �ٴڿ� ������ �ִ�.
����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� ���� 100���� ���� �ʴ´�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ���̿� �ʺ� h�� w (2 �� h, w �� 100)�� �־�����.
���� h�� �ٿ��� ������ ��Ÿ���� w���� ���ڰ� �־�����, �� ���ڴ� ���� �� �ϳ��̴�.

'.'�� �� ������ ��Ÿ����.
'*'�� ���� ��Ÿ����, ����̴� ���� ����� �� ����.
'$'�� ����̰� ���ľ��ϴ� �����̴�.
���ĺ� �빮�ڴ� ���� ��Ÿ����.
���ĺ� �ҹ��ڴ� ���踦 ��Ÿ����, �� ������ �빮���� ��� ���� �� �� �ִ�.
������ �ٿ��� ����̰� �̹� ������ �ִ� ���谡 ������� �־�����. ����, ���踦 �ϳ��� ������ ���� �ʴ� ��쿡�� "0"�� �־�����.

����̴� ���� ������ ���� �� �ִ�.
������ ���� ���ؼ�, �� ���� �� �� �մ� ������ ������ 0��, 1��, �Ǵ� �� �̻��̰�,
������ ���迡 ���ؼ�, �� ����� �� �� �ִ� ���� ������ 0��, 1��, �Ǵ� �� �̻��̴�.
����� ���� �� ����� �� �ִ�.

���
�� �׽�Ʈ ���̽� ����, ����̰� ��ĥ �� �ִ� ������ �ִ� ������ ����Ѵ�.
*/





/*
�ڵ�¥�� ��ħ
ac�ޱ� ������ ���߿� �ٽ� ¥�� ����

solution:
�� ������ queue�� �����Ѵ�.
�迭�� �׵θ����� �Ա��� ã��
bfs�� �����ٰ� ���谡 ���� ���� ã����
�� ���� queue�� ��ǥ�� ����, 
�Ϲ� q�� bfs�� ������ ���谡 �ִ� ��� ���� queue�� ��ǥ�� �Ϲ� queue�� push
�ݺ��ؼ� �Ϲ� queue�� �����Ͱ� ������ �����Ѵ�


keyüũ�� bitmask�� �̿�
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