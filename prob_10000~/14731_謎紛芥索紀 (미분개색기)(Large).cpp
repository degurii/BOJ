/*
문제
성민이는 이번 학기에 미적분학 과목을 수강하고 있다.
다항함수의 미분 단원 과제를 하던 도중 미분을 하기가 귀찮아진 성민이는 미분하려는 함수 f(x)가 주어지면,
미분 된 함수 f’(x)를 자동으로 구해주는 프로그램을 만들어서 계산을 줄일 생각을 하였다. 우리도 성민이가 원하는 프로그램을 한번 같이 만들어보도록 하자.

입력
첫째 줄에는 항의 개수 N(1 ≤ N ≤ 100000)이 주어진다.
둘째 줄부터 N개 줄에 걸쳐서 항의 계수 C(0 < C ≤ 100)와 항의 차수 K(0 ≤ K ≤ 10^9)가 항의 차수와 관계 없이 무작위로 주어진다.
항의 차수가 같은 항은 2개 이상 존재하지 않는다

출력
f’(2)의 값을 109+7로 나눈 나머지를 첫째 줄에 출력한다.
*/







/*
solution:
2^k를 구하는게 관건인데, k<=10^9이므로 데이터 범위때문에 pow를 통한 연산이 불가능하다.
따라서 직접 구해줘야 하지만 O(K)의 시간복잡도로는 구할 수 없다.
제곱연산을 O(log(K))의 시간복잡도로 구현한다.

(x^2k) = (x^k) * (x^k)
(x^(2k+1)) = x * (x^2k)
의 원리로 log시간으로 계산할 수 있다.
*/
#include <iostream>
#include <cmath>
using namespace std;
#define MOD 1000000007
using ll = long long;

ll f(ll x, ll e) {
	if (e == 0) return 1;
	else if (e == 1) return x;
	else if (e % 2 == 0) {
		ll t = f(x, e / 2);
		return ((t%MOD)*(t%MOD)) % MOD;
	}
	else {
		return ((x%MOD)*(f(x, e - 1) % MOD)) % MOD;
	}
}

ll n, c, k, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> c >> k;
		if (k == 0)continue;
		ans = ((ans%MOD) + ((((c%MOD)*(k%MOD)) % MOD)*f(2, k - 1) % MOD)) % MOD;
	}
	cout << ans;
}