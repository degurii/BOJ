/*
문제
선영이는 838호나 1004와같이 한 숫자가 두 번 이상 들어있는 집에는 절대 살지 않을 것이다.

정부는 선영이의 호텔 방 번호는 N보다 크거나 같고, M보다 작거나 같아야 한다는 조건을 걸고 신축 허가를 내주었다.
선영이의 새 호텔에는 방이 최대 몇 개 있을 수 있을까? (두 방이 같은 방 번호를 사용할 수 없다)

입력
입력은 여러 개의 테스트 케이스로 이루어져 있고, 한 줄이다.
각 줄에는 문제의 설명에 나와있는 N과 M이 주어진다. (1 ≤ N ≤ M ≤ 5000)

출력
각각의 테스트 케이스에 대해서 N보다 크거나 같고, M보다 작거나 같은 수 중에서 반복되는 숫자가 없는 것의 개수를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

int n, m;
bool foo(int x) {
	string s = to_string(x);
	bool c[10] = { 0, };
	for (auto i : s) {
		if (c[i - '0'] == false)
			c[i - '0'] = true;
		else {
			return false;
		}
	}
	return true;
}
int main() {
	while (cin >> n) {
		cin >> m;
		int ans = 0;
		for (int i = n; i <= m; i++) {
			if (foo(i))
				ans++;
		}
		cout << ans << '\n';
	}
}