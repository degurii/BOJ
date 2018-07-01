/*
문제
여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

입력
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다.
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다
각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.

출력
출력은 표준 출력을 사용한다.
만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> p;
		int cnt = 0;
		string ans = "YES\n";
		for (int i = 0; p[i]; i++) {
			if (p[i] == '(')
				cnt++;
			else {
				if (cnt == 0) {
					ans = "NO\n";
					break;
				}
				else {
					cnt--;
				}
			}
		}
		if (cnt > 0) ans = "NO\n";
		cout << ans;
	}
}