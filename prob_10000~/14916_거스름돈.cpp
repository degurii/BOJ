/*
�Է�
ù° �ٿ� �Ž����� �׼� n(1 �� n �� 100,000)�� �־�����.

���
�Ž����� ������ �ּ� ������ ����Ѵ�. ���� �Ž��� �� �� ������ -1�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 5) {
		if (n == 3 || n == 1)
			cout << -1;
		else
			cout << n / 2;
		return 0;
	}
	int a = n / 5;
	n %= 5;
	
	if (n & 1) { 
		n += 5;
		a--;
	}
	cout << a + (n / 2);
}