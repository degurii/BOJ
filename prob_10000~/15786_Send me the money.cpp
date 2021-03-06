/*
석규가 기억하는 알파벳 N글자와 포스트잇 M개가 주어질 때, 해당 포스트잇에 적힌 알파벳이 비밀번호일 가능성이 있는지 여부를 판단하여 보자.

입력
입력의 첫째 줄에 석규가 기억하는 원본 알파벳의 수 N(1 ≤ N ≤ 100)과 포스트잇의 개수 M(1 ≤ M ≤ 1000)이 주어진다.
다음 줄에 길이가 N인 알파벳 대문자로 이루어진 문자열 S가 주어진다.
이 후 M개의 줄에 알파벳 대문자로 이루어진 판별해야 할 포스트잇들이 주어진다. 모든 포스트잇에 적힌 문자열은 1000자 이하이다.

출력
M개의 줄에 가능성 여부를 “true” , “false”로 답하여라.
*/
#include <string>
#include <iostream>
using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		bool c = false;
		for (int j = 0, idx = 0; x[j]; j++) {
			if (x[j] == s[idx]) idx++;
			if (idx == n) {
				c = true;
				break;
			}
		}
		if (c) cout << "true\n";
		else cout << "false\n";
	}
}