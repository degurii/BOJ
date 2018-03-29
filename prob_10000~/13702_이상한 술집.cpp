/*
입력
첫째 줄에는 은상이가 주문한 막걸리 주전자의 개수 N, 그리고 은상이를 포함한 친구들 K명이 입력된다.
N은 10000이하의 정수이고, K는 1,000,000이하의 정수이다.
막걸리의 용량은 231 -1 보다 작거나 같은 자연수이다. (단, 항상 N ≤ K 이다. 즉, 주전자의 개수가 사람 수보다 많을 수는 없다 ) .

출력
첫째 줄에 K명에게 나눠줄 수 있는 최대의 막걸리 용량 ml 를 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int p[10000];

int foo(int m) {
	int cur = 0;
	for (int i = 0; i < n; i++)
		cur += p[i] / m;
	return cur;
}
void go(int l, int r) {
	if (l > r)
		return;
	int m = (l + r) / 2;
	int cur = foo(m);
	if (cur >= k) {
		if (ans < m)
			ans = m;
		go(m + 1, r);
	}
	else {
		go(l, m - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	go(0, p[n - 1]);
	cout << ans;
}