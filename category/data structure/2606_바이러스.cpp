/*
문제
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다.
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다.
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/




/*
solution:
dfs/bfs/floyd-warshall 전부 가능
난 union-find로 해결함
*/
#include <iostream>
using namespace std;

int n, m;
int p[101];
int Find(int x) {
	if (p[x] == x) return x;
	else return p[x] = Find(p[x]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)p[i] = i;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[Find(u)] = Find(v);
	}
	int ans = 0;
	for (int i = 2; i < n + 1; i++) {
		if (Find(1) == Find(i)) ans++;
	}
	cout << ans;
}