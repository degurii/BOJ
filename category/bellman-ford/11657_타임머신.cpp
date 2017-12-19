/*
문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다.
각 버스는 A, B, C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다.
시간 C가 양수가 아닌 경우가 있다. C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.
1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다.
둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다.

출력
첫째 줄에는 2번 도시까지 가는 가장 빠른 시간, ..., N-1번째 줄에는 N번 도시까지 가는 가장 빠른 시간을 출력한다.
어떤 도시로 가는 가장 빠른 시간이 없는 경우에는 -1을 출력한다.
만약, 시작점에서 도달 가능한 타임머신으로 되어있는 사이클이 존재해 1번 도시에서 나머지 도시로 가는 가장 빠른 시간이 존재하지 않는 경우에는 -1을 출력한다.
*/





/*
solution:
기본 벨만-포드 알고리즘 문제
*/
#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;

int n, m;
struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) :u(u), v(v), w(w) {}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<int> dist(n + 1, inf);
	vector<Edge> p;
	dist[1] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		p.push_back(Edge(u, v, w));
	}
	bool cycle = false;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			Edge e = p[j];
			if (dist[e.v] > dist[e.u] + e.w) {
				dist[e.v] = dist[e.u] + e.w;
				if (i == n) {
					cycle = true;
					break;
				}
			}
		}
	}
	if (cycle) {
		cout << -1;
		return 0;
	}
	for (int i = 2; i < n + 1; i++) {
		if (dist[i] == inf) cout << -1;
		else cout << dist[i];
		cout << '\n';
	}
}