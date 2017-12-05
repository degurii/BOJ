/*
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만드려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리 이상 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.

출력
첫째 줄에 정답을 출력한다.
*/








/*
solution:
전부 -로 묶는다
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	int ans = 0;
	bool o = false;
	for (int i = 0; i<s.size();) {
		int f = i;
		while (s[i+1] != '+' && s[i+1] != '-' && s[i+1] != '\0') {
			i++;
		}
		string n = s.substr(f, i - f + 1);
		if(o) ans -= stoi(n);
		else ans += stoi(n);

		if (s[i + 1] == '-') o = true;
		i += 2;
	}
	cout << ans;
}