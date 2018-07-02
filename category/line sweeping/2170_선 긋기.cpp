/*
����
�ſ� ū ��ȭ���� �ڸ� ��� ���� �������� �Ѵ�. ���� ���� ������ ���� �� ������ �ٸ� �� ������ �߰� �ȴ�.
���� ���� ������ �̹� ���� �ִ� ��ġ�� ���ļ� �׸� ���� �ִµ�, ���� �� ���� ���� �� �� ���� ���� ���̸� ������ �� ���ٰ� ����.
�̿� ���� ������ ���� �׾��� ��, �׷��� ��(��)�� �� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���� �� �׷��� ���� �� ������ ����Ѵ�.

�Է�
ù° �ٿ� ���� ���� Ƚ�� N(1��N��1,000,000)�� �־�����.
���� N���� �ٿ��� ���� ���� �� ������ �� ���� �־�����.
������ ������ -1,000,000,000 �̻� 1,000,000,000 ������ �����̴�.

���
ù° �ٿ� ���� ���� �� ���̸� ����Ѵ�.
*/






/*
solution:
���� ���� ��ǥ�� �������� �����Ѵ�
������ǥ�� ���� ������ ���鼭
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f

int n;
vector<pair<int, int> > p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		p.push_back({ u, v });
	}
	sort(p.begin(), p.end());
	int ans = 0, last = -INF;
	for (auto &now : p) {
		int u = now.first;
		int v = now.second;
		if (u <= last && v > last) {
				ans += v - last;
		}
		else if (u > last) {
			ans += v - u;
		}
		if (v > last) last = v;
	}
	cout << ans;
}