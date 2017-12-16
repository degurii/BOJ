/*
문제
당신은 두 수에 대하여 최소공배수를 구하는 프로그램을 작성 하는 것이 목표이다.

입력
한 줄에 두 정수 A와 B가 공백으로 분리되어 주어진다.
50%의 입력 중 A와 B는 1000(103)보다 작다. 다른 50%의 입력은 1000보다 크고 100000000(108)보다 작다.
추가: 큰 수 입력에 대하여 변수를 64비트 정수로 선언하시오. C/C++에서는 long long int를 사용하고, Java에서는 long을 사용하시오.

출력
A와 B의 최소공배수를 한 줄에 출력한다.
*/
#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)
		return gcd(b, a);
	else if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main() {
	ll a, b;
	cin >> a >> b;
	cout << a / gcd(a, b)*b;
}