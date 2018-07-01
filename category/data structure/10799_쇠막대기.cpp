/*
쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 주어졌을 때, 잘려진 쇠막대기 조각의 총 개수를 구하는 프로그램을 작성하시오.

입력
한 줄에 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 주어진다. 괄호 문자의 개수는 최대 100,000이다.

출력
잘려진 조각의 총 개수를 나타내는 정수를 한 줄에 출력한다.
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
