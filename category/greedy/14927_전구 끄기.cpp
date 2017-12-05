/*
문제
홍익이를 도와서 전구 판의 모든 전구를 끌 수 있는 최소 횟수 B를 알아보자.
만약, 전구를 끌 수 있는 방법이 없다면, -1을 출력하도록 한다.

입력
N
0과 1로 이루어진 NxN 행렬
(2 <= N <= 18)
출력
B
*/







/*
solution:
첫줄의 전구들을 누를지/안누를지 결정하면
두번째 줄부터는 바로 위의전구에 대해 버튼을 누를지 말지 결정 가능해진다.
버튼을 누르는 순서는 상관 없으므로(독립적) 왼쪽 위부터 순차적으로 결정해간다.
첫줄의 버튼을 누르는 조합이O(2^N)이고, 그 경우마다 O(N^2)로 결정하므로
O((N^2)*(2^N))으로 풀린다

처음 코드(맨아랫쪽 주석코드)는 1016MS로 풀렸고,
vector대신 배열을 쓰고 (-200MS)
change내부의 반복문을 if로 바꾸고 (-300MS)
2차원 배열 대신 1차원으로 바꾸고 비트마스킹을 이용해서(-20MS)
488MS까지 줄였다

더 이상 줄이는건 내 능력 밖일듯
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