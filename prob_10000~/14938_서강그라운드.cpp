/*
문제
예은이가 얻을 수 있는 아이템의 최대 개수를 알려주자.

입력
첫째 줄에는 지역의 개수 n (1 ≤ n ≤ 100)과 예은이의 수색범위 m (1 ≤ m ≤ 15), 길의 개수 r (1 ≤ r ≤ 100)이 주어진다.
둘째 줄에는 n개의 숫자가 차례대로  각 구역에 있는 아이템의 수 t (1 ≤ t ≤ 30)를 알려준다.
세번째 줄부터 r+2번째 줄 까지 길 양 끝에 존재하는 지역의 번호 a, b, 그리고 길의 길이 l (1 ≤ l ≤ 15)가 주어진다.

출력
예은이가 얻을 수 있는 최대 아이템 개수를 출력한다.
*/








/*
solve:
처음엔 단순 bfs를 모든 노드에서 돌렸음 -> 틀렸다
좀 더 생각해본뒤, 모든 노드에서 수색범위만큼 가는 스패닝트리를 만듬 -> 틀렸다
예외케이스 몇개를 만들어본 뒤, 어떻게 해야하나 생각해봄
-> n제한이 100이므로 floyd-warshall로 전부 구해서 하나하나 비교해보면 되는거였음
아직 그래프쪽은 너무 약한듯함
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n, m, r;
int d[101][101], items[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> m;
	for (int i = 1; i < n + 1; i++)
		cin >> items[i];
	fill(&d[0][0], &d[0][0] + 101 * 101, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (d[u][v]) {
			d[u][v] = min(d[u][v], w);
			d[v][u] = min(d[v][u], w);
		}
		else {
			d[u][v] = w;
			d[v][u] = w;
		}
	}
	for (int i = 1; i < n + 1; i++)d[i][i] = 0;
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = 0;
	
	for (int u = 1; u < n + 1; u++) {
		int res = 0;
		for (int v = 1; v < n + 1; v++) {
			if (d[u][v] <= r)
				res += items[v];
		}
		ans = max(ans, res);
	}
	cout << ans;
}