/*
����
���� �÷��̿� ���� �ð��� ��Ȳ�� ���� �ٸ� �� �ֱ� ������, ��� �ǹ��� ���µ� �ɸ��� �ּ��� �ð��� �̿��Ͽ� �ٻ��ϱ�� �Ͽ���.
����, � �ǹ��� ���� ���ؼ� �ٸ� �ǹ��� ���� ����� �� ���� �ֱ� ������ ������ �ܼ��������� ���� ���� �ִ�.
���� ��� ��Ÿũ����Ʈ���� ��Ŀ�� ���� ���ؼ��� �跰�� ���� ����� �ϱ� ������, �跰�� ���� ���� �� ��Ŀ�� ����� �Ѵ�.
���ǻ� �ڿ��� ������ ���� ������ �ְ�, �ǹ��� ���� ����� ����������� �ð��� �ɸ��� �ʴ´ٰ� ��������.

�Է�
ù° �ٿ� �ǹ��� ���� �� N(1��N��500)�� �־�����.
���� N���� �ٿ��� �� �ǹ��� ���µ� �ɸ��� �ð��� �� �ǹ��� ���� ���� ���� �������� �ϴ� �ǹ����� ��ȣ�� �־�����.
�ǹ��� ��ȣ�� 1���� N������ �ϰ�, �� ���� -1�� �����ٰ� ����.

���
N���� �� �ǹ��� �ϼ��Ǳ���� �ɸ��� �ּ� �ð��� ����Ѵ�.
*/









/*
solution:
boj 1005�� acm craft�� ���� ����
https://github.com/degurii/BOJ/blob/master/prob_1000-9999/1005_ACM%20Craft.cpp

�ٸ����� indgree�� ���� �˷����� �ʰ�
���� ���� -1�� ���� ������ ������ ó���������
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n;
vector<vector<int> > p(501);
int cost[501], dist[501], ind[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> cost[i];
		int x;
		while (cin >> x, x != -1) {
			p[x].push_back(i);
			ind[i]++;
		}
	}
	vector<bool> check(n + 1);
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (ind[i] == 0) {
			check[i] = true;
			q.push(i);
			dist[i] = cost[i];
		}
	}
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i];
			if (check[next] == false) {
 				dist[next] = max(dist[next], dist[now] + cost[next]);
				if (--ind[next] == 0) {
					check[next] = true;
					q.push(next);
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		cout << dist[i] << '\n';
	}
}