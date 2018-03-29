/*
�Է�
ù° �ٿ��� �����̰� �ֹ��� ���ɸ� �������� ���� N, �׸��� �����̸� ������ ģ���� K���� �Էµȴ�.
N�� 10000������ �����̰�, K�� 1,000,000������ �����̴�.
���ɸ��� �뷮�� 231 -1 ���� �۰ų� ���� �ڿ����̴�. (��, �׻� N �� K �̴�. ��, �������� ������ ��� ������ ���� ���� ���� ) .

���
ù° �ٿ� K���� ������ �� �ִ� �ִ��� ���ɸ� �뷮 ml �� ����Ѵ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int p[10000];

int foo(int m) {
	int cur = 0;
	for (int i = 0; i < n; i++)
		cur += p[i] / m;
	return cur;
}
void go(int l, int r) {
	if (l > r)
		return;
	int m = (l + r) / 2;
	int cur = foo(m);
	if (cur >= k) {
		if (ans < m)
			ans = m;
		go(m + 1, r);
	}
	else {
		go(l, m - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	go(0, p[n - 1]);
	cout << ans;
}