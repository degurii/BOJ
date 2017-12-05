/*
����
��� �Ұ� ���忡 �����Ϸ��� �󸶳� �ɸ��� �� ���غ���.

�Է�
ù �ٿ� 100 ������ ���� ���� N�� �־�����.
���� N�ٿ��� �� �ٿ� �ϳ��� ���� ���� �ð��� �˹� �ð��� �־�����. ���� 1,000,000 ������ ���� �����̴�.

���
��� �Ұ� ���忡 �����ϴ� �� �ɸ��� �ּ� �ð��� ����Ѵ�.
*/



/*
solution:
���� �����Ѵ�
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[101];
int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p + 1, p + n + 1);
	int t = 0;
	for (int i = 1; i < n + 1; i++) {
		if (t < p[i].first) t = p[i].first;
		t += p[i].second;
	}
	cout << t;
}