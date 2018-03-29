/*
������ ���� 7���� ��ɾ ������ ������, �� ��ɾ�� ���� 1�����̴�. (���� 8���� ��ɾ ������ ������, ������ ���� �ϳ��� ������)

>: �����͸� ������Ų��. ����, ������ ���� 32767�̸� 0�̵ȴ�.
<: �����͸� ���ҽ�Ų��. ����, ������ ���� 0�̸� 32767�� �ȴ�.
+: �����Ͱ� ����Ű�� ���� ������Ų��. 255�� ������Ű�� 0�� �ȴ�.
-: �����Ͱ� ����Ű�� ���� ���ҽ�Ų��. 0�� ���ҽ�Ű�� 255�� �ȴ�.
.: �����Ͱ� ����Ű�� ���� ASCII���ڷ� ����Ѵ�.
[: �����Ͱ� ����Ű�� ���� 0�̸�, ¦�� �Ǵ� ������ ]�� �̵��Ѵ�.
]: �����Ͱ� ����Ű�� ���� 0�� �ƴϸ�, ¦�̵Ǵ� ������ [�� �̵��Ѵ�.
Brainfuck ���α׷��� �־����� ��, �� ���α׷��� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���α׷��� ���� T(1<=T<=100)�� �־�����.
�� ���α׷��� ���� �Ǵ� �� �̻����� �����Ǿ� ������, end�� �����ִ� �ٷ� ������.
���α׷��� �ùٸ��� ���� ���� (<>+-[])�� �ִٸ�, �̴� �����ϰ� �Ѿ�� �Ѵ�.
%�� �ּ��� �ǹ��ϸ�, %�� ���� �ڿ� ������ �ش� ���� ���ڴ� ��� �����Ѵ�. ���α׷��� �ִ� ��ɾ� ������ 128000�̴�.

���
�� ���α׷��� ����� ������ ���� ����Ѵ�.
ù° �ٿ� PROGRAM #n�� ����Ѵ�. n�� ���α׷� ��ȣ�̴�. (ù ��° ���α׷����� ���ʴ�� 1�̰�, 1 <= n <= N�̴�).
��° �ٿ��� ���α׷��� ����� ����Ѵ�. ���� [�� ]�� ¦�� ���� ���� ��� COMPILE ERROR�� ����ϸ� �ȴ�. ��¿��� ���� ���� ����� ���� �ִ�.
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
