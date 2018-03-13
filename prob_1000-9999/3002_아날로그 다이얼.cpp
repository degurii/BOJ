/*
����
����̴� ù ��° ���̸� ������ �ִ�. �� ��° ���̿� �� �ִ� ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� M�� �־�����. (1 �� N �� 250,000, 1 �� M �� 100,000)
��° �ٿ��� ���� ó���� ���̾� ǥ�õ� ���ڰ� �־�����. �� ���ڴ� ������� �־�����.
���� M�� �ٿ��� ����̰� �� ������ A�� B�� �־�����. (1 �� A �� B �� N)

���
����� �� M�� ���̴�. ����̰� ���� ���̾��� ���� ������� ����Ѵ�.
*/


/*
solution:
segment tree�� ������ 0~9������ �����Ѵ�
lazy propagation�� �̿��� update�ϸ�ȴ�
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int ndigit[10];
	Node() { memset(ndigit, 0, sizeof(ndigit)); }
	Node operator +(const Node &o) const {
		Node t(*this);
		for (int i = 0; i < 10; i++) {
			t.ndigit[i] += o.ndigit[i];
		}
		return t;
	}
};
int n, m;
vector<Node> tree;
vector<int> p, lazy;

void init(int node, int start, int end) {
	if (start == end) {
		tree[node].ndigit[p[start]]++;
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		int add = lazy[node];
		Node t;
		for (int i = 0; i < 10; i++) {
			int digit = (i + add) % 10;
			t.ndigit[digit] = tree[node].ndigit[i];
		}
		tree[node] = t;
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int i , int j) {
	update_lazy(node, start, end);
	if (start > j || end < i)
		return;
	if (i <= start && end <= j) {
		Node t;
		if (start != end) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		for (int i = 0; i < 10; i++) {
			t.ndigit[(i + 1) % 10] = tree[node].ndigit[i];
		}
		tree[node] = t;
		return;
	}
	update(node * 2, start, (start + end) / 2, i, j);
	update(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}



Node query(int node, int start, int end, int i, int j) {
	update_lazy(node, start, end);
	if (start > j || end < i) {
		Node t;
		return t;
	}
	else if (i <= start && end <= j) {
		return tree[node];
	}
	return query(node * 2, start, (start + end) / 2, i, j) + query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

void sum(Node a) {
	int res = 0;
	for (int i = 1; i < 10; i++) {
		res += a.ndigit[i] * i;
	}
	cout << res << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	p.resize(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	lazy.resize(tree_size);
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		p[i] = x - '0';
	}

	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		sum(query(1, 0, n - 1, a-1, b-1));
		update(1, 0, n - 1, a-1, b-1);
	}
}