/*
문제
단, 수가 너무 커질 수 있으니 1000000007로 나눈 나머지를 구해보자.

입력
입력의 첫째 줄에 남학생의 수 N(2 ≤ N ≤ 1000000)명 여학생의 수 M(1 ≤ M ≤ N)명이 주어진다.

출력
경우의 수를 1000000007로 나눈 나머지를 출력하라.
*/


/*
solution:
nCk = n! / (k! * (n-k)!)
p가 소수일때 페르마 소정리에 의해
1/x = x^(p-2) (mod p)
따라서 nCk = n! * (k! * (n-k)!)^(p-2) (mod p)
이다.
*/
#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

ll n, r, fac[1000001];
ll mpow(ll x, ll k) {
	if (k == 0) return 1;
	else if (k & 1) {
		return ((x%MOD)*(mpow(x, k - 1) % MOD)) % MOD;
	}
	else {
		ll t = mpow(x, k / 2) % MOD;
		return (t*t) % MOD;
	}
}
int main() {
	cin >> n >> r;
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	cout << (fac[n] * mpow((fac[r] * fac[n - r]) % MOD, (MOD - 2))) % MOD;
}