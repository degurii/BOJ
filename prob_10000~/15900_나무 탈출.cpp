/*
문제
성원이가 이 게임을 이길 수 있을지 없을지를 알려주는 프로그램을 만들어 성원이를 도와주자.

입력
첫째 줄에 트리의 정점 개수 N(2 ≤ N ≤ 500,000)이 주어진다.
둘째 줄부터 N-1줄에 걸쳐 트리의 간선 정보가 주어진다.
줄마다 두개의 자연수 a, b(1 ≤ a, b ≤ N, a ≠ b)가 주어지는데, 이는 a와 b 사이에 간선이 존재한다는 뜻이다.

출력
성원이가 최선을 다했을 때 이 게임을 이길 수 있으면 Yes, 아니면 No를 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> p;
vector<bool> check;
int dfs(int now, int l) {
	check[now] = true;
	int cnt = 0;
	for (int next : p[now]) {
		if (!check[next])
			cnt += dfs(next, l + 1);
	}
	return cnt ? cnt : l;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	p.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	if (dfs(1, 0) & 1) cout << "Yes";
	else cout << "No";
}