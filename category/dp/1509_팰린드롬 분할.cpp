/*
문제
세준이는 어떤 문자열을 팰린드롬으로 분할하려고 한다.
예를 들어, ABACABA를 팰린드롬 분할하면, {A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}가 된다.
분할의 개수의 최소값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열이 주어진다. 이 문자열의 최대길이는 2,500이다.

출력
첫째 줄에 팰린드롬 분할의 개수의 최소값을 출력한다
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int d[3000], pal[3000][3000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (int i = 0; s[i]; i++) {
		pal[i][i] = 1;
		if (s[i] == s[i + 1]) pal[i][i + 1] = 1;
	}
	int n = s.size();
	for (int k = 3; k < n + 1; k++) {
		for (int i = 0; i + k - 1 < n; i++) {
			int j = i + k - 1;
			if (pal[i + 1][j - 1] && s[i] == s[j]) pal[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		d[i] = 0x3f3f3f3f;
		if (pal[0][i]) d[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (pal[j][i]) {
				d[i] = min(d[i], d[j - 1] + 1);
			}
		}
	}
	cout << d[n - 1];
}