/*
문제
당신은 N 개의 반지를 가지고있다. 어떤 반지도 대문자 10 문자로 이루어진 문자열이 새겨져있다. 반지는 문자열의 시작과 끝이 연결된 형태로 문자가 새겨져있다. 반지에 각인된 문자열을 거꾸로 읽는 걱정은 없다.
찾고자하는 문자열이 주어졌을 때 그 문자열을 포함하는 반지가 몇 개인지를 발견하는 프로그램을 작성하라.

입력
입력은 2 + N 행된다.
첫 번째 줄에는 1 자 이상 10 자 이하의 대문자로 구성된 찾고자하는 문자열이 적혀있다.
두 번째 줄에는 반지의 개수 N (1 ≦ N ≦ 100)이 적혀있다.
2+i 줄(1 ≦ i ≦ N)엔 i개의 반지에 새겨져있고, 10 문자로 이루어진 문자열이 적혀있다.

출력
찾고자하는 문자열을 포함 반지의 개수를 나타내는 정수를 한 줄로 출력하라.
*/



/*
solution:
제한 범위가 작으므로 하나하나 확인해주면 된다.
*/
#include <iostream>
#include <string>
using namespace std;

string key;
int n;
string s;
int main() {
	cin >> key >> n;
	int ksize = key.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int l = s.size();
		s = s + s;
		for (int i = 0; i < l; i++) {
			string cmp = s.substr(i, ksize);
			if (key == cmp) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
}