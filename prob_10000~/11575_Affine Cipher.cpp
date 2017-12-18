/*
����
���ʳ��󿡼� Ư���Ʒ��� ���� �����̴� ���ʳ���� ħ���� �ϰ� �Ǿ���. �پ �����̿��� �����̴� ���ʳ����� ������ �Լ��ϰ� �Ǿ��� ������ �����ϰ� ���ʳ���� �����ϱ� ���� ���� ��ȣ(Affine Cipher)�� �̿��ϱ�� �Ͽ���.
���� ��ȣ�� ������ ���� ���� ���� ���� �� �ִ�.
E(X) = (aX + b) mod 26
A���� Z������ ���ĺ��� ���ʴ�� 0, 1, 2, ... , 25 ��� ����.
a = 3�̰�, b = 1�� ��쿡 ���ĺ� A�� ���� ��ȣ�Ŀ� �����ϸ� E(0) = (3 �� 0 + 1) mod 26 �� �Ǿ� ��ȣȭ�� ����� B�� �ȴ�.
a�� b, �׸��� ���ĺ� �빮�ڷθ� ������ ���� �־����� ��, �̸� ��ȣ������ ġȯ�ϴ� ���α׷��� �ۼ��϶�.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T(1 �� T �� 50) �� �־�����.
�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �� ���� a�� b(0 < a, b �� 1,000,000)�� ���� �־�����. a�� 26�� ���μ����� ����ȴ�.
�� �׽�Ʈ���̽��� �� ��° �ٿ��� �� s�� �־�����. ���� ���� |s|�� 0���� ũ�� 1,000,000���� �۴�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� �� ���� �� s�� ��ȣ������ ġȯ�� ����� ����Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

int a, b;
char con[26];
void foo() {
	for (int i = 0; i < 26; i++) {
		con[i] = (a*i + b) % 26 + 'A';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		string s;
		cin >> s;
		foo();
		for (int i = 0; s[i]; i++) {
			cout << con[s[i] - 'A'];
		}
		cout << '\n';
	}
}