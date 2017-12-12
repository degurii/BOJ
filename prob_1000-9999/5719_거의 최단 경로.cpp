/*
����
���� �ִ� ��ζ� �ִ� ��ο� ���Ե��� �ʴ� ���ηθ� �̷���� ��� �� ���� ª�� ���� ���Ѵ�.
���� �ִ� ��δ� ���� �� ������ ���� �ִ�. ��, ���� �ִ� ��ΰ� ���� ��쵵 �ִ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ����� �� N (2 �� N �� 500)�� ������ �� M (1 �� M �� 10^4)�� �־�����.
��Ҵ� 0���� N-1������ ��ȣ�� �Ű��� �ִ�.
��° �ٿ��� ������ S�� ������ D�� �־�����. (S �� D; 0 �� S, D < N)
���� M�� �ٿ��� ������ ���� U, V, P�� �־�����. (U �� V ; 0 �� U, V < N; 1 �� P �� 10^3)
�� ���� U���� V�� ���� ������ ���̰� P��� ���̴�.
U���� V�� ���� ���δ� �ִ� �� ���̴�. ��, U���� V�� ���� ���ο� V���� U�� ���� ���δ� �ٸ� �����̴�.

�Է��� ������ �ٿ��� 0�� �� �� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, ���� �ִ� ����� ���̸� ����Ѵ�. ����, ���� �ִ� ��ΰ� ���� ��쿡�� -1�� ����Ѵ�.
*/







/*
solution:
���� �׷����¸� ori, ��� ������ �ݴ�������� ������ �׷����� rev�� �Ѵ�.
ori���� ���ͽ�Ʈ��(s���� ����)�� �̿��� s���� �� �������� �ִܰŸ��� ���� �� �ִ�.
�� �ִܰŸ� ������ dist1�̶� �Ѵ�.
rev���� ���ͽ�Ʈ��(d���� ����)�� �̿��� �� ��忡�� d������ �ִܰŸ��� ���� �� �ִ�.
�� �ִܰŸ� ������ dist2�� �Ѵ�.
������ rev�� ������ �ʴ´�.

s�������� bfs�� ������
�� ���� u���� ���� ���� v�� Ȯ���� ��,
dist1[v]+dist2[v] == (s->d������ �ִܰŸ�)�̸� ���� (u, v)�� �ִܰ�ο� ���յ� ����̹Ƿ� üũ�صд�.

�׷����� ó������ Ȯ���ϸ鼭 üũ������ ���� ������ ��� ���� �׷����� �����.
�� ��, ���ο� �׷����� s���� d������ �ִܰŸ��� ���� �ȴ�.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int> >;
using vvb = vector<vector<bool> >;

int n, m;
int s, d;
struct Node {
	int u, w;
	Node(int u = 0, int w = 0) :u(u), w(w) {}
};

vector<int> dijkstra(vector<vector<Node> > &p, int now) {
	vb check(n);
	vi dist(n, INF);
	priority_queue<pair<int, int> > q;
	dist[now] = 0;
	q.push({ 0, now });
	while (!q.empty()) {
		now = q.top().second;
		q.pop();
		if (check[now]) continue;
		check[now] = true;
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i].u;
			int ncost = p[now][i].w;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -dist[next], next });
			}
		}
	}
	return dist;
}

void rm_e(vector<vector<Node> > &p, vvb &e, vi &d1, vi &d2, int mind) {
	vb check(n);
	queue<int> q;
	check[s] = true;
	q.push(s);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0, l = p[now].size(); i < l; i++) {
			int next = p[now][i].u;
			
			if (d1[next] + d2[next] == mind) {	
				if (check[next] == false) {
					check[next] = true;
					q.push(next);
				}
				e[now][next] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m, (n != 0 & m != 0)) {
		vector<vector<Node> > ori(n), rev(n);
		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			ori[u].push_back(Node(v, w));
			rev[v].push_back(Node(u, w));
		}

		vi dist1 = dijkstra(ori, s);
		vi dist2 = dijkstra(rev, d);
		if (dist1[d] == INF) {
			cout << -1 << '\n';
			continue;
		}
		vvb check(n, vb(n));
		rm_e(ori, check, dist1, dist2, dist1[d]);
		
		vector<vector<Node> > p(n);
		for (int now = 0; now < n; now++) {
			for (int j = 0, l = ori[now].size(); j < l; j++) {
				int next = ori[now][j].u;
				int ncost = ori[now][j].w;
				if (!check[now][next]) {
					p[now].push_back(Node(next, ncost));
				}
			}
		}
		vi ans = dijkstra(p, s);
		if (ans[d] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << ans[d] << '\n';
		}
	}
}