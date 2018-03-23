/*
����
W(n) = Sum[k=1..n; k*T(k+1)]
n�� �־����� ��, W(n)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ���� n �ϳ��� �̷���� �ִ�. (1<=n<=300)

���
�� �׽�Ʈ ���̽��� ���� W(n)�� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int a[302];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < 302; i++) {
		a[i] = a[i - 1] + i;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 1; i < n + 1; i++) {
			ans += i * a[i + 1];
		}
		cout << ans << '\n';
	}
}