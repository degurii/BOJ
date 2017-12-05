/*
����
���� �׷����� �־����� ��, �� �׷����� SCC��� ������ ���α׷��� �ۼ��Ͻÿ�.
���� �׷����� SCC�� �켱 ������ �ִ� �κ������̸�,
�� �κ����տ� ����ִ� ���� �ٸ� ������ �� ���� u, v�� ���ؼ� u���� v�� ���� ��ο� v���� u�� ���� ��ΰ� ��� �����ϴ� ��츦 ���Ѵ�.

�Է�
ù° �ٿ� �� ���� V(1��V��10,000), E(1��E��100,000)�� �־�����. �̴� �׷����� V���� ������ E���� �������� �̷���� �ִٴ� �ǹ��̴�.
���� E���� �ٿ��� ������ ���� ������ ��Ÿ���� �� ���� A, B�� �־�����. �̴� A�� ������ B�� ������ ����Ǿ� �ִٴ� �ǹ��̴�.
�� �� ������ A->B�� �ȴ�.

���
ù° �ٿ� SCC�� ������ K�� ����Ѵ�.
���� K���� �ٿ��� �� �ٿ� �ϳ��� SCC�� ���� ������ ��ȣ�� ����Ѵ�.
�� ���� ������ -1�� ����Ͽ� �� ���� ���� ��Ÿ����.
������ SCC�� ����� �� �� �ȿ� ���� �������� ������������ ����Ѵ�.
���� ���� ���� SCC�� ���ؼ��� �� �ȿ� �����ִ� ���� ���� ������ ���� ��ȣ ������ ����Ѵ�.
*/




/*
solution:

scc�� ���ʹ����̴�
kosaju�˰������� Ǯ����.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<vector<int> > ori, rev, scc;
vector<int> order, group;
vector<bool> check;
void dfs(int now) {
	check[now] = true;
	for (int next : ori[now]) {
		if (!check[next])
			dfs(next);
	}
	order.push_back(now);
}

void make_scc(int now, int gnum) {
	check[now] = true;
	group[now] = gnum;
	for (int next : rev[now])
		if (!check[next])
			make_scc(next, gnum);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e;
	ori.resize(v + 1);
	rev.resize(v + 1);
	check.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		ori[x].push_back(y);
		rev[y].push_back(x);
	}
	for (int i = 1; i < v + 1; i++) {
		if (!check[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());
	check.clear();
	check.resize(v + 1);
	group.resize(v + 1);
	int gnum = -1;
	for (int now : order) {
		if (!check[now]) {
			gnum++;
			make_scc(now, gnum);
		}
	}
	cout << gnum + 1 << '\n';
	scc.resize(gnum + 1);
	for (int i = 1; i < v + 1; i++) {
		scc[group[i]].push_back(i);
	}
	for (auto i : scc) {
		sort(i.begin(), i.end());
	}
	sort(scc.begin(), scc.end());
	for (auto c : scc) {
		for (auto i : c) {
			cout << i << ' ';
		}
		cout << "-1\n";
	}
}