/*
�Է�
ù ��° �ٿ� �ڿ��� N(1 �� N �� 1,000,000,000)�� �־�����.

���
ù ��° �ٿ� ��1ȸ ZOAC���� ��Nȸ ZOAC������ ������ ���� ���� ����Ѵ�.
*/
#include <iostream>
using namespace std;
using ll = long long;

ll n, ans;
int main() {
	cin >> n;
	ans = 2 * n;
	for (ll i = 1; n / 2 > 0; i++, n /= 2) {
		ans += (1 << i) * (n / 2);
	}
	cout << ans;
}