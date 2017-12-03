/*
����
���̳�� ��մ�. ���̳� ����� �Ϸķ� ��� �þ�� �� ��� �ϳ��� �Ѿ�߸���
�� ����� �Ѿ����� ���� ����� �Ѿ�߸��� ���� �ݺ��Ǿ� �Ϸķ� �þ ��ϵ��� ���������� ��� �����߸� �� �ִ�.
�׷���, ������ ���̳밡 �ٸ� ����� �Ѿ�߸��� ���ϰ� ��ġ�Ǿ� �ִٸ�, �츮�� ���� ����� �������� �Ѿ�߷��� �Ѵ�.
���� �� ���̳� ����� ��ġ�� �־����� ��, ��� ����� �Ѿ�߸��� ���� ������ �Ѿ�߷��� �ϴ� ��� ������ �ּҰ��� ������.

�Է�
ù ��° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.
�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �� ���� N, M�� �־����� �� ���� 100,000�� ���� �ʴ´�.
N�� ���̳��� ������, M�� ������ ������ ��Ÿ����. ���̳� ����� ��ȣ�� 1�� N ������ ������.
���� M���� �ٿ��� ���� �� ���� x, y�� �־����µ�, �̴� x�� ����� �Ѿ����� y�� ��ϵ� �Ѿ����� ���Ѵ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ���� �ϳ��� ����Ѵ�.
������ ������ �Ѿ�߷��� �ϴ� �ּ��� ���̳� ��� �����̴�.
*/






/*
ó���� ���� �������� ������ �� �˾Ҵµ� �ƴϿ���
scc�� ���� �� ������ ����Ŭ���γ��� ����� indegree�� ���ְ�,
�� scc�� ���Ե� �� ��� ��ü�� ind�� 0�̸� ���� ������ �Ѱܾ� �ϴ� ���̳��̴�.
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