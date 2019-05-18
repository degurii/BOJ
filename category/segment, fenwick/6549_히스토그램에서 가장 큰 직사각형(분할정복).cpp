/*
문제
히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다.
각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다.
히스토그램에서 가장 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000)
그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1000000000)가 주어진다.
이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다.
모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 큰 직사각형의 넓이를 출력한다.
*/


/*
solution:
같은 높이라면 너비가 가장 긴 것이 가장 큰 직사각형이다.
가장 낮은 기둥을 양옆으로 갈 수 있는데까지 확장하면 그게 그 높이에서 가장 큰 직사각형이므로
그 기둥을 제외하고 왼쪽, 오른쪽 히스토그램에서 같은 과정을 거칠 수 있다.
그 중 가장 큰 값을 구하면 된다.

n개의 모든 기둥에 대해 위의 과정을 반복하게되는데, 
가장 낮은 기둥을 선형 탐색으로 찾으면 결과적으로 O(N^2)의 시간복잡도가 나온다.
따라서 세그먼트 트리에 최소값을 가지는 인덱스를 저장해 O(NlogN)의 시간복잡도로 풀 수 있다.
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






