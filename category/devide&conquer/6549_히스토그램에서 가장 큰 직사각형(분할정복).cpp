/*
����
������׷��� ���簢�� ���� ���� �Ʒ������� ���ĵǾ� �ִ� �����̴�.
�� ���簢���� ���� �ʺ� ������ ������, ���̴� ���� �ٸ� ���� �ִ�.
������׷����� ���� ū ���簢���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �׽�Ʈ ���̽� ���� ���� �̷���� �ִ�.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���簢���� �� n�� ���� ó������ �־�����. (1 �� n �� 100,000)
�� ���� n���� ���� h1, ..., hn (0 �� hi �� 1000000000)�� �־�����.
�� ���ڵ��� ������׷��� �ִ� ���簢���� �����̸�, ���ʺ��� �����ʱ��� ������� �־�����.
��� ���簢���� �ʺ�� 1�̰�, �Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, ������׷����� ���� ū ���簢���� ���̸� ����Ѵ�.
*/


/*
solution:
���� ���̶�� �ʺ� ���� �� ���� ���� ū ���簢���̴�.
���� ���� ����� �翷���� �� �� �ִµ����� Ȯ���ϸ� �װ� �� ���̿��� ���� ū ���簢���̹Ƿ�
�� ����� �����ϰ� ����, ������ ������׷����� ���� ������ ��ĥ �� �ִ�.
�� �� ���� ū ���� ���ϸ� �ȴ�.

n���� ��� ��տ� ���� ���� ������ �ݺ��ϰԵǴµ�, 
���� ���� ����� ���� Ž������ ã���� ��������� O(N^2)�� �ð����⵵�� ���´�.
���� ���׸�Ʈ Ʈ���� �ּҰ��� ������ �ε����� ������ O(NlogN)�� �ð����⵵�� Ǯ �� �ִ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

void init(vector<ll> &p, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
	}
	else {
		init(p, tree, node * 2, start, (start + end) / 2);
		init(p, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		if (p[tree[node * 2]] < p[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

int query(vector<ll> &p, vector<int> &tree, int node, int start, int end, int i, int j) {
	if (end < i || start >j)
		return -1;
	else if (i <= start && end <= j)
		return tree[node];
	
	int q1 = query(p, tree, node * 2, start, (start + end) / 2, i, j);
	int q2 = query(p, tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (q1 == -1)
		return q2;
	else if (q2 == -1)
		return q1;
	else if (p[q1] < p[q2])
		return q1;
	else
		return q2;
}

ll go(vector<ll> &p, vector<int> &tree, int start, int end) {
	int n = p.size() - 1;
	int minidx = query(p, tree, 1, 1, n, start, end);
	ll ans = (end - start + 1)*p[minidx];
	if (start < minidx) {
		ans = max(ans, go(p, tree, start, minidx - 1));
	}
	if (minidx < end) {
		ans = max(ans, go(p, tree, minidx + 1, end));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {
		int n;
		cin >> n;
		if (n == 0) return 0;

		vector<ll> p(n + 1);

		for (int i = 1; i < n + 1; i++)
			cin >> p[i];
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));

		vector<int> tree(tree_size);
		
		init(p, tree, 1, 1, n);

		cout << go(p, tree, 1, n) << '\n';
	}
}






