/*
����
C����� �� ������� �־����� ��, ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �ִ� 12000�ٷ� �̷���� �ִ�. �� ���� �� ���� a, b�� �־�����, ���� ���̿��� ������ ">", ">=", "<", "<=", "==", "!="�� �ϳ��� �־�����.
�����ڿ� �ǿ����� ���̿��� ������ �ϳ� ������, �����ڷ� "E"�� �־��� ��쿡�� ���α׷��� ������. (-10000 �� a,b �� 10000)

���
�Է��� �� �� ���� �Է����� �־��� ���� ����� "true"���� "false"���� ����Ѵ�.
*/
// ">", ">=", "<", "<=", "==", "!="
#include <iostream>
#include <string>
using namespace std;

int a, b;
string s;
string foo(bool b) {
	return b ? "true" : "false";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; 1; i++) {
		cin >> a >> s >> b;
		if (s == "E") break;
		cout << "Case " << i << ": ";
		if (s == ">") cout << foo(a > b);
		else if (s == ">=") cout << foo(a >= b);
		else if (s == "<") cout << foo(a < b);
		else if (s == "<=") cout << foo(a <= b);
		else if (s == "==") cout << foo(a == b);
		else if (s == "!=") cout << foo(a != b);
		cout << '\n';
	}
}