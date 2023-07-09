#include <iostream>
#include <vector>
using namespace std;


int n, m;	// n: num of vertex, m: num of edge
vector<vector<int> > p;
vector<bool> check;

void dfs(int now) {
	check[now] = true;

	for (int i = 0, l = p[now].size(); i < l; i++) {
		int next = p[now][i];
		if (!check[next])
			dfs(next);
	}
}
int main() {
	cin >> n >> m;
	check.resize(n + 1);
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	
	int start = 1; // assume that start node is 1
	dfs(start);
}
