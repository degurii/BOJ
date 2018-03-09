/*
����
�������� Ǯ��� �� ������ �־��� ��ȣ���� �а� �� ��ȣ���� �տ��� �����Ѵ�� ����Ͽ� ����ϴ� ���̴�.

�Է�
ù° �ٿ� ��ȣ���� ��Ÿ���� ���ڿ�(��Ʈ��)�� �־�����. �� �� ���̴� 1 �̻�, 30 �����̴�.

���
ù° �ٿ� �� ��ȣ���� ���� ��Ÿ���� ������ ����Ѵ�. ���� �Է��� �ùٸ��� ���� ��ȣ���̸� �ݵ�� 0�� ����ؾ� �Ѵ�.
*/



/*
solution:
���þȿ���,
��ȣ ���̿� ���ڰ��ִٸ� -> ���ؾ� �� ��
���ڰ� ���޾� �ִٸ� -> ���ؾ� �� ��
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string p;
	cin >> p;
	s.push(0);
	for (int i = 0; p[i]; i++) {
		int num = 1;
		if (p[i] == '(') {
			s.push(-2);
		}
		else if (p[i] == '[') {
			s.push(-3);
		}
		else {
			if (s.top() != -2 && s.top() != -3) {
				num = s.top();
				s.pop();
			}
			if (s.empty() || (s.top() == -2 && p[i] == ']') || (s.top() == -3 && p[i] == ')')) {
				cout << 0;
				return 0;
			}
			if (s.top() == -2 && p[i] == ')') {
				s.pop();
				num *= 2;
			}
			else if (s.top() == -3 && p[i] == ']') {
				s.pop();
				num *= 3;
			}
			if (s.top() != -2 && s.top() != -3) {
				s.top() += num;
			}
			else {
				s.push(num);
			}
		}
	}
	int ans = 0;
	while (!s.empty()) {
		if (s.top() == -2 || s.top() == -3) {
			cout << 0;
			return 0;
		}
		ans += s.top();
		s.pop();
	}
	cout << ans;
}