/*
입력
The first line contains three integers n, m, and k where 1 ≤ n, k, ≤ 1,000 and 1 ≤ m ≤ 1,000,000.
The following m lines contain two integers per line where each line describes an inseparable pair of jars (the two integers in the same line are distinct and between 1 and n, inclusive).
The (i+1)th line describes the ith pair of inseparable jars.

출력
Your output should consist of a single line that contains either "SAFE" or "DOOMED".
Output "SAFE" if it is possible to safely separate k jars and n-k jars; otherwise, output "DOOMED".
Quotes are for clarity only.
*/


/*
solution
묶여야 하는 번호들끼리 그룹을 짓는다
그룹의 사이즈와 k까지의 용량을 이용한 knapsack 문제
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > p(1001);
bool check[1001];
vector<int> group(1);
int n, m, k, g;
int d[1001][1001];

void dfs(int now) {
	check[now] = true;
	group[g]++;
	for (auto &next : p[now]) {
		if(check[next] == false)
			dfs(next);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	
	for (int i = 1; i < n + 1; i++) {
		if (check[i] == false) {
			group.push_back(0);
			g++;
			dfs(i);
		}
	}
	sort(group.begin(), group.end());
	for (int i = 1; i < g + 1; i++) {
		for (int j = 1; j < k + 1; j++) {
			if (group[i] > j) 
				d[i][j] = d[i - 1][j];
			d[i][j] = max(d[i - 1][j], group[i] + d[i - 1][j - group[i]]);
		}
	}

	bool flag = false;
	for (int i = 1; i < g + 1; i++) {
		if (d[i][k] == k) {
			flag = true;
			break;
		}
	}
	if (flag) cout << "SAFE";
	else cout << "DOOMED";
}