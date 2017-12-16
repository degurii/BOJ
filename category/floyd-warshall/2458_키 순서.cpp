/*
학생들의 키를 비교한 결과가 주어질 때, 자신의 키가 몇 번째인지 알 수 있는 학생들이 모두 몇 명인지 계산하여 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 학생들의 수 N (2<=N<=500)과 두 학생 키를 비교한 횟수 M (0<=M<=N(N-1)/2)이 주어진다.
다음 M개의 각 줄에는 두 학생의 키를 비교한 결과를 나타내는 두 양의 정수 a와 b가 주어진다.
이는 번호가 a인 학생이 번호가 b인 학생보다 키가 작은 것을 의미한다.

출력
자신이 키가 몇 번째인지 알 수 있는 학생이 모두 몇 명인지를 출력한다.
*/




/*
solution:
a>b, b>c 이거나, a<b, b<c이면 a->c로 갈 수 있는경로가 있다고 생각한다.
플로이드-워셜로 모든 경로를 찾은 뒤
어떤 정점이든 갈 수 있다면 정답에 추가한다.
*/
#include <iostream>
using namespace std;

int n, m;
int d[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = -1;
	}
	for (int i = 0; i < n + 1; i++) d[i][i] = 1;
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][k] != 0 && d[i][k] == d[k][j])
					d[i][j] = d[i][k];
			}
		}
	}
	int cnt = 0, ans = 0;
	for (int j = 1; j < n + 1; j++) {
		for (int i = 1; i < n + 1; i++) {
			cnt += (d[i][j] != 0);
		}
		if (cnt == n)
			ans++;
		cnt = 0;
	}
	cout << ans;
}