/*
입력
첫째 줄에 정수 n과 k(1 ≤ k ≤ n ≤ 3 · 105)가 주어집니다.
둘째 줄에 n개의 정수가 공백을 사이에 두고 주어집니다. i번째 정수는 ai이며 0보다 크고 108보다 작거나 같습니다.

출력
첫째 줄에 키파가 아케인스톤에 모을 수 있는 경험치의 합의 최댓값을 출력합니다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n, k, p[400000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		sum += p[i];
	}
	
	ll ans = 0;
	sort(p, p + n);
	for (int i = 0; i < k; i++) {
		sum -= p[i];
		ans += sum;
	}
	cout << ans;
}