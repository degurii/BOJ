/*
문제
여러분이 풀어야 할 문제는 주어진 괄호열을 읽고 그 괄호값을 앞에서 정의한대로 계산하여 출력하는 것이다.

입력
첫째 줄에 괄호열을 나타내는 문자열(스트링)이 주어진다. 단 그 길이는 1 이상, 30 이하이다.

출력
첫째 줄에 그 괄호열의 값을 나타내는 정수를 출력한다. 만일 입력이 올바르지 못한 괄호열이면 반드시 0을 출력해야 한다.
*/



/*
solution:
스택안에서,
괄호 사이에 숫자가있다면 -> 곱해야 할 값
숫자가 연달아 있다면 -> 더해야 할 값
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