/*
����
�Լ� F(x)�� �Է����� �־��� �� x�� ù �ڸ��� ���ڿ� �� x�� �ڸ����� ���� ����� ��ȯ�ϴ� �Լ��̴�.
���� ��� x = 932 �϶� F(x)�� 9��3���� 27�� ��ȯ�Ѵ�.
�Է¹��� x�� ���ؼ� �Լ� F�� �����ϰ�, ���� ������� �ٽ� �Լ� F�� �����ϴ� ���� �ݺ��Ѵ�.
����Ƚ�� �̻� �ݺ��ؼ� ���������� �Լ��� ����� ����ؼ� ������ ���ڰ� ������ ���, �Է� x�� FA�� ��� �Ѵ�.

�Է� x�� �־������� �� ���� FA ������ ����϶�.

�Է�
���� x �� �־�����. (0 �� x �� 10^100)

���
���� x�� FA�� ��� FA�� ����ϰ�, �ƴ϶�� NFA�� ����Ѵ�.
*/



/*
solve:
���� ����Ŭ����.
x�� ���������� string���� ó���ϸ� �ȴ�
*/
#include <iostream>
using namespace std;
#include <string>

bool f(string x) {
	string ori = x;
	string res = to_string((x[0] - '0')*(int)x.size());

	while (res != x) {
		x = res;
		res = to_string((x[0] - '0')*(int)x.size());
		if (res == x) return true;
		if (res == ori)return false;
	}
}
int main() {
	string x;
	cin >> x;
	if (f(x))cout << "FA";
	else cout << "NFA";
}