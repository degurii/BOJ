/*
����
Ư���ǹ��� ���� ���� ���� ������ �ɸ��� �ּҽð��� �˾Ƴ��� ���α׷��� �ۼ�������.

�Է�
ù° �ٿ��� �׽�Ʈ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �־�����.
ù° �ٿ� �ǹ��� ���� N �� �ǹ����� �Ǽ�������Ģ�� �� ���� K�� �־�����. (�ǹ��� ��ȣ�� 1������ N������ �����Ѵ�)
��° �ٿ��� �� �ǹ��� �Ǽ��� �ɸ��� �ð� D�� ������ ���̷� �־�����.
��° �ٺ��� K+2�ٱ��� �Ǽ����� X Y�� �־�����. (�̴� �ǹ� X�� ���� ������ �ǹ� Y�� ���� ���� �����ϴٴ� �ǹ��̴�)

������ �ٿ��� �����̰� �¸��ϱ� ���� �Ǽ��ؾ� �� �ǹ��� ��ȣ W�� �־�����. (1 �� N �� 1000, 1 �� K �� 100000 , 1�� X,Y,W �� N, 0 �� D �� 1000)

���
�ǹ� W�� �Ǽ��Ϸ� �ϴµ� ��� �ּ� �ð��� ����Ѵ�. ���ǻ� �ǹ��� ���� ����� ������ ���� �ð��� �ҿ���� �ʴ´ٰ� �����Ѵ�.
��� �ǹ��� ���� �� ���� ���� ����.
*/




/*
solution:
����� �������� ����

���������� �ϸ鼭 �� �ð��� ���� ū ������ ������Ʈ�� �Ѵ�
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int n, k, w;
vector<vector<int> > p;
vector<int> dist, times, indeg;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		dist.clear();
		times.clear();
		indeg.clear();
		p.clear();
		
		cin >> n >> k;
		dist.resize(n + 1);
		times.resize(n + 1);
		indeg.resize(n + 1);
		p.resize(n + 1);
		for (int i = 1; i < n + 1; i++) {
			cin >> times[i];
		}
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			indeg[v]++;
		}
		cin >> w;
		
		queue<int> q;
		for (int i = 1; i < n + 1; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				dist[i] = times[i];
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (now == w) break;
			
			for (int &next : p[now]) {
				if (--indeg[next]== 0)
					q.push(next);
				if (dist[next] < dist[now] + times[next]) {
					dist[next] = dist[now] + times[next];
				}
			}
		}
		cout << dist[w] << '\n';
	}
}