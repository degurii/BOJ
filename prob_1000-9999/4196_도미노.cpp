/*
문제
도미노는 재밌다. 도미노 블록을 일렬로 길게 늘어세운 뒤 블록 하나를 넘어뜨리면
그 블록이 넘어지며 다음 블록을 넘어뜨리는 일이 반복되어 일렬로 늘어선 블록들을 연쇄적으로 모두 쓰러뜨릴 수 있다.
그러나, 가끔씩 도미노가 다른 블록을 넘어뜨리지 못하게 배치되어 있다면, 우리는 다음 블록을 수동으로 넘어뜨려야 한다.
이제 각 도미노 블록의 배치가 주어졌을 때, 모든 블록을 넘어뜨리기 위해 손으로 넘어뜨려야 하는 블록 개수의 최소값을 구하자.

입력
첫 번째 줄에 테스트 케이스의 개수가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 정수 N, M이 주어지며 두 수는 100,000을 넘지 않는다.
N은 도미노의 개수를, M은 관계의 개수를 나타낸다. 도미노 블록의 번호는 1과 N 사이의 정수다.
다음 M개의 줄에는 각각 두 정수 x, y가 주어지는데, 이는 x번 블록이 넘어지면 y번 블록도 넘어짐을 뜻한다.

출력
각 테스트 케이스마다 한 줄에 정수 하나를 출력한다.
정답은 손으로 넘어뜨려야 하는 최소의 도미노 블록 개수이다.
*/






/*
처음엔 쉬운 위상정렬 문제인 줄 알았는데 아니였음
scc를 구한 뒤 각각의 싸이클내부끼리 연결된 indegree는 뺴주고,
각 scc에 포함된 각 노드 전체의 ind가 0이면 직접 손으로 넘겨야 하는 도미노이다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
void dfs(vector<vector<int> > &p, vector<int> &order, vector<bool> &check, int now) {
	check[now] = true;
	for (int &next : p[now]) {
		if (check[next] == false)
			dfs(p, order, check, next);
	}
	order.push_back(now);
}
void make_scc(vector<vector<int> > &p, vector<int> &compo, vector<bool> &check, int now, int cnt) {
	check[now] = true;
	compo[now] = cnt - 1;
	for (int next : p[now]) {
		if(check[next] == false)
			make_scc(p, compo, check, next, cnt);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<bool> check(n + 1);
		vector<int> ind(n + 1);
		vector<vector<int> > ori(n + 1), rev(n + 1);
		while (m--) {
			int u, v;
			cin >> u >> v;
			ori[u].push_back(v);
			ind[v]++;
			rev[v].push_back(u);
		}
		vector<int> order;
		for (int i = 1; i < n + 1; i++) {
			if (check[i] == false) {
				dfs(ori, order, check, i);
			}
		}
		reverse(order.begin(), order.end());
		vector<int> component(n + 1);
		check.clear();
		check.resize(n + 1);
		int cnt = 0;
		for (int i : order) {
			if (check[i] == false)
				make_scc(rev, component, check, i, ++cnt);
		}
		vector<vector<int> > scc(cnt);
		for (int i = 1; i < n + 1; i++) {
			scc[component[i]].push_back(i);
		}
		for (auto i : scc) {
			for (int now : i) {
				for (int v : ori[now]) {
					if(component[v] == component[now])
						ind[v]--;
				}
			}
		}
		int ans = cnt;
		for (auto i : scc) {
			for (int j : i) {
				if (ind[j] != 0) {
					ans--;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}