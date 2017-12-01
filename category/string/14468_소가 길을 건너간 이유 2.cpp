/*
문제

어떤 두 소는 어떤 방법으로 걷든 그 경로가 어딘가에서 만나야 될 수도 있다. 그런 소가 총 몇 쌍인지 구해 보자.

입력
첫 줄에 52글자의 문자열이 주어진다. 각 글자는 알파벳 대문자이며, 각 알파벳이 정확히 두 번씩 나타난다.

출력
경로가 무조건 만나는 소가 몇 쌍인지 출력한다.
*/




/*
solve:
원에 52개의 점이 있고, 두 점을 이은 호가 겹치는지 판단하면 된다
대충 O(26* N^2)정도
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int main() {
	cin >> s;
	s += s;
	int ans = 0;
	for (int i = 0; i < 52; i++) {
		if (s[i] == 0)continue;
		vector<int> check('Z' + 1);
		for (int j = i + 1; 1; j++) {
			if (s[i] == s[j]) {
				s[j] = 0;
				for (int k = 'A'; k < 'Z' + 1; k++) {
					if (check[k])ans++;
				}
				break;
			}
			check[s[j]] ^= 1;
		}
	}
	cout << ans;
}