/*
체스판은 각 정사각형이 검정 또는 흰색이며, 변을 공유하는 두 개의 사각형이 같은 색이 아닐 때 이다.
따라서 위 정의에 의하면 체스판의 색은 항상 두 가지가 가능한데, 하나는 왼쪽 위 코너가 흰색인 것, 검정색인 것 두가지이다.

입력
첫째 줄에 N과 M이 주어진다. M과 N은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다
둘째 줄부터 N개 줄에는 체스판의 색 상태가 주어진다. B는 검정색이며, W는 흰색이다.

출력
첫째 줄에 지민이가 8*8크기로 자른 뒤에 다시 칠해야하는 정사각형 개수의 최솟값을 출력한다.
*/



/*
sliding window로 비교해보자
*/
#include <iostream>
using namespace std;

int ori1[8][8], ori2[8][8], p[51][51];
int cmp(int x, int y) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (ori1[i - x][j - y] != p[i][j]) {
				cnt1++;
			}
			if (ori2[i - x][j - y] != p[i][j]) {
				cnt2++;
			}
		}
	}
	return (cnt1 < cnt2) ? cnt1 : cnt2;
}
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == 'W')
				p[i][j] = 1;
			else
				p[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) & 1) {
				ori1[i][j] = 0;
				ori2[i][j] = 1;
			}
			else {
				ori1[i][j] = 1;
				ori2[i][j] = 0;
			}
		}
	}
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			ans = min(ans, cmp(i, j));
		}
	}
	cout << ans;
}