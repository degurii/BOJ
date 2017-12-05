/*
����
�����, �̸��ڴ� �쿬�� ��Ÿ����� ��� N�� ���Ҵ�. �̸��ڴ� 30�̶� ���� �����ϱ� ������,
�״� ��Ÿ����� ã�� ���� ���Ե� ���ڵ��� ���� 30�� ����� �Ǵ� ���� ū ���� ����� �;��Ѵ�.
�̸��ڸ� ���� �װ� ����� �;��ϴ� ���� ����ϴ� ���α׷��� �ۼ��϶�. (�� ���� �����Ѵٸ�)

�Է�
N�� �Է¹޴´�. N�� �ִ� 10^5���� ���ڷ� �����Ǿ� �ִ�.

���
�̸��ڰ� ����� �;��ϴ� ���� �����Ѵٸ� �� ���� ����϶�. �� ���� �������� �ʴ´ٸ�, -1�� ����϶�.
*/






/*
solution:
30�� ��� : 2, 3, 5�� ���
2,5�ǹ�� -> 10�ǹ��, ���ڸ��� 0
3�ǹ�� -> �� �ڸ����� ���ؼ� 3���� ������������
���� ū�� -> �������� ����
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;

bool isThreeMul(string s){
	int sum = 0, len = s.size();
	for (int i = 0; i < len; i++)
		sum += (s[i] - '0');
	if (sum % 3 == 0)
		return true;
	else
		return false;
}
char s[100001];
int main(){
	cin >> s;
	int len = strlen(s), last = 0;
	sort(s, s+len, greater<char>());
	last = s[len - 1] - '0';
	if (!isThreeMul(s) || last != 0)
		cout << -1;
	else
		cout << s;
}