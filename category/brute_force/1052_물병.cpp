/*
문제
이런 제약 때문에, N개로 K개를 넘지않는 비어있지 않은 물병을 만드는 것이 불가능할 수도 있다.
다행히도, 새로운 물병을 살 수 있다. 상점에서 사는 물병은 물이 1리터 들어있다.

입력
첫째 줄에 N과 K가 주어진다. N은 10^7보다 작거나 같은 자연수이고, K는 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 상점에서 사야하는 물병의 최소값을 출력한다. 만약 정답이 없을 경우에는 -1을 출력한다.
*/







/*
solution:
이진수로 만들었을 때 1의 개수가 k보다 작은 n이상의 최소의 정수를 만드는 문제이다.
n <= 10,000,000 이므로 2^24 (대략 1600만)까지 1 씩 더해가면서 판단하면 된다.
n을 이진수로 만들면 길이는 logN
O(NlogN)으로 풀 수 있다.
카테고리도 브루트포스임
대충 풀면됨



사실 더 빨리 푸는 방법이 있다.
다음에 다시 풀어봐야겠다.
*/
#include <iostream>
#include <string>
using namespace std;

int n, k, ans;
int main() {
	cin >> n >> k;
	string s;
	int num1 = 0;
	while (n > 0) {
		s = to_string(n % 2) + s;
		num1 += n % 2;
		n /= 2;
	}
	bool ok = false;
	if (num1 <= k)
		ok = true;
	while (!ok && n + ans <= (1 << 24)) {
		ans++;
		num1 = 0;
		int ripple = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			int t = s[i] - '0';
			t += ripple;
			s[i] = t % 2 + '0';
			num1 += t % 2;
			ripple = t / 2;
		}
		if (ripple) {
			s = "1" + s;
			num1++;
		}
		if (num1 <= k)
			ok = true;
	}
	if (ok)
		cout << ans;
	else
		cout << -1;
}