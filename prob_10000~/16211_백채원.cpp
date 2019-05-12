/*
입력
첫째 줄에는 우리나라에 있는 지점의 수 N과 도로의 수 M, 백채원의 추종자의 수 K가 차례대로 주어진다. (1≤N≤200,000, 1≤M≤500,000, 1≤K≤N-1)
둘째 줄부터 M개의 줄에 차례대로 M개의 각 도로가 잇는 지점의 번호 A, B와 이 도로를 통해 두 지점을 오가는 데에 걸리는 시간 T가 주어진다. (1≤A,B≤N, 1≤T≤10,000, A≠B, 같은 도로가 두 번 주어지지 않는다.)
마지막 줄에는 백채원의 추종자들이 사는 지점의 번호를 나타내는 서로 다른 자연수 P1, …, PK가 공백을 사이에 두고 주어진다. (2 ≤ Pi ≤ N)

출력
백채원의 집이 될 수 있는 지점의 번호들을 한 줄에 공백을 사이에 두고 오름차순으로 출력하라.
만약 그런 지점이 하나도 없다면, 대신 정수 0을 출력한다.
백채원은 1번 지점에 집을 가지고 있지 않다는 점에 유의하라.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
	int to, cost;
};
int n, m, k;
vector<int> d1, d2;
vector<vector<Node>> p;
vector<int> dijkstra(vector<int> st) {
	priority_queue<pair<int, int>> q;
	vector<int> dist(2 * n, INF);
	vector<bool> chk(2 * n);

	for (int x : st)q.push({ 0, x }), dist[x] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();
		if (chk[now]) continue;
		chk[now] = true;

		for (auto e : p[now]) {
			int next = e.to;
			int ncost = e.cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	p.resize(n * 2);
	for (int i = 0; i < m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		p[x].push_back({ y, t });
		p[y].push_back({ x, t });
	}
	vector<int> temp;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		temp.push_back(x);
	}
	d1 = dijkstra(vector<int>(1, 1));
	d2 = dijkstra(temp);
	vector<int> ans;
	for (int i = 2; i < n + 1; i++) {
		if (d1[i] < d2[i]) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) cout << 0;
	else for (int x : ans)cout << x << ' ';
}