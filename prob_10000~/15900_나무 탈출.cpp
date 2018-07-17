/*
����
�����̰� �� ������ �̱� �� ������ �������� �˷��ִ� ���α׷��� ����� �����̸� ��������.

�Է�
ù° �ٿ� Ʈ���� ���� ���� N(2 �� N �� 500,000)�� �־�����.
��° �ٺ��� N-1�ٿ� ���� Ʈ���� ���� ������ �־�����.
�ٸ��� �ΰ��� �ڿ��� a, b(1 �� a, b �� N, a �� b)�� �־����µ�, �̴� a�� b ���̿� ������ �����Ѵٴ� ���̴�.

���
�����̰� �ּ��� ������ �� �� ������ �̱� �� ������ Yes, �ƴϸ� No�� ����Ѵ�.
*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> p;
vector<bool> check;
int dfs(int now, int l) {
	check[now] = true;
	int cnt = 0;
	for (int next : p[now]) {
		if (!check[next])
			cnt += dfs(next, l + 1);
	}
	return cnt ? cnt : l;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	p.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	if (dfs(1, 0) & 1) cout << "Yes";
	else cout << "No";
}