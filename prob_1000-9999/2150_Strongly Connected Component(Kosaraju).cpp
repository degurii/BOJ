/*
문제
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오.
방향 그래프의 SCC는 우선 정점의 최대 부분집합이며,
그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.

입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다.
다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다.
이 때 방향은 A->B가 된다.

출력
첫째 줄에 SCC의 개수를 K를 출력한다.
다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다.
각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다.
각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다.
또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.
*/




/*
solution:

scc의 기초문제이다
kosaju알고리즘으로 풀었다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<vector<int> > ori, rev, scc;
vector<int> order, group;
vector<bool> check;
void dfs(int now) {
	check[now] = true;
	for (int next : ori[now]) {
		if (!check[next])
			dfs(next);
	}
	order.push_back(now);
}

void make_scc(int now, int gnum) {
	check[now] = true;
	group[now] = gnum;
	for (int next : rev[now])
		if (!check[next])
			make_scc(next, gnum);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e;
	ori.resize(v + 1);
	rev.resize(v + 1);
	check.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		ori[x].push_back(y);
		rev[y].push_back(x);
	}
	for (int i = 1; i < v + 1; i++) {
		if (!check[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());
	check.clear();
	check.resize(v + 1);
	group.resize(v + 1);
	int gnum = -1;
	for (int now : order) {
		if (!check[now]) {
			gnum++;
			make_scc(now, gnum);
		}
	}
	cout << gnum + 1 << '\n';
	scc.resize(gnum + 1);
	for (int i = 1; i < v + 1; i++) {
		scc[group[i]].push_back(i);
	}
	for (auto i : scc) {
		sort(i.begin(), i.end());
	}
	sort(scc.begin(), scc.end());
	for (auto c : scc) {
		for (auto i : c) {
			cout << i << ' ';
		}
		cout << "-1\n";
	}
}