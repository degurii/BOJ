/*
입력
The first and only line of input contains the integers A and B (1 ≤ A ≤ B ≤ 100 000) from the task.

출력
The first and only line of output must contain any essay that meets the rules from the task.
*/
#include <iostream>
#include <string>
using namespace std;

int a, b, k, o;
bool foo(string s, int lev) {
	if (o == b) return true;
	if (s.size() > 15) return false;
	if (k <= lev) {
		cout << s << ' ';
		o++;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		if (foo(s + i, lev + 1)) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	for (int i = b; i > 0; i /= 26) {
		k++;
		i /= 26;
	}
	foo("", 0);
}
