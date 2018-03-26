/*
원래의 네트워크에 대한 정보가 주어졌을 때, 위의 조건을 만족하면서 네트워크를 복구하는 방법을 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 두 정수 N, M이 주어진다. 다음 M개의 줄에는 회선의 정보를 나타내는 세 정수 A, B, C가 주어진다.
이는 A번 컴퓨터와 B번 컴퓨터가 통신 시간이 C (1 ≤ C ≤ 10)인 회선으로 연결되어 있다는 의미이다.
컴퓨터들의 번호는 1부터 N까지의 정수이며, 1번 컴퓨터는 보안 시스템을 설치할 슈퍼컴퓨터이다.
C값은 항상 양수이다. 또한 모든 통신은 완전쌍방향 방식으로 이루어지기 때문에, 한 회선으로 연결된 두 컴퓨터는 어느 방향으로도 통신할 수 있다.

출력
첫째 줄에 복구할 회선의 개수 K를 출력한다.
다음 K개의 줄에는 복구한 회선을 나타내는 두 정수 A, B를 출력한다.
이는 A번 컴퓨터와 B번 컴퓨터를 연결하던 회선을 복구한다는 의미이다.
출력은 임의의 순서대로 하며, 답이 여러 개 존재하는 경우에는 아무 것이나 하나만 출력하면 된다.
*/


/*
solution:
1에서부터 최단거리로 갈 수 있는 간선들을 출력하면 된다.
n개 정점들을 최단거리로 잇는 간선들은 n-1개이므로 n-1개 고정출력 후
다익스트라 실행과정 중에서 정점이 true가 될 때마다 이전정점과 현재정점(=간선정보)를 출력한다.
*/


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
	int to, cost;
	Node(int t = 0, int c = 0) :to(t), cost(c) {}
};
int n, m;
vector<vector<Node> > p;
bool check[10001];
int dist[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	cout << n - 1 << '\n';
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		p[u].push_back(Node(v, c));
		p[v].push_back(Node(u, c));
	}
	fill(dist + 1, dist + n + 1, INF);
	dist[1] = 0;
	priority_queue<pair<int, pair<int, int> > > q;
	q.push({ 0, {1, 1} });
	while (!q.empty()) {
		int now = q.top().second.first;
		int prev = q.top().second.second;
		q.pop();
		if (check[now]) continue;
		if(now != 1)
			cout << prev << ' ' << now << '\n';
		check[now] = true;
		
		for (auto it : p[now]) {
			int next = it.to;
			int ncost = it.cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], {next, now} });
			}
		}
	}
}