/*
����
���ǻ��� ���͵鿡�� ������ �̷��� �� �� �ִ� �����밡 �ϳ��� ��ġ�Ǿ� �ִ�.
Corea�� �ִ��� ���� ���͸� �湮�ؼ� ������ �̷��� ���� ���� Unused���� ���� �ֱ�� �ߴ�.
���ǻ��� ������ �־��� ��, Corea�� ������ ���Ϳ��� ����ؼ� ���� ���� �� �ִ� �� ���� ���͸� �湮�� �� �ִ��� ���Ͽ���.

�Է�
ù ��° �ٿ� ���ο� �ִ� ������ �� N(2 �� N �� 5, 000)�� �� ���� ���̸� �����ϴ� ���� �� M(1 �� M �� 100, 000)�� �־�����.
�� ��° �ٿ��� �� ������ ���̸� ��Ÿ���� N���� ������ ��ȣ ������� �־�����.�� ������ ���̴� 1 �̻� 1, 000, 000 �����̸� ���� �ٸ���.
�� ��° �ٺ��� M���� �ٿ� ���� ������ ���� �����ϴ� �� ������ ��ȣ�� �������� ���еǾ� �־�����
������ ��ȣ�� 1 �̻� N ������ �����̴�. �� ������ ���� ������ ���� ������, ������ �� ���͸� �����ϴ� ���� ���� �� ������ �� �ִ�.

���
N���� �ٿ� ���� n��° �ٿ� Corea�� n�� ���Ϳ��� ����ؼ� ���� ���� �� �ִ�� �湮�� �� �ִ� ������ ������ ����Ѵ�.
*/





/*
bfsó�� ���ܼ� ��̴µ� ��� dp������
2017 icpc���������� ���� ����� ������ ���Ծ���
���������� �������� ���Ǹ�

solve:
���� �������� ���������� update�� �Ѵ�
dist�� �ڽź��� ���� ��ġ�� �ִ� ���͵��� �ִ밳��

** ������������ �ݺ��� �����°� �������ķ� �ذ��ص� �ȴ� **
** �׷� ���� ������ sorting���ص� �� **

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int n, m;
vector<vector<int> > p;
vector<pair<int, int> > sorted;
vector<int> dist, h;

void update(int now) {
	for (int &next : p[now]) {
		if (h[now] < h[next]) {
			dist[now] = max(dist[now], dist[next] + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	h.resize(n + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> h[i];
		sorted.push_back({ h[i], i });
	}
	dist.resize(n + 1, 1);
	p.resize(n + 1);
	sort(sorted.begin(), sorted.end(), greater<pair<int, int> >());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (auto it : sorted) {
		update(it.second);
	}
	for (int i = 1; i < n + 1; i++) {
		cout << dist[i] << '\n';
	}
}