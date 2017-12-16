/*
문제
물건의 개수 N 과 일부 물건 쌍의 비교 결과가 주어졌을 때,
각 물건에 대해서 그 물건과의 비교 결과를 알 수 없는 물건의 개수를 출력하는 프로그램을 작성하시오.

입력
첫 줄에는 물건의 개수 N 이 주어지고,
둘째 줄에는 미리 측정된 물건 쌍의 개수 M이 주어진다. 단, 5 ≤ N ≤ 100 이고, 0 ≤ M ≤ 2,000이다.
다음 M개의 줄에 미리 측정된 비교 결과가 한 줄에 하나씩 주어진다.
각 줄에는 측정된 물건 번호를 나타내는 두 개의 정수가 공백을 사이에 두고 주어지며, 앞의 물건이 뒤의 물건보다 더 무겁다.

출력
여러분은 N개의 줄에 결과를 출력해야 한다. i 번째 줄에는 물건 i 와 비교 결과를 알 수 없는 물건의 개수를 출력한다.
*/




/*
solution:
대소관계는 전이성이 있기때문에
a<b, b<c 이면 a<c이고
a>b, b>c 이면 a>c이다.
a>b를 1로, a<b를 -1로 배열에 저장후
워셜-플로이드로 모두 비교해보면 된다.
d[i][k] == d[k][j] 이면 d[i][j]=d[i][k].
*/
#include <iostream>
#include <algorithm>
using namespace std;

int d[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) d[i][i] = 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = -1;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][k] != 0 && d[i][k] == d[k][j]) {
					d[i][j] = d[i][k];
				}
			}
		}
	}
	int ans = 0;
	for (int j = 1; j < n + 1; j++) {
		for (int i = 1; i < n + 1; i++) {
			ans += (!d[i][j]);
		}
		cout << ans << '\n';
		ans = 0;
	}
}