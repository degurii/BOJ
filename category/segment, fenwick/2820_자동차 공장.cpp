/*
문제
상근이는 자동차를 매우 좋아한다. 자동차 공장에 취직한 상근이는 계속된 승진 끝에 드디어 사장이 되었다.
공장에는 총 N명의 직원이 있다. 상근이를 제외한 모든 직원은 한 명의 상사가 있다. (상근이는 모든 사람의 상사이다) 상근이의 번호는 1번이고, 나머지 직원의 번호는 2부터 N이다.
모든 직원은 자신의 모든 부하 직원(직속 부하와 부하의 부하등등을 모두 포함)의 월급을 인상하거나 삭감할 수 있다. 상근이는 권력 남용을 막기 위해 직원의 월급을 모니터링 하려고 한다.
월급의 변화를 모니터링하는 프로그램을 작성하시오.
모든 직원의 월급은 항상 양의 정수이고 231-1 이하이다.

입력
첫째 줄에 직원의 수 N과 월급 변화와 조사 쿼리의 수 M이 주어진다. (1 ≤ N, M ≤ 500,000)
다음 N개 줄의 i번째 줄에는 직원 i의 초기 월급과 상사의 번호가 주어진다. (상근이는 상사가 없기 때문에, 초기 월급만 주어진다)
다음 M개 줄에는 월급 변화와 조사 쿼리가 주어진다.

1. p a x가 주어진 경우 A의 모든 부하의 월급을 X만큼 증가시킨다. (-10,000 ≤ X ≤ 10,000)
2. u a가 주어진 경우에는 A의 월급을 출력한다.

출력
입력으로 u가 주어질 때마다 해당하는 직원의 월급을 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;
const int N_MAX = 500001;
using ll = long long;

int n, m, l[N_MAX], r[N_MAX];
ll tree[N_MAX * 4], lazy[N_MAX * 4], money[N_MAX], order[N_MAX];
vector<vector<int>> p;

void dfs(int now, int &o) {
	l[now] = ++o;
	for (int next : p[now]) dfs(next, o);
	r[now] = o;
}

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = order[s];
		return;
	}
	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
}

void update_lazy(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int s, int e, int i, int j, ll v) {
	update_lazy(node, s, e);
	if (j < s || e < i) return;
	if (i <= s && e <= j) {
		tree[node] += v;
		if (s != e) {
			lazy[node * 2] += v;
			lazy[node * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, i, j, v);
	update(node * 2 + 1, m + 1, e, i, j, v);
}
ll query(int node, int s, int e, int idx) {
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
	cin >> money[1];
	int x;
	for (int i = 2; i < n + 1; i++) {
		cin >> money[i] >> x;
		p[x].push_back(i);
	}
	int o = 0;
	dfs(1, o);
	for (int i = 1; i < n + 1; i++) {
		order[l[i]] = money[i];
	}
	init(1, 1, n);

	char c;
	ll y;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 'p') {
			cin >> x >> y;
			update(1, 1, n, l[x] + 1, r[x], y);
		}
		else if (c == 'u') {
			cin >> x;
			cout << query(1, 1, n, l[x]) << '\n';
		}
	}
}