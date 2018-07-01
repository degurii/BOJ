/*
입력
The input consists of:

one line with one integer n (1 ≤ n ≤ 10^5), the number of submissions;
n lines, each with a result of the judging by DOMjudge, in arbitrary order;
n lines, each with a result of the judging by Kattis, in arbitrary order.
Each result is a string of length between 5 and 15 characters (inclusive) consisting of lowercase letters.

출력
Output one line with the maximum number of judging results that could have been the same for both systems.
*/



/*
solution:
문자열 각각의 갯수를 구해둔다.
첫번째, 두번째에서 같은 문자열이 있다면 둘 중 더 작은 값을 답에 더해준다.
n제한이 10^5에 문자열을 탐색해야 하므로 탐색을 빠르게 할 수 있는 자료구조를 이용한다.
여기서는 map을 사용했다.
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
map<string, int> m1, m2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m1.find(s) == m1.end())
			m1[s] = 1;
		else
			m1[s]++;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m2.find(s) == m2.end())
			m2[s] = 1;
		else
			m2[s]++;
	}
	int ans = 0;
	for (auto i : m1) {
		if (m2.find(i.first) != m2.end()) {
			ans += (i.second < m2[i.first]) ? i.second : m2[i.first];
		}
	}
	cout << ans;
}