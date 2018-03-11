/*
문제
C언어의 비교 연산식이 주어졌을 때, 결과를 구하는 프로그램을 작성하시오.

입력
입력은 최대 12000줄로 이루어져 있다. 각 줄은 두 정수 a, b가 주어지며, 정수 사이에는 연산자 ">", ">=", "<", "<=", "==", "!="중 하나가 주어진다.
연산자와 피연산자 사이에는 공백이 하나 있으며, 연산자로 "E"가 주어진 경우에는 프로그램을 끝낸다. (-10000 ≤ a,b ≤ 10000)

출력
입력의 각 줄 마다 입력으로 주어진 식의 결과가 "true"인지 "false"인지 출력한다.
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