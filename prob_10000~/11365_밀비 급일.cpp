/*
����
����� ���� ���ٰ� �̻��� ������ �߰��ߴ�. �� �������� ��ȣ�� ���� �־��µ�, �ȶ��� ����� ��ȣ�� �������� �ص��ȴٴ� ���� �߰��ߴ�.
�� ��ȣ�� �ص��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ٿ� �ϳ��� ��ȣ�� �־�����. ��ȣ�� ���̴� 500�� ���� �ʴ´�.
������ �ٿ��� "END"�� �־�����. (END�� �ص����� �ʴ´�.)

���
�� ��ȣ�� �ص��� ���� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (getline(cin, s)) {
		if (s == "END") break;
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
}