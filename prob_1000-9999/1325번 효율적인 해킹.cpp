/*
����
��Ŀ �������� �� �˷��� ��� ȸ�縦 ��ŷ�Ϸ��� �Ѵ�. �� ȸ��� N���� ��ǻ�ͷ� �̷���� �ִ�.
�������� ������ ������, �� ���� ��ŷ���� ���� ���� ��ǻ�͸� ��ŷ �� �� �ִ� ��ǻ�͸� ��ŷ�Ϸ��� �Ѵ�.
�� ȸ���� ��ǻ�ʹ� �ŷ��ϴ� �����, �ŷ����� �ʴ� ����� �̷���� �ִµ�, A�� B�� �ŷ��ϴ� ��쿡�� B�� ��ŷ�ϸ�, A�� ��ŷ�� �� �ִٴ� �Ҹ���.
�� ȸ���� ��ǻ���� �ŷ��ϴ� ���谡 �־����� ��, �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ�, N�� M�� ���´�. N�� 10,000���� �۰ų� ���� �ڿ���, M�� 100,000���� �۰ų� ���� �ڿ����̴�.
��° �ٺ��� M���� �ٿ� �ŷ��ϴ� ���谡 A B�� ���� �������� ������, "A�� B�� �ŷ��Ѵ�"�� �ǹ��Ѵ�.

���
ù° �ٿ�, �������� �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ������������ ����Ѵ�.
*/



/*
sovle:
�ð������� 5���ΰ� ������ �̰� ��� Ǫ�� �Ӹ� �θŴٰ� �ܿ� Ǭ �����̴�.
�ð��� �γ��ϴ� ��� ��忡�� bfs�� ���� �ִ񰪵��� ã���ָ� �ȴ�.

scc(strongly connected component)������� �ϴµ�, ���߿� �����ؼ� �ٽ� Ǯ������� ��.
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

vector<vector<int> > p;
vector<bool> check;
vector<int> dist;
int n, m;

void bfs(int now, int &cur) {
	queue<int> q;
	check[now] = true;
	q.push(now);
	
	while (!q.empty()) {
		now = q.front();
		q.pop();
		cur++;
		for (int &next : p[now]) {
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	p.resize(n + 1); check.resize(n + 1); dist.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[v].push_back(u);
	}
	
	int maxi = 0;
	vector<int> ans;
	for (int i = 1; i < n + 1; i++) {
		int cur = 0;
		bfs(i, cur);
		if (maxi < cur) {
			maxi = cur;
			ans = vector<int>(1, i);
		}
		else if(maxi == cur){
			ans.push_back(i);
		}
		check = vector<bool>(n + 1);
	}
	for (int it : ans)
		cout << it << ' ';
}