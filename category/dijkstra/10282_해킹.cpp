/*
����
�����־��� ��Ŀ yum3�� ��Ʈ��ũ �ü��� �� ��ǻ�͸� ��ŷ�ߴ�! ���� ���ο� �����ϴ� ��ǻ�͵��� ���� �ϳ��� �����Ǳ� �����Ѵ�. � ��ǻ�� a�� �ٸ� ��ǻ�� b�� �����Ѵٸ�, b�� �����Ǹ� �׷κ��� ���� �ð� �� a�� �����ǰ� ����. �̶� b�� a�� �������� �ʴ´ٸ�, a�� �����Ǵ��� b�� �����ϴ�.
�����־��� ��Ŀ yum3�� ��ŷ�� ��ǻ�� ��ȣ�� �� �������� �־��� ��, ��ŷ���� ��ǻ�ͱ��� �����Ͽ� �� �� ���� ��ǻ�Ͱ� �����Ǹ� �׿� �ɸ��� �ð��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� ������ �ִ� 100���̴�. �� �׽�Ʈ ���̽��� ������ ���� �̷���� �ִ�.

ù° �ٿ� ��ǻ�� ���� n, ������ ���� d, ��ŷ���� ��ǻ���� ��ȣ c�� �־�����(1 �� n �� 10,000, 1 �� d �� 100,000, 1 �� c �� n).
�̾ d���� �ٿ� �� �������� ��Ÿ���� ���� a, b, s�� �־�����(1 �� a, b �� n, a �� b, 0 �� s �� 1,000). �̴� ��ǻ�� a�� ��ǻ�� b�� �����ϸ�, ��ǻ�� b�� �����Ǹ� s�� �� ��ǻ�� a�� �������� ���Ѵ�.
�� �׽�Ʈ ���̽����� ���� ������ (a, b)�� �� �� �̻� �������� �ʴ´�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ���� �� �����Ǵ� ��ǻ�� ��, ������ ��ǻ�Ͱ� �����Ǳ���� �ɸ��� �ð��� �������� �������� ����Ѵ�.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
	int to, cost;
	Node(int t = 0, int c = 0) :to(t), cost(c) {}
};
int n, d, c;
int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		vector<vector<Node> > p(n + 1);
		for (int i = 0; i < d; i++) {
			int u, v, o;
			cin >> u >> v >> o;
			p[v].push_back(Node(u, o));
		}
		vector<bool> check(n + 1);
		vector<int> dist(n + 1, INF);
		dist[c] = 0;
		priority_queue<pair<int, int> > q;
		q.push({ 0, c });
		while (!q.empty()) {
			int now = q.top().second;
			q.pop();
			if (check[now]) continue;
			check[now] = true;
			for (auto node : p[now]) {
				int next = node.to;
				int ncost = node.cost;
				if (dist[next] > dist[now] + ncost) {
					dist[next] = dist[now] + ncost;
					q.push({ -dist[next], next });
				}
			}
		}
		int num = 0, maxDist = 0;
		for (int i = 1; i < n + 1; i++) {
			if (dist[i] != INF) {
				num++;
				if (maxDist < dist[i])
					maxDist = dist[i];
			}
		}
		cout << num << ' ' << maxDist << '\n';
	}
}