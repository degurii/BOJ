/*
입력
첫 번째 줄에 알파벳 대소문자, 공백으로 구성된 문자열이 주어진다.
문자열의 길이는 최대 1,000자이다. 문자열의 맨 앞과 맨 끝에 공백이 있는 경우는 없고, 공백이 연속해서 2번 이상 주어지는 경우도 없다.

출력
첫 번째 줄에 입력으로 주어진 문자열을 적절히 축약해 "UCPC"로 만들 수 있으면 "I love UCPC"를 출력하고, 만들 수 없으면 "I hate UCPC"를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	getline(cin, s);
	int d = 0;
	for (int i = 0; s[i]; i++) {
		if (d == 0 && s[i] == 'U')
			d++;
		else if (d == 1 && s[i] == 'C')
			d++;
		else if (d == 2 && s[i] == 'P')
			d++;
		else if (d == 3 && s[i] == 'C') {
			d++;
			break;
		}
	}
	if (d == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
}