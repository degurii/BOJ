/*
문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만, 
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.
*/



/*
solution:
기본적인 lis(inc)를 구하고, 맨 뒤에서부터 역으로 된 lis(rev)를 구한다.
inc[i]+rev[i]의 값이 가장 큰 것이 답이다.
이 때 i번째를 두 번 세기 때문에 1을 빼준다.
*/
#include <iostream>
using namespace std;

int n, p[1001], inc[1001], rev[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
		inc[i] = rev[i] = 1;
		for (int j = 1; j < i; j++) {
			if (p[j] < p[i] && inc[i] < inc[j] + 1) {
				inc[i] = inc[j] + 1;
			}
		}
	}
	for (int i = n; i > 0; i--) {
		for (int j = n; j > i; j--) {
			if (p[j] < p[i] && rev[i] < rev[j] + 1) {
				rev[i] = rev[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		if (ans < inc[i] + rev[i])
			ans = inc[i] + rev[i];
	}
	cout << ans - 1;
}