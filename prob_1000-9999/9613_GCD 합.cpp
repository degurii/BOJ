/*
문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 < t < 100)이 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고,
첫째 줄에는 수의 개수 n (1 < n < 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
*/





/*
solution:
단순히 모든 쌍에 대해서 gcd들의 합을 구하는 문제
답이 int범위를 넘어갈 수 있으므로 long long으로 해야함
*/
#include <iostream>
using namespace std;
#include <vector>
using ll = long long;

int t;
ll gcd(ll x, ll y) {
	if (x < y) return gcd(y, x);
	else if (y == 0) return x;
	else return gcd(y, x%y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(p[i], p[j]);
			}
		}
		cout << ans << '\n';
	}
}