/*
명우기업은 2008년부터 택배 사업을 새로이 시작하기로 하였다.
우선 택배 화물을 모아서 처리하는 집하장을 몇 개 마련했지만, 택배 화물이 각 집하장들 사이를 오갈 때 어떤 경로를 거쳐야 하는지 결정하지 못했다.
어떤 경로를 거칠지 정해서, 이를 경로표로 정리하는 것이 여러분이 할 일이다.

경로표는 한 집하장에서 다른 집하장으로 최단경로로 화물을 이동시키기 위해 가장 먼저 거쳐야 하는 집하장을 나타낸 것이다.
이와 같은 경로표를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 두 수 n과 m이 빈 칸을 사이에 두고 순서대로 주어진다.
n은 집하장의 개수로 200이하의 자연수, m은 집하장간 경로의 개수로 10000이하의 자연수이다.
이어서 한 줄에 하나씩 집하장간 경로가 주어지는데, 두 집하장의 번호와 그 사이를 오가는데 필요한 시간이 순서대로 주어진다.
집하장의 번호들과 경로의 소요시간은 모두 1000이하의 자연수이다.

출력
예시된 것과 같은 형식의 경로표를 출력한다.
*/







/*
워셜-플로이드를 사용한다.
(d[i][j] > d[i][k] + d[k][j])
는 i->j의 다른 경로보다 i->k->j의 경로가 더 가깝다는 말이므로
ans[i][j] 를 ans[i][k]로 업데이트 해준다.
이때, (ans[i][k] == 0) 이라는 뜻은 i -> k로 바로 연결된 길이 있다는 뜻이므로
ans[i][j] = k로 업데이트 해준다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n, m;
int d[201][201], ans[201][201];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fill(&d[0][0], &d[0][0] + 201 * 201, INF);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (d[u][v] != 0) {
			d[u][v] = min(d[u][v], w);
			d[v][u] = min(d[v][u], w);
		}
		else {
			d[u][v] = w;
			d[v][u] = w;
		}
	}
	for (int i = 1; i < n + 1; i++) d[i][i] = 0;
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					if (ans[i][k] == 0)
						ans[i][j] = k;
					else
						ans[i][j] = ans[i][k];
				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j)
				cout << "- ";
			else if (ans[i][j] == 0)
				cout << j << ' ';
			else
				cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}