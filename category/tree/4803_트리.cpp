/*
문제
그래프는 정점과 간선으로 이루어져 있다. 두 정점 사이에 경로가 있다면, 두 정점은 연결되어 있다고 한다.
연결 요소는 모든 정점이 서로 연결되어 있는 정점의 부분집합이다.
그래프는 하나 또는 그 이상의 연결 요소로 이루어져 있다.
트리는 사이클이 없는 연결 요소이다. 트리에는 여러 성질이 있다.
예를 들어, 트리는 정점이 n개, 간선이 n-1개 있다. 또, 임의의 두 정점에 대해서 경로가 유일하다.
그래프가 주어졌을 때, 트리의 개수를 세는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 n ≤ 500과 m ≤ n(n-1)/2을 만족하는 정점의 개수 n과 간선의 개수 m이 주어진다.
다음 m개의 줄에는 간선을 나타내는 두 개의 정수가 주어진다. 같은 간선은 여러번 주어지지 않는다. 정점은 1번부터 n번까지 번호가 매겨져 있다.
입력의 마지막 줄에는 0이 두 개 주어진다.

출력
입력으로 주어진 그래프에 트리가 없다면 "No trees."를,
한 개라면 "There is one tree."를,
두 개 이상이라면 "A forest of T trees."를 테스트 케이스 번호와 함께 출력한다.
*/


/*
solution:
한 컴포넌트 내 정점의 수가 g일때 컴포넌트 내의 간선의 개수가 g-1개인지 확인한다.
*/
#include <iostream>
#include <vector>
using namespace std;
using vvi = vector<vector<int>>;

int n, m;
vvi p, group;
vector<bool> check;
void dfs(int now) {
	int g = group.size() - 1;
	group[g].push_back(now);
	check[now] = true;
	for (auto next : p[now]) {
		if (!check[next]) {
			dfs(next);
		}
	}
}
int getEdgeNum(int now) {
	int edge = 0;
	check[now] = true;
	for (int next : p[now]) {
		edge++;
		if (!check[next])
			edge += getEdgeNum(next);
	}
	return edge;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int tc = 1; cin >> n >> m, n != 0; tc++) {
		p = vvi(n + 1, vector<int>());
		check = vector<bool>(n + 1);
		group.clear();

		while (m--) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			p[v].push_back(u);
		}

		int treenum = 0;
		for (int i = 1; i < n + 1; i++) {
			if (!check[i]) {
				group.push_back(vector<int>());
				dfs(i);
			}
		}
		check = vector<bool>(n + 1);
		for (auto g : group) {
			int edge = getEdgeNum(g[0]);
			if (edge / 2 == g.size() - 1)
				treenum++;
		}

		if (treenum == 0)
			cout << "Case " << tc << ": No trees.\n";
		else if (treenum == 1)
			cout << "Case " << tc << ": There is one tree.\n";
		else
			cout << "Case " << tc << ": A forest of " << treenum << " trees.\n";
	}

}