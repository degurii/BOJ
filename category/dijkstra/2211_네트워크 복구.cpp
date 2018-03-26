/*
������ ��Ʈ��ũ�� ���� ������ �־����� ��, ���� ������ �����ϸ鼭 ��Ʈ��ũ�� �����ϴ� ����� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� N, M�� �־�����. ���� M���� �ٿ��� ȸ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����.
�̴� A�� ��ǻ�Ϳ� B�� ��ǻ�Ͱ� ��� �ð��� C (1 �� C �� 10)�� ȸ������ ����Ǿ� �ִٴ� �ǹ��̴�.
��ǻ�͵��� ��ȣ�� 1���� N������ �����̸�, 1�� ��ǻ�ʹ� ���� �ý����� ��ġ�� ������ǻ���̴�.
C���� �׻� ����̴�. ���� ��� ����� �����ֹ��� ������� �̷������ ������, �� ȸ������ ����� �� ��ǻ�ʹ� ��� �������ε� ����� �� �ִ�.

���
ù° �ٿ� ������ ȸ���� ���� K�� ����Ѵ�.
���� K���� �ٿ��� ������ ȸ���� ��Ÿ���� �� ���� A, B�� ����Ѵ�.
�̴� A�� ��ǻ�Ϳ� B�� ��ǻ�͸� �����ϴ� ȸ���� �����Ѵٴ� �ǹ��̴�.
����� ������ ������� �ϸ�, ���� ���� �� �����ϴ� ��쿡�� �ƹ� ���̳� �ϳ��� ����ϸ� �ȴ�.
*/


/*
solution:
1�������� �ִܰŸ��� �� �� �ִ� �������� ����ϸ� �ȴ�.
n�� �������� �ִܰŸ��� �մ� �������� n-1���̹Ƿ� n-1�� ������� ��
���ͽ�Ʈ�� ������� �߿��� ������ true�� �� ������ ���������� ��������(=��������)�� ����Ѵ�.
*/


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
	int to, cost;
	Node(int t = 0, int c = 0) :to(t), cost(c) {}
};
int n, m;
vector<vector<Node> > p;
bool check[10001];
int dist[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	cout << n - 1 << '\n';
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		p[u].push_back(Node(v, c));
		p[v].push_back(Node(u, c));
	}
	fill(dist + 1, dist + n + 1, INF);
	dist[1] = 0;
	priority_queue<pair<int, pair<int, int> > > q;
	q.push({ 0, {1, 1} });
	while (!q.empty()) {
		int now = q.top().second.first;
		int prev = q.top().second.second;
		q.pop();
		if (check[now]) continue;
		if(now != 1)
			cout << prev << ' ' << now << '\n';
		check[now] = true;
		
		for (auto it : p[now]) {
			int next = it.to;
			int ncost = it.cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], {next, now} });
			}
		}
	}
}