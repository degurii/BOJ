/*
문제
임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오

입력
첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다.
다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다.
노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.

출력
첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다.
너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.
*/


/*
solution:
설명하기 넘나 애매한것
자기 전체 자식의 수, 오른쪽, 왼쪽 자식의 수를 잘 살펴보자
*/
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;

pii p[10001];
pii children[10001];
int num[10001];
pii k[10001];
int n;
bool checkRoot[10001];

int setChildren(int now) {
	int l = p[now].first;
	int r = p[now].second;
	if (l != -1) {
		children[now].first += setChildren(l);
	}
	if (r != -1) {
		children[now].second += setChildren(r);
	}
	return children[now].first + children[now].second + 1;
}

void setNum(int now, int x) {
	int l = p[now].first;
	int r = p[now].second;

	num[now] = x - children[now].second;
	if (l != -1) {
		setNum(l, x - children[now].second - 1);
	}
	if (r != -1) {
		setNum(r, x);
	}
}

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
void dfs(int now, int level) {
	k[level] = { min(k[level].first, num[now]), max(k[level].second, num[now]) };
	int l = p[now].first;
	int r = p[now].second;
	if (l != -1)
		dfs(l, level + 1);
	if (r != -1)
		dfs(r, level + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		int x;
		cin >> x;
		cin >> p[x].first >> p[x].second;
		if (p[x].first != -1)
			checkRoot[p[x].first] = true;
		if (p[x].second != -1)
			checkRoot[p[x].second] = true;
	}
	int root = -1;
	for (int i = 1; i < n + 1; i++) {
		if (!checkRoot[i]) {
			root = i;
			break;
		}
	}
	setChildren(root);
	setNum(root, n);

	for (int i = 0; i < n + 1; i++) {
		k[i] = { INF, -INF };
	}
	dfs(root, 1);
	int ans = -INF, node = -1;
	for (int i = 1; i < n + 1; i++) {
		if (k[i].first == INF) break;
		if (ans < k[i].second - k[i].first + 1) {
			ans = k[i].second - k[i].first + 1;
			node = i;
		}
		ans = max(ans, k[i].second - k[i].first);
	}

	cout << node << ' ' << ans;
}