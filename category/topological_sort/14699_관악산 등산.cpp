/*
문제
관악산의 쉼터들에는 조국의 미래를 볼 수 있는 전망대가 하나씩 설치되어 있다.
Corea는 최대한 많은 쉼터를 방문해서 조국의 미래를 많이 보고 Unused에게 전해 주기로 했다.
관악산의 지도가 주어질 때, Corea가 각각의 쉼터에서 출발해서 산을 오를 때 최대 몇 개의 쉼터를 방문할 수 있는지 구하여라.

입력
첫 번째 줄에 등산로에 있는 쉼터의 수 N(2 ≤ N ≤ 5, 000)과 두 쉼터 사이를 연결하는 길의 수 M(1 ≤ M ≤ 100, 000)이 주어진다.
두 번째 줄에는 각 쉼터의 높이를 나타내는 N개의 정수가 번호 순서대로 주어진다.각 쉼터의 높이는 1 이상 1, 000, 000 이하이며 서로 다르다.
세 번째 줄부터 M개의 줄에 걸쳐 각각의 길이 연결하는 두 쉼터의 번호가 공백으로 구분되어 주어진다
쉼터의 번호는 1 이상 N 이하의 정수이다. 양 끝점이 같은 쉼터인 길은 없으며, 임의의 두 쉼터를 연결하는 길이 여러 개 존재할 수 있다.

출력
N개의 줄에 걸쳐 n번째 줄에 Corea가 n번 쉼터에서 출발해서 산을 오를 때 최대로 방문할 수 있는 쉼터의 개수를 출력한다.
*/





/*
bfs처럼 생겨서 헤맸는데 사실 dp문제다
2017 icpc대전본선때 거의 비슷한 문제가 나왔었음
갓갓샤대의 선견지명에 경의를

solve:
높은 지역부터 순차적으로 update를 한다
dist는 자신보다 높은 위치에 있는 쉼터들의 최대개수

** 높은지역부터 반복문 돌리는걸 위상정렬로 해결해도 된다 **
** 그럼 굳이 귀찮게 sorting안해도 됨 **

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int n, m;
vector<vector<int> > p;
vector<pair<int, int> > sorted;
vector<int> dist, h;

void update(int now) {
	for (int &next : p[now]) {
		if (h[now] < h[next]) {
			dist[now] = max(dist[now], dist[next] + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	h.resize(n + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> h[i];
		sorted.push_back({ h[i], i });
	}
	dist.resize(n + 1, 1);
	p.resize(n + 1);
	sort(sorted.begin(), sorted.end(), greater<pair<int, int> >());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (auto it : sorted) {
		update(it.second);
	}
	for (int i = 1; i < n + 1; i++) {
		cout << dist[i] << '\n';
	}
}