/*
����
ȫ���̸� ���ͼ� ���� ���� ��� ������ �� �� �ִ� �ּ� Ƚ�� B�� �˾ƺ���.
����, ������ �� �� �ִ� ����� ���ٸ�, -1�� ����ϵ��� �Ѵ�.

�Է�
N
0�� 1�� �̷���� NxN ���
(2 <= N <= 18)
���
B
*/







/*
solution:
ù���� �������� ������/�ȴ����� �����ϸ�
�ι�° �ٺ��ʹ� �ٷ� ���������� ���� ��ư�� ������ ���� ���� ����������.
��ư�� ������ ������ ��� �����Ƿ�(������) ���� ������ ���������� �����ذ���.
ù���� ��ư�� ������ ������O(2^N)�̰�, �� ��츶�� O(N^2)�� �����ϹǷ�
O((N^2)*(2^N))���� Ǯ����

ó�� �ڵ�(�ǾƷ��� �ּ��ڵ�)�� 1016MS�� Ǯ�Ȱ�,
vector��� �迭�� ���� (-200MS)
change������ �ݺ����� if�� �ٲٰ� (-300MS)
2���� �迭 ��� 1�������� �ٲٰ� ��Ʈ����ŷ�� �̿��ؼ�(-20MS)
488MS���� �ٿ���

�� �̻� ���̴°� �� �ɷ� ���ϵ�
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

int n, src[18], p[18];
void change(int x, int y) {
	p[x] ^= (1 << y);
	if (x - 1 >= 0) p[x - 1] ^= (1 << y);
	if (x + 1 < n) p[x + 1] ^= (1 << y);
	if (y - 1 >= 0)p[x] ^= (1 << (y - 1));
	if (y + 1 < n) p[x] ^= (1 << (y + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) src[i] |= (1 << j);
		}
	}

	int ans = INF;
	for (int k = 0; k < (1 << n); k++) {
		memcpy(p, src, sizeof(src));
		int cnt = 0;
		for (int m = 0; m < n; m++) {
			if (k &(1 << m)) {
				cnt++;
				change(0, m);
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i - 1] & (1<<j)) {
					cnt++;
					change(i, j);
				}
			}
		}
		if (p[n - 1] != 0) cnt = INF;
		ans = (ans < cnt) ? ans : cnt;
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
void change(vector<vector<int> > &p, int x, int y) {
	p[x][y] ^= 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			p[nx][ny] ^= 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<vector<int> > src(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n ; j++) {
			cin >> src[i][j];
		}
	}
	
	int ans = INF;
	for (int k = 0; k < (1 << n); k++) { 
		auto p = src;
		int cnt = 0;
		for (int m = 0; m < n; m++) {
			if (k &(1 << m)) {
				cnt++;
				change(p, 0, m);
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i - 1][j] == 1) {
					cnt++;
					change(p, i, j);
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (p[n - 1][j] == 1) {
				cnt = INF;
				break;
			}
		}
		ans = min(ans, cnt);
	}
	if (ans == INF) cout << -1;
	else cout << ans;
}
*/