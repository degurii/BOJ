/*
������ �����̴� ����̿��� ��Ʈ�� ����� ����ߴ�. ����̴� �ڽ��� ���� �Ƿº��� �ڵ� �Ƿ��� �� �ϴ´�.
����̸� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� N�� ������ ���� �� K�� �־�����. (1 �� N, K �� 105)
��° �ٿ��� �� N���� ���� Xi�� �־�����. (-100 �� Xi �� 100)
���� K�� �ٿ��� �����̰� ���� ����� �־�����. ����� C �Ǵ� P�� �����Ѵ�.
C�� �����ϴ� ����� ���� ����̰�, �� ������ i�� V�� �־�����. Xi�� V�� �����ϴ� ����̴�. (1 �� i �� N, -100 �� V �� 100)
P�� �����ϴ� ����� ���� ����̰�, �� ������ i�� j�� �־�����. (1 �� i �� j �� N)
�� �׽�Ʈ ���̽��� ���� ����� �׻� �� �� �̻��ִ�.

���
�� �׽�Ʈ ���̽����� ���� ����� ����� �� �ٿ� ��� ����ϸ� �ȴ�.
����ϴ� i��° ���ڴ� i��° ���� ����� ����̴�.
����� ��쿡�� +, ������ ��쿡�� -, ���� ��쿡�� 0�� ����Ѵ�.
*/






/*
solve:
�׳� ���׸�Ʈ Ʈ�� ����ó�� �����
���, ����, 0�� ������ �����ϴ� Node sturcture�� �����
tree�� �ڷ������� �� ������ ���, ����, 0�� ������ �����ߴ�.

¥���� �����ϴ� ���� �׷��� ���ϰ�
�׶� �׶� ������ ���ϰ� �����ϸ� ���� �� ����.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
	int p, z, n;
	Node(int a = 0, int b = 0, int c = 0) :p(a), z(b), n(c) {}
	Node operator + (const Node &e)const {
		Node t(p, z, n);
		t.p += e.p;
		t.z += e.z;
		t.n += e.n;
		return t;
	}
	bool operator == (const Node &e)const {
		return (p == e.p && z == e.z && n == e.n);
	}
	Node operator - (const Node &e)const {
		Node t(p, z, n);
		t.p -= e.p;
		t.z -= e.z;
		t.n -= e.n;
		return t;
	}
};
int n, k;

void init(vector<int> &p, vector<Node> &tree, int node, int start, int end) {
	if (start == end) {
		int po = 0, z = 0, n = 0;
		if (p[start] > 0)po++;
		else if (p[start] == 0)z++;
		else n++;
		tree[node] = Node(po, z, n);
	}
	else {
		init(p, tree, node * 2, start, (start + end) / 2);
		init(p, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

Node query(vector<Node> &tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start)
		return Node(0, 0, 0);
	if (i <= start && end <= j)
		return tree[node];
	return (query(tree, node * 2, start, (start + end) / 2, i, j) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}

void update(vector<Node> &tree, int node, int start, int end, int idx, Node diff) {
	if (start <= idx && idx <= end) {
		tree[node] = tree[node] + diff;
		if (start != end) {
			update(tree, node * 2, start, (start + end) / 2, idx, diff);
			update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n) {
		cin >> k;
		int tree_size = (1 << ((int)ceil(log2(n)) + 1));
		vector<int> p(n + 1);
		vector<Node> tree(tree_size);
		for (int i = 1; i < n + 1; i++)
			cin >> p[i];
		init(p, tree, 1, 1, n);
		
		for (int i = 0; i < k; i++) {
			char c;
			cin >> c;
			if (c == 'C') {
				int idx, v;
				cin >> idx >> v;
				Node modi, ori;
				if (v > 0) modi.p = 1;
				else if (v < 0)modi.n = 1;
				else modi.z = 1;
				if (p[idx] > 0) ori.p++;
				else if (p[idx] < 0) ori.n++;
				else ori.z++;
				p[idx] = v;
				Node diff = modi - ori;
				update(tree, 1, 1, n, idx, diff);
			}
			else {
				int i, j;
				cin >> i >> j;
				Node t = query(tree, 1, 1, n, i, j);
				if (t.z) cout << 0;
				else if (t.n % 2 != 0) cout << '-';
				else cout << '+';
			}
		}
		cout << '\n';
	}
}