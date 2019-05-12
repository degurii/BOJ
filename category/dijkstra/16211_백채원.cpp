/*
�Է�
ù° �ٿ��� �츮���� �ִ� ������ �� N�� ������ �� M, ��ä���� �������� �� K�� ���ʴ�� �־�����. (1��N��200,000, 1��M��500,000, 1��K��N-1)
��° �ٺ��� M���� �ٿ� ���ʴ�� M���� �� ���ΰ� �մ� ������ ��ȣ A, B�� �� ���θ� ���� �� ������ ������ ���� �ɸ��� �ð� T�� �־�����. (1��A,B��N, 1��T��10,000, A��B, ���� ���ΰ� �� �� �־����� �ʴ´�.)
������ �ٿ��� ��ä���� �����ڵ��� ��� ������ ��ȣ�� ��Ÿ���� ���� �ٸ� �ڿ��� P1, ��, PK�� ������ ���̿� �ΰ� �־�����. (2 �� Pi �� N)

���
��ä���� ���� �� �� �ִ� ������ ��ȣ���� �� �ٿ� ������ ���̿� �ΰ� ������������ ����϶�.
���� �׷� ������ �ϳ��� ���ٸ�, ��� ���� 0�� ����Ѵ�.
��ä���� 1�� ������ ���� ������ ���� �ʴٴ� ���� �����϶�.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

struct Node {
	int to, cost;
};
int n, m, k;
vector<int> d1, d2;
vector<vector<Node>> p;
vector<int> dijkstra(vector<int> st) {
	priority_queue<pair<int, int>> q;
	vector<int> dist(2 * n, INF);
	vector<bool> chk(2 * n);

	for (int x : st)q.push({ 0, x }), dist[x] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();
		if (chk[now]) continue;
		chk[now] = true;

		for (auto e : p[now]) {
			int next = e.to;
			int ncost = e.cost;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	p.resize(n * 2);
	for (int i = 0; i < m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		p[x].push_back({ y, t });
		p[y].push_back({ x, t });
	}
	vector<int> temp;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		temp.push_back(x);
	}
	d1 = dijkstra(vector<int>(1, 1));
	d2 = dijkstra(temp);
	vector<int> ans;
	for (int i = 2; i < n + 1; i++) {
		if (d1[i] < d2[i]) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) cout << 0;
	else for (int x : ans)cout << x << ' ';
}