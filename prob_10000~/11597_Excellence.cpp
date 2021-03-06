/*
입력
The first line of input contains a single positive integer n (1 ≤ n ≤ 105 , n is even), the number of students who want to enter the online programming tournament.
Each of the following n lines contains one single integer si (1 ≤ si ≤ 106), the rating of student i.

출력
Print, on a single line, the maximum value, X, such that David can form teams where every team has a total rating greater than or equal to X.
*/


/*
solution:
정렬 후 양 끝에서부터 서로 더해가면서
그 합이 가장 작은걸 고르면 된다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, p[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n / 2; i++) {
		int cur = p[i] + p[n - i - 1];
		if (ans > cur) {
			ans = cur;
		}
	}
	cout << ans;
}