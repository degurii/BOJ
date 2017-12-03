/*
문제
함수 F(x)는 입력으로 주어진 수 x의 첫 자리의 숫자와 수 x의 자리수를 곱한 결과를 반환하는 함수이다.
예를 들어 x = 932 일때 F(x)는 9×3으로 27을 반환한다.
입력받은 x에 대해서 함수 F를 수행하고, 나온 결과값에 다시 함수 F를 수행하는 것을 반복한다.
일정횟수 이상 반복해서 수행했을때 함수의 결과가 계속해서 동일한 숫자가 나오는 경우, 입력 x를 FA수 라고 한다.

입력 x가 주어졌을때 이 수가 FA 수인지 출력하라.

입력
숫자 x 가 주어진다. (0 ≤ x ≤ 10^100)

출력
숫자 x가 FA수 라면 FA를 출력하고, 아니라면 NFA를 출력한다.
*/



/*
solve:
흔한 싸이클문제.
x의 범위때문에 string으로 처리하면 된다
*/
#include <iostream>
using namespace std;
#include <string>

bool f(string x) {
	string ori = x;
	string res = to_string((x[0] - '0')*(int)x.size());

	while (res != x) {
		x = res;
		res = to_string((x[0] - '0')*(int)x.size());
		if (res == x) return true;
		if (res == ori)return false;
	}
}
int main() {
	string x;
	cin >> x;
	if (f(x))cout << "FA";
	else cout << "NFA";
}