/*
입력
First line contains two integers, n and m where 1 ≤ n ≤ 16 and 1 ≤ m ≤ 150.
The following m lines contain two integers where i+1th line
describes fi and si where 1 ≤ fi, si ≤ n. It is guaranteed that fi ≠ si for all i.

출력
Your output should be a single line that contains a string "POSSIBLE" or "IMPOSSIBLE" (quotes for clarity only).
*/


/*
solution:
쪼개져야하는 번호들이 이분그래프를 이루는가를 묻는 문제
나오지 않은 번호는 신경쓰지 않아도 된다
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > p;
vector<int> color;
vector<bool> check;
void dfs(int now, int c) {
	check[now] = true;
	color[now] = c;
	for (auto &next : p[now]) {
		if (!check[next]) {
			dfs(next, 3 - c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	color.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}

	bool flag = true;
	for (int i = 1; i < n + 1; i++) {
		if (check[i] == false)
			dfs(i, 1);
	}

	for (int now = 1; now < n + 1; now++) {
		for (auto &next : p[now]) {
			if (color[next] == color[now]) { 
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	if (flag)cout << "POSSIBLE";
	else cout << "IMPOSSIBLE";
}



