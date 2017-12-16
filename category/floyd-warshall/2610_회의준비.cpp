/*
문제
KOI 준비를 위해 회의를 개최하려 한다. 주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 이상의 위원회를 구성하려고 한다.
위원회를 구성하는 방식은 다음과 같다.

서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.
이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다.
각 위원회의 대표만이 회의 시간 중 발언권을 가지며,
따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 자신의 의견을 전달해야 한다.
그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다.
대표에게 의견을 전달하는 경로가 여러 개 있를 경우에는 가장 적은 사람을 거치는 경로로 의견을 전달하며
이 때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.

위원회에서 모든 참석자들의 의사전달시간 중 최대값이 최소가 되도록 대표를 정하는 프로그램을 작성하시오.

입력
첫째 중에 회의에 참석하는 사람의 수 N이 주어진다. 참석자들은 1부터 N까지의 자연수로 표현되며 회의에 참석하는 인원은 100 이하이다.
둘째 줄에는 서로 알고 있는 관계의 수 M이 주어진다.
이어 M개의 각 줄에는 서로 아는 사이인 참석자를 나타내는 두개의 자연수가 주어진다.

출력
첫째 줄에는 구성되는 위원회의 수 K를 출력한다.
다음 K줄에는 각 위원회의 대표 번호를 작은 수부터 차례로 한 줄에 하나씩 출력한다.
한 위원회의 대표가 될 수 있는 사람이 둘 이상일 경우 그중 한 명만 출력하면 된다.
*/





/*
solution:
(d[i][j] == 1) -> i와 j가 서로 알고있다.
(d[i][j] == k) -> i와 j가 k명을 건너 알고있다.

플로이드-워셜을 돌려서
서로 알고있는 관계이면 같은 그룹에 묶은다음
답을 구한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;

int n, m;
int foo(vector<vector<int> > &d, int now) {
	int dd = 0;
	for (int i = 1; i < n + 1; i++) {
		if (d[now][i] == inf) continue;
		dd = (dd > d[now][i]) ? dd : d[now][i];
	}
	return dd;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int> > d(n + 1, vector<int>(n + 1, inf));
	for (int i = 1; i < n + 1; i++) d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = 1;
	}
	
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	vector<bool> check(n + 1);
	vector<vector<int> > group;
	for (int i = 1; i < n + 1; i++) {
		if (check[i]) continue;
		check[i] = true;
		group.push_back(vector<int>(1, i));
		int g = group.size() - 1;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int next = 1; next < n + 1; next++) {
				if (!check[next] && d[now][next] == 1) {
					check[next] = true;
					group[g].push_back(next);
					q.push(next);
				}
			}
		}
	}
	cout << group.size() << '\n';
	vector<int> print;
	for (int i = 0; i < group.size(); i++) {
		int min = inf, ans = -1;
		for (int j = 0; j < group[i].size(); j++) {
			int now = group[i][j];
			int tvalue = foo(d, now);
			if (min > tvalue) {
				min = tvalue;
				ans = now;
			}
		}
		print.push_back(ans);
	}
	sort(print.begin(), print.end());
	for (int i : print) cout << i << '\n';
}
