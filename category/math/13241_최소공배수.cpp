/*
����
����� �� ���� ���Ͽ� �ּҰ������ ���ϴ� ���α׷��� �ۼ� �ϴ� ���� ��ǥ�̴�.

�Է�
�� �ٿ� �� ���� A�� B�� �������� �и��Ǿ� �־�����.
50%�� �Է� �� A�� B�� 1000(103)���� �۴�. �ٸ� 50%�� �Է��� 1000���� ũ�� 100000000(108)���� �۴�.
�߰�: ū �� �Է¿� ���Ͽ� ������ 64��Ʈ ������ �����Ͻÿ�. C/C++������ long long int�� ����ϰ�, Java������ long�� ����Ͻÿ�.

���
A�� B�� �ּҰ������ �� �ٿ� ����Ѵ�.
*/
#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)
		return gcd(b, a);
	else if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main() {
	ll a, b;
	cin >> a >> b;
	cout << a / gcd(a, b)*b;
}