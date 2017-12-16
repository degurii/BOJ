/*
문제
V개의 마을와 E개의 도로로 구성되어 있는 도시가 있다. 도로는 마을과 마을 사이에 놓여 있으며, 일방 통행 도로이다.
마을에는 편의상 1번부터 V번까지 번호가 매겨져 있다고 하자.
당신은 도로를 따라 운동을 하기 위한 경로를 찾으려고 한다.
운동을 한 후에는 다시 시작점으로 돌아오는 것이 좋기 때문에, 우리는 사이클을 찾기를 원한다.
단, 당신은 운동을 매우 귀찮아하므로, 사이클을 이루는 도로의 길이의 합이 최소가 되도록 찾으려고 한다.
도로의 정보가 주어졌을 때, 도로의 길이의 합이 가장 작은 사이클을 찾는 프로그램을 작성하시오.
두 마을을 왕복하는 경우도 사이클에 포함됨에 주의한다.

입력
첫째 줄에 V와 E가 빈칸을 사이에 두고 주어진다. (2<=V<=400, 0<=E<=V*(V-1))
다음 E개의 줄에는 각각 세 개의 정수 a, b, c가 주어진다.
a번 마을에서 b번 마을로 가는 거리가 c인 도로가 있다는 의미이다. (a->b임에 주의
거리는 10,000 이하의 자연수이다.

출력
첫째 줄에 최소 사이클의 도로 길이의 합을 출력한다. 운동 경로를 찾는 것이 불가능한 경우에는 -1을 출력한다.
*/






/*
solution:
플로이드-워셜로 모든 경로의 최단거리를 구한다.
싸이클을 찾아야 하므로
모든 정점쌍(i, j)에 대해서, d[i][j]+d[j][i]의 최솟값을 구한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

int d[401][401];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	fill(&d[0][0], &d[0][0] + 401 * 401, inf);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = w;
	}
	
	for (int i = 1; i < n + 1; i++) d[i][i] = 0;
	
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	
	int ans = inf;
	for (int i = 1; i < n + 1; i++) {
		for (int j = i + 1; j < n + 1; j++) {
			if (d[i][j] != inf && d[j][i] != inf) {
				ans = min(ans, d[i][j] + d[j][i]);
			}
		}
	}
	if (ans == inf) cout << -1;
	else cout << ans;
}