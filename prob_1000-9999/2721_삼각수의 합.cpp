/*
문제
W(n) = Sum[k=1..n; k*T(k+1)]
n이 주어졌을 때, W(n)을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 정수 n 하나로 이루어져 있다. (1<=n<=300)

출력
각 테스트 케이스에 대해 W(n)을 한 줄에 하나씩 출력한다.
*/
#include <iostream>
using namespace std;

int a[302];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < 302; i++) {
		a[i] = a[i - 1] + i;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 1; i < n + 1; i++) {
			ans += i * a[i + 1];
		}
		cout << ans << '\n';
	}
}