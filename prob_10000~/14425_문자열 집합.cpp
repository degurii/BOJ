/*
문제
총 N개의 문자열로 이루어진 집합 S가 주어진다.
입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다.
둘째 줄에는 집합 S에 포함되어 있는 문자열이 주어지며, 공백으로 구분되어져 있다.
셋째 줄에는 검사해야 하는 문자열 M개가 주어지며, 공백으로 구분되어져 있다.
입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러번 주어지는 경우는 없다.

출력
첫째 줄에 M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는지 출력한다.
*/
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string s;
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	unordered_set<string> set;
	int ans = 0;
	while (n--) {
		cin >> s;
		set.insert(s);
	}
	while (m--) {
		cin >> s;
		if (set.find(s) != set.end())
			ans++;
	}
	cout << ans;
}