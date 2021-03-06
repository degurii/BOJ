/*
문제
영선회사에는 치명적인 악습이 있는데, 바로 상사가 직속 부하를 갈구면 그 부하가 부하의 직속 부하를 연쇄적으로 갈구는 내리 갈굼이 있다.
즉, 상사가 한 직속 부하를 갈구면 그 부하의 모든 부하들이 갈굼을 당한다.

갈굼에 대해 정도에 대한 수치가 주어지는데, 이 수치 또한 부하들에게 똑같이 갈궈진다.
이번에는 내리 갈굼이 실시간으로 일어날 것이다.
입력으로 아래와 같은 쿼리가 주어질 것이다.

1 i w : i번째 직원이 직속 상사로부터 w만큼 갈굼을 당한다. .(2≤i≤n, 1≤w≤1,000)
2 i : i번째 직원이 갈굼을 당한 정도를 확인(출력).
직속 상사와 직속 부하관계에 대해 주어지고,쿼리가 주어졌을 때 2번 쿼리에 따라 출력하시오.

입력
첫째 줄에는 회사의 직원 수 n명, 쿼리의 개수 m이 주어진다. 직원은 1번부터 n번까지 번호가 매겨져 있다. . (2≤n,m≤100,000)
둘째 줄에는 직원 n명의 직속 상사의 번호가 주어진다. 직속 상사의 번호는 자신의 번호보다 작으며, 최종적으로 1번이 사장이다. 1번의 경우, 상사가 없으므로 -1이 입력된다.
다음 m줄에는 위와 같이 쿼리가 주어진다. 사장은 상사가 없으므로 갈굼을 당하지 않는다.

출력
2번 쿼리가 주어질 때마다, 알맞게 출력하시오.
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m, lazy[400001], tree[400001], l[100001], r[100001];
vector<vector<int>> p;

void dfs(int now, int &o) {
	l[now] = ++o;
	for (int next : p[now]) {
		dfs(next, o);
	}
	r[now] = o;
}

void update_lazy(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1)*lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int s, int e, int i, int j, int v) {
	update_lazy(node, s, e);
	if (j < s || e < i) return;
	if (i <= s && e <= j) {
		tree[node] += (e - s + 1)*v;
		if (s != e) {
			lazy[node * 2] += v;
			lazy[node * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, i, j, v);
	update(node * 2 + 1, m + 1, e, i, j, v);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int s, int e, int idx) {
	update_lazy(node, s, e);
	if (idx < s || e < idx) return 0;
	if (s == e) return tree[node];
	int m = (s + e) / 2;
	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	int x;
	cin >> x;
	for (int i = 2; i < n + 1; i++) {
		cin >> x;
		p[x].push_back(i);
	}
	int o = 0;
	dfs(1, o);
	int c, y; 
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 1) {
			cin >> x >> y;
			update(1, 1, n, l[x], r[x], y);
		}
		else if (c == 2) {
			cin >> x;
			cout << query(1, 1, n, l[x]) << '\n';
		}
	}
}