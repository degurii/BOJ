/*
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
inorder로 트리를 탐색하면 순서대로 노드의 번호를 알 수 있다.
*/
#include <iostream>
using namespace std;
using pii = pair<int, int>;
#define INF 0x3f3f3f3f

int n, root;
pii p[10001], k[10001];
int m;
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
void dfs(int now, int level) {
	int l = p[now].first;
	int r = p[now].second;
	
	if(l != -1)
		dfs(l, level + 1);
	m++;
	k[level] = { min(k[level].first, m), max(k[level].second, m) };
	if(r != -1)
		dfs(r, level + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	root = n * (n + 1) / 2;
	for (int i = 1; i < n + 1; i++) {
		int x;
		cin >> x;
		cin >> p[x].first >> p[x].second;
		if (p[x].first != -1)
			root -= p[x].first;
		if (p[x].second != -1)
			root -= p[x].second;
		k[i].first = INF;
		k[i].second = -INF;
	}
	k[n + 1] = { INF, -INF };
	dfs(root, 1);
	
	int ans = -1, breadth = -1;
	for (int i = 1; k[i] != pii{INF, -INF}; i++) {
		if (breadth < k[i].second - k[i].first + 1) {
			breadth = k[i].second - k[i].first + 1;
			ans = i;
		}
	}

	cout << ans << ' ' << breadth;
}