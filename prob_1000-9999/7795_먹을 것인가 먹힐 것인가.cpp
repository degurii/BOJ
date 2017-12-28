/*
����
���ؿ��� �� ������ ����ü A�� B�� �����Ѵ�. A�� B�� �Դ´�. A�� �ڱ⺸�� ũ�Ⱑ ���� ���̸� ���� �� �ִ�
���� ���, A�� ũ�Ⱑ {8, 1, 7, 3, 1}�̰�, B�� ũ�Ⱑ {3, 6, 1}�� ��쿡 A�� B�� ���� �� �ִ� ���� ������ 7������ �ִ�.
8-3, 8-6, 8-1, 7-3, 7-6, 7-1, 3-1.
�� ����ü A�� B�� ũ�Ⱑ �־����� ��, A�� ũ�Ⱑ B���� ū ���� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� �׽�Ʈ ���̽��� ù° �ٿ��� A�� �� N�� B�� �� M�� �־�����.
��° �ٿ��� A�� ũ�Ⱑ ��� �־�����,
��° �ٿ��� B�� ũ�Ⱑ ��� �־�����. ũ��� ���� �����̴�. (1 �� N, M �� 20,000)

���
�� �׽�Ʈ ���̽�����, A�� B���� ū ���� ������ ����Ѵ�.
*/





/*
solution:
a�� �����ϰ� b�� ������� Ž���ϸ鼭
���� b�� ���Һ��� ū a�� ������ ������ upper_bound�� �����ش�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		vector<int> a, b;
		int n, m;
		cin >> n >> m;
		while (n--) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		while (m--) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		int ans = 0;
		for (int now : b) {
			ans += a.end() - upper_bound(a.begin(), a.end(), now);
		}
		cout << ans << '\n';
	}
}

