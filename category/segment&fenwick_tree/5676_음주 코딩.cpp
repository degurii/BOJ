/*
다행히 선영이는 상근이에게 노트북 사용을 허락했다. 상근이는 자신의 수학 실력보다 코딩 실력을 더 믿는다.
상근이를 도우는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 수열의 크기 N과 게임의 라운드 수 K가 주어진다. (1 ≤ N, K ≤ 105)
둘째 줄에는 총 N개의 숫자 Xi가 주어진다. (-100 ≤ Xi ≤ 100)
다음 K개 줄에는 선영이가 내린 명령이 주어진다. 명령은 C 또는 P로 시작한다.
C로 시작하는 명령은 변경 명령이고, 그 다음에 i와 V가 주어진다. Xi를 V로 변경하는 명령이다. (1 ≤ i ≤ N, -100 ≤ V ≤ 100)
P로 시작하는 명령은 곱셈 명령이고, 그 다음에 i와 j가 주어진다. (1 ≤ i ≤ j ≤ N)
각 테스트 케이스에 곱셈 명령은 항상 한 번 이상있다.

출력
각 테스트 케이스마다 곱셈 명령의 결과를 한 줄에 모두 출력하면 된다.
출력하는 i번째 문자는 i번째 곱셈 명령의 결과이다.
양수인 경우에는 +, 음수인 경우에는 -, 영인 경우에는 0을 출력한다.
*/






/*
solve:
그냥 세그먼트 트리 문제처럼 생겼다
양수, 음수, 0의 개수를 저장하는 Node sturcture를 만들어
tree의 자료형으로 써 구간의 양수, 음수, 0의 개수를 저장했다.

짜고나서 생각하니 굳이 그렇게 안하고
그때 그때 값들을 곱하고 저장하면 됐을 것 같다.
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