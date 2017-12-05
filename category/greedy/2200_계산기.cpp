/*
문제
문제를 단순하게 하기 위해서 최고차항의 계수는 항상 1이라고 가정하자. 또 음수 계수는 고려하지 않기로 하자.
다항식이 주어졌을 때, 이 계산기로 주어진 다항식을 계산하려면 계산기를 최소 몇 번 눌러야 하는지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 다항식의 차수 N(1≤N≤10,000)이 주어진다.
다음 줄에는 다항식의 계수가 최고차항부터 주어진다. 최고차항의 계수는 항상 1이며 모든 계수는 0 이상이다. 모든 계수는 1,000,000,000을 넘지 않는다.

출력
첫째 줄에 계산기를 누르는 최소 횟수를 출력한다.
*/





/*
solution:
잘 생각해서 풀면 된다.
*/
#include <iostream>
using namespace std;
#include <string>
using ll = long long;

int n, p[10001];
int main() {
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		cin >> p[i];
	}
	ll ans = 2;//(첫항 x)+ (마지막에들어가는 =)
	for (int i = 1; i < n; i++) {
		if (p[i] == 0) ans += 2;
		else {
			ans += to_string(p[i]).size() + 3;
		}
	}
	if(p[n] != 0)
		ans += to_string(p[n]).size() + 1;
	cout << ans;
}