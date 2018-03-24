/*
�Է�
ù° �ٿ� ����� ������ ��Ÿ���� ���� N(1 �� N �� 10,000)�� �־�����.
���� N���� �ٿ��� �� �ٸ��� ��� ��ȣ�� �ش� ����� ���� �ڽ� ���� ������ �ڽ� ����� ��ȣ�� ������� �־�����.
������ ��ȣ�� 1���� N�����̸�, �ڽ��� ���� ��쿡�� �ڽ� ����� ��ȣ�� -1�� �־�����.

���
ù° �ٿ� �ʺ� ���� ���� ������ �� ������ �ʺ� ������� ����Ѵ�.
�ʺ� ���� ���� ������ �� �� �̻� ���� ������ ��ȣ�� ���� ������ ����Ѵ�.
*/


/*
solution:
inorder�� Ʈ���� Ž���ϸ� ������� ����� ��ȣ�� �� �� �ִ�.
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