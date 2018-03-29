/*
다음과 같이 7가지 명령어를 가지고 있으며, 각 명령어는 문자 1글자이다. (원래 8가지 명령어를 가지고 있지만, 문제를 위해 하나를 지웠다)

>: 포인터를 증가시킨다. 만약, 포인터 값이 32767이면 0이된다.
<: 포인터를 감소시킨다. 만약, 포인터 값이 0이면 32767이 된다.
+: 포인터가 가리키는 값을 증가시킨다. 255를 증가시키면 0이 된다.
-: 포인터가 가리키는 값을 감소시킨다. 0을 감소시키면 255가 된다.
.: 포인터가 가리키는 값을 ASCII문자로 출력한다.
[: 포인터가 가리키는 값이 0이면, 짝이 되는 뒤쪽의 ]로 이동한다.
]: 포인터가 가리키는 값이 0이 아니면, 짝이되는 앞쪽의 [로 이동한다.
Brainfuck 프로그램이 주어졌을 때, 이 프로그램의 출력을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 프로그램의 개수 T(1<=T<=100)가 주어진다.
각 프로그램은 한줄 또는 그 이상으로 구성되어 있으며, end만 적혀있는 줄로 끝난다.
프로그램에 올바르지 않은 문자 (<>+-[])가 있다면, 이는 무시하고 넘어가야 한다.
%는 주석을 의미하며, %가 나온 뒤에 나오는 해당 줄의 문자는 모두 무시한다. 프로그램의 최대 명령어 개수는 128000이다.

출력
각 프로그램의 결과를 다음과 같이 출력한다.
첫째 줄에 PROGRAM #n을 출력한다. n은 프로그램 번호이다. (첫 번째 프로그램부터 차례대로 1이고, 1 <= n <= N이다).
둘째 줄에는 프로그램의 결과를 출력한다. 만약 [나 ]가 짝이 맞지 않을 대는 COMPILE ERROR를 출력하면 된다. 출력에서 여러 줄을 출력할 수도 있다.
*/


/*
solution:
brain fuck
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define FMT(n) "PROGRAM " << '#' << n <<':'
#define ERR "COMPILE ERROR"
#define MOD_PTR 32768
#define MOD_VAL 256

int t;
unsigned char p[32768];
int bracket[128001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	for (int test = 1; test < t + 1; test++) {
		string s;
		int ptr = 0, val = 0;
		bool error = false;
		memset(p, 0, sizeof(p));
		memset(bracket, 0, sizeof(bracket));
		cout << FMT(test) << '\n';

		for (string tmp; getline(cin, tmp), tmp != "end";) {
			for (int i = 0; tmp[i]; i++) {
				if (tmp[i] == '%') {
					tmp = tmp.substr(0, i);
					break;
				}
			}
			s += tmp;
		}
		stack<int> stack;
		for (int i = 0; s[i]; i++) {
			if (stack.empty() && s[i] == ']') {
				error = true;
				break;
			}
			else if (s[i] == '[')
				stack.push(i);
			else if (s[i] == ']') {
				bracket[stack.top()] = i;
				bracket[i] = stack.top();
				stack.pop();
			}
				
		}
		if (!stack.empty() || error) {
			cout << ERR << '\n';
			continue;
		}
		for (int i = 0; s[i]; i++) {
			if (s[i] == '>')
				ptr = (++ptr) % MOD_PTR;
			else if (s[i] == '<')
				ptr = (--ptr + MOD_PTR) % MOD_PTR;
			else if (s[i] == '+')
				p[ptr] = ++p[ptr] % MOD_VAL;
			else if (s[i] == '-')
				p[ptr] = (--p[ptr] + MOD_VAL) % MOD_VAL;
			else if (s[i] == '.')
				cout << p[ptr];
			else if (s[i] == '[') {
				if (!p[ptr])
					i = bracket[i];
			}
			else if (s[i] == ']') {
				if (p[ptr])
					i = bracket[i];
			}
		}
		cout << '\n';
	}
}
