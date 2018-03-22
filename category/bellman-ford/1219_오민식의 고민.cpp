/*
문제
오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 많이 팔아서 최대 이윤을 남기라고 했다.

오민식은 고민에 빠졌다.

어떻게 하면 최대 이윤을 낼 수 있을까
이 나라에는 N개의 도시가 있다. 도시는 0번부터 N-1번까지 번호 매겨져 있다. 오민식의 여행은 A도시에서 시작해서 B도시에서 끝난다.
오민식이 이용할 수 있는 교통수단은 여러 가지가 있다.
오민식은 모든 교통수단의 출발 도시와 도착 도시를 알고 있고, 비용도 알고 있다. 게다가, 오민식은 각각의 도시를 방문할 때마다 벌 수 있는 돈을 알고있다.
이 값은 도시마다 다르며, 액수는 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 벌게 된다.
오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 액수를 최대로 하려고 한다. 이 최댓값을 구하는 프로그램을 작성하시오.

오민식이 돈을 버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 가지고 있는 돈의 액수가 음수가 될 수도 있다.
또, 같은 도시를 여러 번 방문할 수 있으며, 그 도시를 방문할 때마다 돈을 벌게 된다.
모든 교통 수단은 입력으로 주어진 방향으로만 이용할 수 있으며, 여러번 이용할 수도 있다.

입력
첫째 줄에 도시의 수 N과 시작 도시, 도착 도시 그리고 교통 수단의 개수 M이 주어진다.
둘째 줄부터 M개의 줄에는 교통 수단의 정보가 주어진다. 교통 수단의 정보는 “시작 끝 가격”과 같은 형식이다.
마지막 줄에는 오민식이 각 도시에서 벌 수 있는 돈의 최댓값이 0번 도시부터 차례대로 주어진다.
N과 M은 100보다 작거나 같고, 돈의 최댓값과 교통 수단의 가격은 1,000,000보다 작거나 같은 음이 아닌 정수이다.

출력
첫째 줄에 도착 도시에 도착할 때, 가지고 있는 돈의 액수의 최댓값을 출력한다.
만약 오민식이 도착 도시에 도착하는 것이 불가능할 때는 "gg"를 출력한다. 그리고, 오민식이 무한대의 돈을 벌 수 있을 때는 “Gee"를 출력한다.
*/


/*
solution:
역그래프의 bfs로 각 노드의 도착지점까지 도달 가능성을 구해 놓고
시작점에서 도착점으로 갈 수 없다면 "gg"
싸이클이 있는데 그 싸이클에 포함된 정점에서 도착점으로 갈 수 있다면 "Gee"
그 외에는 dist[종점]을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f
using ll = long long;

struct Edge {
	int from, to, cost;
};
int n, m, st, ed, money[101];
bool canGo[101];
ll dist[101];
Edge p[101];
vector<vector<int> > rev;

void dfs(int now) {
	canGo[now] = true;
	for (int next : rev[now]) {
		if (!canGo[next])
			dfs(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> st >> ed >> m;
	fill(dist, dist + n, INF);
	rev.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> p[i].from >> p[i].to >> p[i].cost;
		rev[p[i].to].push_back(p[i].from);
	}
	dfs(ed);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
	dist[st] = -money[st];
	bool cycle = false;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			int now = p[j].from;
			int next = p[j].to;
			int ncost = p[j].cost;

			if (dist[now] != INF && dist[next] > dist[now] + ncost - money[next]) {
				dist[next] = dist[now] + ncost - money[next];
				if (i == n) {
					if (canGo[next])
						cycle = true;
				}
			}
		}
	}

	if (!canGo[st]) cout << "gg";
	else if (cycle) cout << "Gee";
	else cout << -dist[ed];
}