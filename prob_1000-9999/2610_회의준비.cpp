/*
����
KOI �غ� ���� ȸ�Ǹ� �����Ϸ� �Ѵ�. ������������ ȸ�ǿ� �����ϴ� ����� ���� �����ڵ� ������ ���踦 ���� �ϳ� �̻��� ����ȸ�� �����Ϸ��� �Ѵ�.
����ȸ�� �����ϴ� ����� ������ ����.

���� �˰� �ִ� ����� �ݵ�� ���� ����ȸ�� ���ؾ� �Ѵ�.
ȿ������ ȸ�� ������ ���� ����ȸ�� ���� �ִ밡 �Ǿ�� �Ѵ�.
�̷� ������� ����ȸ�� ������ �Ŀ� �� ����ȸ�� ��ǥ�� �� �� �̾ƾ� �Ѵ�.
�� ����ȸ�� ��ǥ���� ȸ�� �ð� �� �߾���� ������,
���� ȸ�� �����ڵ��� �ڽ��� �ǰ��� ���ϱ� ���ؼ��� �ڽ��� ���� ����ȸ�� ��ǥ���� �ڽ��� �ǰ��� �����ؾ� �Ѵ�.
�׷��� �� �����ڴ� �ڽ��� �˰� �ִ� ������Ը� �ǰ��� ������ �� �־� ��ǥ���� �ǰ��� �����ϱ� ���ؼ��� ���� ���� ����� ���ľ� �Ѵ�.
��ǥ���� �ǰ��� �����ϴ� ��ΰ� ���� �� �ָ� ��쿡�� ���� ���� ����� ��ġ�� ��η� �ǰ��� �����ϸ�
�� �� ��ġ�� ����� ���� �������� �ǻ����޽ð��̶�� �Ѵ�.

����ȸ���� ��� �����ڵ��� �ǻ����޽ð� �� �ִ밪�� �ּҰ� �ǵ��� ��ǥ�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �߿� ȸ�ǿ� �����ϴ� ����� �� N�� �־�����. �����ڵ��� 1���� N������ �ڿ����� ǥ���Ǹ� ȸ�ǿ� �����ϴ� �ο��� 100 �����̴�.
��° �ٿ��� ���� �˰� �ִ� ������ �� M�� �־�����.
�̾� M���� �� �ٿ��� ���� �ƴ� ������ �����ڸ� ��Ÿ���� �ΰ��� �ڿ����� �־�����.

���
ù° �ٿ��� �����Ǵ� ����ȸ�� �� K�� ����Ѵ�.
���� K�ٿ��� �� ����ȸ�� ��ǥ ��ȣ�� ���� ������ ���ʷ� �� �ٿ� �ϳ��� ����Ѵ�.
�� ����ȸ�� ��ǥ�� �� �� �ִ� ����� �� �̻��� ��� ���� �� �� ����ϸ� �ȴ�.
*/





/*
solution:
(d[i][j] == 1) -> i�� j�� ���� �˰��ִ�.
(d[i][j] == k) -> i�� j�� k���� �ǳ� �˰��ִ�.

�÷��̵�-������ ������
���� �˰��ִ� �����̸� ���� �׷쿡 ��������
���� ���Ѵ�.
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
