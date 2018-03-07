/*
문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에
합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.
*/


/*
LIS와 같음.
대신 길이대신 합의 크기를 비교한다
*/
#include <iostream>
using namespace std;

int n, p[1001], d[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
		d[i] = p[i];
		for (int j = 1; j < i; j++) {
			if (p[j] < p[i] && d[i] < d[j] + p[i]) {
				d[i] = d[j] + p[i];
			}
		}
	}
	int ans = d[1];
	for (int i = 2; i < n + 1; i++)
		if (ans < d[i]) ans = d[i];
	cout << ans;
}