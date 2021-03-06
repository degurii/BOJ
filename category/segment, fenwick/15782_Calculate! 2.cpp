/*
문제
제 3회 IUPC의 Calculate! 에서 교정이는 인규가 질문한 모든 논리연산에 대한 정답을 말하였다.
그 후 1년 뒤 제 4회 IUPC가 열리게 되었고, 인규는 이번에는 교정이를 꼭 골탕 먹이겠다는 생각을 갖고
교정이가 빠르게 대답을 못할만한 어려운 논리연산 문제를 준비했다.

인규가 준비한 문제는 다음과 같다.

정점이 N(≤ 100,000)개인 트리가 주어진다. 루트는 항상 1번 정점이다. (트리란 N개의 정점과 N-1개의 간선으로 이루어 진 사이클이 존재하지 않는 하나의 컴포넌트를 가지는 연결 그래프이다)
각 정점은 가중치 D(0 ≤ D ≤ 10,000)를 가진다.
M(≤ 500,000)개의 질의가 주어진다.
1 x 꼴로 주어지는 질의에는 정점 x를 포함한 x의 모든 자손들의 가중치를 전부 XOR한 값을 출력.
2 x y 꼴로 주어지는 질의에는 정점 x를 포함한 x의 모든 자손들의 가중치에 각각 y(0 ≤ y ≤ 10,000)를 XOR을 함.
인규의 문제에 대한 교정이의 답변이 맞는지 확인하기 위하여 1 x 꼴로 주어지는 질의에 대한 답을 출력하는 프로그램을 작성해보자

입력
입력의 첫째 줄에 정점의 수 N(3 ≤ N ≤ 100,000)와 질의의 수 M(3 ≤ M ≤ 500,000)이 주어진다.
이 후 N-1줄에 A,B가 주어진다. 이는 A와 B가 연결되어 있다는 뜻이다.
다음 줄에 공백으로 분리 된 N개의 수가 주어진다.
i번 째 수는 i번 째 정점의 가중치를 의미한다. 이후 M개의 줄에 질의가 주어진다.

출력
M개의 질의 중, 1 x 꼴로 주어지는 질의에 대한 답을 한줄 씩 출력한다.
*/


/*
solution:
입력트로 주어진 트리의 각 노드를 리프노드로 하여 세그먼트 트리를 만든다.
이때 각 노드의 자식의 수를 저장하고 postorder순으로 리프노드에 배치하면 빠르게 query 구간을 잡을 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> seg_tree, lazy, p(1), weight;
vector<vector<int>> ori_tree;
int n, m, numChild[100001], numbering[100001];
bool check[100001];

int init_seg_data(int now) {
	check[now] = true;
	int child = 0;
	for (int next : ori_tree[now]) {
		if(!check[next])
			child += init_seg_data(next);
	}
	numbering[now] = p.size();
	p.push_back(weight[now]);
	numChild[now] = child;
	return child + 1;
}

void init_seg_tree(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = p[start];
	}
	else {
		init_seg_tree(node * 2, start, (start + end) / 2);
		init_seg_tree(node * 2 + 1, (start + end) / 2 + 1, end);
		seg_tree[node] = seg_tree[node * 2] ^ seg_tree[node * 2 + 1];
	}
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		if ((end - start + 1) & 1)
			seg_tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}
void update_range(int node, int start, int end, int i, int j, int diff) {
	update_lazy(node, start, end);
	if (start > j || end < i)
		return;
	else if (i <= start && end <= j) {
		if ((end - start + 1) & 1)
			seg_tree[node] ^= diff;
		if (start != end) {
			lazy[node * 2] ^= diff;
			lazy[node * 2 + 1] ^= diff;
		}
		return;
	}
	update_range(node * 2, start, (start + end) / 2, i, j, diff);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, i, j, diff);
	seg_tree[node] = seg_tree[node * 2] ^ seg_tree[node * 2 + 1];
}
int query(int node, int start, int end, int i, int j) {
	update_lazy(node, start, end);
	if (start > j || end < i)
		return 0;
	else if (i <= start && end <= j) {
		return seg_tree[node];
	}
	return query(node * 2, start, (start + end) / 2, i, j) ^ query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	weight.resize(n + 1);
	ori_tree.resize(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	seg_tree.resize(tree_size);
	lazy.resize(tree_size);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		ori_tree[u].push_back(v);
		ori_tree[v].push_back(u);
	}
	for (int i = 1; i < n + 1; i++) {
		cin >> weight[i];
	}
	init_seg_data(1);

	init_seg_tree(1, 1, n);
	
	while (m--) {
		int cmd, x, y;
		cin >> cmd;
		if (cmd == 1) { // x포함 자손들의 가중치의 XOR값 출력
			cin >> x;
			cout << query(1, 1, n, numbering[x] - numChild[x], numbering[x]) << '\n';
		}
		else if (cmd == 2) { // 구간업데이트, y를 XOR
			cin >> x >> y;
			update_range(1, 1, n, numbering[x] - numChild[x], numbering[x], y); 
			
		}
	}
}