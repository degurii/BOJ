/*
�踷���� �������� ��ġ�� ��Ÿ���� ��ȣ ǥ���� �־����� ��, �߷��� �踷��� ������ �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ٿ� �踷���� �������� ��ġ�� ��Ÿ���� ��ȣ ǥ���� ������� �־�����. ��ȣ ������ ������ �ִ� 100,000�̴�.

���
�߷��� ������ �� ������ ��Ÿ���� ������ �� �ٿ� ����Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	int x = 0, ans = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(' && s[i + 1] == ')') {
			ans += x;
			i++;
		}
		else if (s[i] == '(') {
			x++;
		}
		else {
			x--;
			ans += 1;
		}
	}
	cout << ans;
}
