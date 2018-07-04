#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;	//n: num of vertex, m: num of edge
vector<vector<int> > p;

void bfs(int now) {
	queue<int> q;
	vector<bool> check(n + 1);
	check[now] = true;
	q.push(now);

	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	p.resize(n + 1);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}

	int start = 1;	// assume that start node is 1
	bfs(start);
}