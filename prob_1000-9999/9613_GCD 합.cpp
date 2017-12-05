/*
����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 < t < 100)�� �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�,
ù° �ٿ��� ���� ���� n (1 < n < 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.
*/





/*
solution:
�ܼ��� ��� �ֿ� ���ؼ� gcd���� ���� ���ϴ� ����
���� int������ �Ѿ �� �����Ƿ� long long���� �ؾ���
*/
#include <iostream>
using namespace std;
#include <vector>
using ll = long long;

int t;
ll gcd(ll x, ll y) {
	if (x < y) return gcd(y, x);
	else if (y == 0) return x;
	else return gcd(y, x%y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(p[i], p[j]);
			}
		}
		cout << ans << '\n';
	}
}