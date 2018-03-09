/*
문제
n개의 정수로 이루어진 임의의 수열이 주어진다.
우리는 이 중 연속된 몇 개의 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 숫자는 한 개 이상 선택해야 한다.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
여기서 정답은 12+21인 33이 정답이 된다.

입력
첫째 줄에 정수 n(1≤n≤100,000)이 주어지고
둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 답을 출력한다.
*/



/*
solution:
d[n]: n번째 수에서 끝나는 연속합
d[i] = max(p[i], d[i-1]+p[i])
*/
#include <iostream>
using namespace std;

int n, p[100001], d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
		d[i] = p[i];
		if (d[i - 1] + p[i] > d[i])
			d[i] = d[i - 1] + p[i];
	}
	int ans = d[1];
	for (int i = 2; i < n + 1; i++) {
		ans = (ans > d[i]) ? ans : d[i];
	}
	cout << ans;
}