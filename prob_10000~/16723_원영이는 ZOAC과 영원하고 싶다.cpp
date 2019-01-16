/*
입력
첫 번째 줄에 자연수 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.

출력
첫 번째 줄에 제1회 ZOAC부터 제N회 ZOAC까지의 참가자 수의 합을 출력한다.
*/
#include <iostream>
using namespace std;
using ll = long long;

ll n, ans;
int main() {
	cin >> n;
	ans = 2 * n;
	for (ll i = 1; n / 2 > 0; i++, n /= 2) {
		ans += (1 << i) * (n / 2);
	}
	cout << ans;
}