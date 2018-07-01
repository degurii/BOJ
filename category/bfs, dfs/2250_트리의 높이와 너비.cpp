/*
����
������ ����Ʈ���� �Է����� �־��� �� �ʺ� ���� ���� ������ �� ������ �ʺ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�

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
�����ϱ� �ѳ� �ָ��Ѱ�
�ڱ� ��ü �ڽ��� ��, ������, ���� �ڽ��� ���� �� ���캸��
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