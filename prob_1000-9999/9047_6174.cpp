/*
문제
6174 에 도달한 다음에는 매번 6174 를 만들어 낸다. 2008 만이 유독 6174 에 도달하는 것이 아니라 한 숫자로 이루어지지 않은 모든 네 자리 수는 Kaprekar 연산을 통해 6174 로 가게 된다.
2008 의 경우 6 단계를 거쳐 6174 로 가게 되었는데, 다른 숫자가 입력으로 주어졌을 때 몇 단계만에 6174 로 가는지 알아내는 프로그램을 작성하시오.

입력
입력은 표준입력(standard input)을 통해 받아들인다.
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다.
각 테스트 케이스마다 한 줄에 네 자리 수(1000~9999)가 하나씩 주어진다. 단, 이 숫자는 1111, 2222 처럼 하나의 숫자로 이루어진 수는 제외한다.

출력
출력은 표준출력(standard output)을 통하여 출력한다.
각 테스트 케이스에 대하여 Kaprekar 연산을 통해 몇 단계 만에 6174가 되는지 한 줄에 하나씩 출력하시오.
*/
#include <iostream>
#include <map>
using namespace std;

int t, n, ans;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		while (n != 6174) {
			map<int, int> m;
			for(int i=0; i<4; i++){
				m[n % 10]++;
				n /= 10;
			}
			int big = 0, small = 0;
			int i = 1;
			for (auto cur : m) {
				int x = cur.first, cnt = cur.second;
				while (cnt--) {
					big += i * x;
					i *= 10;
					small = small * 10 + x;
				}
			}
			n = big - small;
			ans++;
		}
		cout << ans << '\n';
	}
}
