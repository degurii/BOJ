/*
입력
In the first line of the standard input there is a positive integer n ≤ 30,000. It is the number of elements of the sequence B.
In each of the following n lines there is one nonnegative integer not greater than 30,000. It is the successive element of the sequence B.
출력
The standard output should contain:
in each of n consecutive lines - one element of the permutation A, whose code is the sequence B written in the standard input,
one word NIE, if the sequence B is not a code of any permutation.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> ans, b, p, tree;
int n;

int init(int node, int start, int end) {
	if (start == end) {
		tree[node] = p[start];
		return tree[node];
	}
	return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

int query(int node, int start, int end, int i, int j) {
	if (i > j)
		return 0;
	if (j < start || end < i)
		return 0;
	if (i <= start && end <= j)
		return tree[node];
	return query(node * 2, start, (start + end) / 2, i, j) + query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

void update(int node, int start, int end, int idx, int diff) {
	if (start <= idx && idx <= end) {
		tree[node] += diff;
		if (start != end) {
			update(node * 2, start, (start + end) / 2, idx, diff);
			update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
		}
	}
}

int lower(int l, int r, int goal) {
	int an = 0x3f3f3f3f;
	int an_idx = 0x3f3f3f3f;
	while (l <= r) {
		int mid = (l + r) / 2;
		int sum = query(1, 1, n, mid + 1, n);

		if (sum <= goal) {
			if (sum == goal) {
				an = sum;
				an_idx = mid;
			}
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	if (an != goal || p[an_idx] == 0)
		return -1;

	update(1, 1, n, an_idx, -1);
	p[an_idx] = 0;
	return an_idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	p.resize(n + 1, 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	init(1, 1, n);
	reverse(b.begin(), b.end());
	for (auto it : b) {
		ans.push_back(lower(1, n, it));
		if (ans.back() == -1) {
			cout << "NIE";
			return 0;
		}
	}

	reverse(ans.begin(), ans.end());
	for (auto it : ans) {
		cout << it << '\n';
	}

	return 0;
}