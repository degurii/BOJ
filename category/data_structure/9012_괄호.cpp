/*
����
�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�.

�Է�
�Է� �����ʹ� ǥ�� �Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �־�����.
�Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����
�� �׽�Ʈ �������� ù° �ٿ��� ��ȣ ���ڿ��� �� �ٿ� �־�����. �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�.

���
����� ǥ�� ����� ����Ѵ�.
���� �Է� ��ȣ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(VPS)�̸� ��YES��, �ƴϸ� ��NO���� �� �ٿ� �ϳ��� ���ʴ�� ����ؾ� �Ѵ�.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> p;
		int cnt = 0;
		string ans = "YES\n";
		for (int i = 0; p[i]; i++) {
			if (p[i] == '(')
				cnt++;
			else {
				if (cnt == 0) {
					ans = "NO\n";
					break;
				}
				else {
					cnt--;
				}
			}
		}
		if (cnt > 0) ans = "NO\n";
		cout << ans;
	}
}