/*
문제
유리수 분수를 소수로 나타내면, 소수점 아래 자리가 유한 개인 경우(1/8 = 0.125)와
어떤 자리에서부터 일정한 숫자가 한없이 되풀이 되는 경우(1/11 = 0.090909...)가 있다.
소수를 입력받은 뒤, 분수로 나타내는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 개수는 100개를 넘지 않는다.
각 테스트 케이스는 한 줄에 소수가 하나씩 주어진다.
소수의 첫 두 자리는 "0."이다. 그 다음에는 숫자 0개~6개가 주어진다.
그 다음, 길이가 1과 9사이면서 괄호로 감싸져있는 수가 주어질 수도 있다. 이 수는 무한히 반복되는 자리를 의미한다.
항상 0이 아닌 자리가 하나는 주어지며, 괄호 안에 주어지는 수는 0이나 9로만 이루어져 있지 않다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 소수의 분수 표현을 출력한다. (분모와 분자는 서로소이어야 한다)
*/





/*
누더기코드. 
생각나는대로 덕지덕지 붙인 코드라 부끄러운 코드지만
어쨋든 AC

solve:
1) 순환소수가 아닐 때:
	"0."이거 떼고 남은 수랑 10^(소수자릿수)랑 약분해주면됨
2) 순환소수일떄
	분모: 순환되는 자릿수만큼 9를 쓰고, 뒤에 순환 안되는 자릿수만큼 0을 채워준다
	분자: ("0."뗀 전체 수) - (순환안되는 수)

약분은 gcd구해서 각각 나눠준다
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
int t;
ll gcd(ll a, ll b) {
	if (a < b)return gcd(b, a);
	else if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int b = 0, nb = 0;
		s.erase(0, 2);
		bool k = false;
		for (auto i : s) {
			if (k && i != ')') b++;
			else if (i == '(') k = true;
			else if (i != ')' && i != '(')nb++;
		}
		
		for (int i = 0; s[i]; i++) {
			if (s[i] == '(') {
				s.pop_back();
				s.erase(s.begin()+i);
				break;
			}
		}
		if (b == 0) {
			ll x = stoll(s), y = (ll)pow(10, nb);
			ll g = gcd(x, y);
			cout << x / g << '/' << y / g << '\n';
		}
		else {
			string y;
			ll x = 0;
			for (int i = 0; i < b; i++)y += "9";
			for (int i = 0; i < nb; i++)y += "0";
			if (nb == 0)
				x = stoll(s);
			else
				x = stoll(s) - stoll(s.substr(0, nb));
			ll yy = stoll(y);
			ll g = gcd(x, yy);
			cout << x / g << '/' << yy / g << '\n';
		}
	}
}