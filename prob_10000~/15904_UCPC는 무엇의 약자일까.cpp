/*
�Է�
ù ��° �ٿ� ���ĺ� ��ҹ���, �������� ������ ���ڿ��� �־�����.
���ڿ��� ���̴� �ִ� 1,000���̴�. ���ڿ��� �� �հ� �� ���� ������ �ִ� ���� ����, ������ �����ؼ� 2�� �̻� �־����� ��쵵 ����.

���
ù ��° �ٿ� �Է����� �־��� ���ڿ��� ������ ����� "UCPC"�� ���� �� ������ "I love UCPC"�� ����ϰ�, ���� �� ������ "I hate UCPC"�� ����Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	getline(cin, s);
	int d = 0;
	for (int i = 0; s[i]; i++) {
		if (d == 0 && s[i] == 'U')
			d++;
		else if (d == 1 && s[i] == 'C')
			d++;
		else if (d == 2 && s[i] == 'P')
			d++;
		else if (d == 3 && s[i] == 'C') {
			d++;
			break;
		}
	}
	if (d == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
}