/*
문제
튜브의 이동속도는 매우 빠르기 때문에
미노가 1번 도시에서 반물질 폭탄이 있는 도시로 이동한 다음에 폭탄을 들고 다시 N번 도시로 이동할 수만 있다면 CTP를 구할 수 있다.
이동하는 과정에서 똑같은 튜브를 다시 사용할 수 있고 방문했던 도시를 또다시 방문할 수도 있다. 또한 이동경로의 길이 제한은 없다.
과연 슈퍼히어로 미노는 위기에 빠진 CTP를 구할 수 있을까?

입력으로는 T개의 시나리오가 주어진다.
시나리오마다 재유니스가 반물질 폭탄을 설치한 도시의 번호가 주어진다.
각각의 시나리오에 대해 슈퍼히어로 미노가 CTP를 지킬 수 있는지 알아보는 프로그램을 작성하자.

입력
첫 번째 줄에 N(3≤N≤100,000)과 M(1≤M≤1,000,000)이 주어진다.
N은 CTP에 존재하는 도시의 개수를 의미하고 M은 CTP에 존재하는 튜브의 개수를 의미한다.
다음 M개의 줄에 걸쳐 X, Y(1≤X, Y≤N)가 주어지는데 X에서 Y로 이동할 수 있는 튜브가 있다는 뜻이다.
다음 줄에는 시나리오의 개수 T(1≤T≤100,000)가 주어진다
다음 T개의 줄에 차례대로 C(2≤C≤N-1)가 주어지는데 이는 우주급 빌런 재유니스가 반물질 폭탄을 설치한 도시의 번호를 의미한다.
입/출력의 양이 많으므로 속도가 빠른 입/출력 함수를 사용하는것을 권장한다.

출력
T개의 줄에 걸쳐 CTP를 지킬 수 있는지 결과를 출력한다.
만약 CTP를 구할 방법이 없다면 “Destroyed the CTP”를 출력하고 슈퍼히어로 미노가 CTP를 구할 수 있다면 “Defend the CTP”를 출력한다.
모든 출력은 쌍따옴표를 제외하고 출력한다.
*/






/*
solution:
case마다 주어지는 도시 c에 대해서,
1 -> c -> n 의 탐색이 가능한가를 묻는 문제이다.

어떤 노드 x에 대해
시작노드를 x로 해서 bfs/dfs를 돌리면
x에서 어떤 도시로 갈 수 있고 갈 수 없는지 저장할 수 있다.

임의의 노드 x와 고정된 노드 n에 대해
위와 같은 원리로 n -> x로 갈수있는도시와 못가는도시를 저장 할 수 있다
그 말은, 그래프의 모든 간선을 역방향으로 뒤집어서 bfs/dfs를 돌린다면
한번의 bfs로 x -> n으로의 탐색가능여부를 알 수 있다는 것이다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int t;
vector<vector<int> > ori, rev;
vector<bool> bomb, des;

vector<bool> bfs(vector<vector<int> > &p, int now) {
	vector<bool> check(n + 1);
	check[now] = true;
	queue<int> q;
	q.push(now);

	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int &next : p[now]) {
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
	return check;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	ori.resize(n + 1);
	rev.resize(n + 1);
	des.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ori[u].push_back(v);
		rev[v].push_back(u);
	}
	bomb = bfs(ori, 1);
	des = bfs(rev, n);
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		if (bomb[c] && des[c])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}
}