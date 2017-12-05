/*
문제
어느날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에,
그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라. (그 수가 존재한다면)

입력
N을 입력받는다. N는 최대 10^5개의 숫자로 구성되어 있다.

출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.
*/






/*
solution:
30의 배수 : 2, 3, 5의 배수
2,5의배수 -> 10의배수, 끝자리가 0
3의배수 -> 각 자릿수를 더해서 3으로 나눠떨어진다
가장 큰수 -> 내림차순 정렬
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;

bool isThreeMul(string s){
	int sum = 0, len = s.size();
	for (int i = 0; i < len; i++)
		sum += (s[i] - '0');
	if (sum % 3 == 0)
		return true;
	else
		return false;
}
char s[100001];
int main(){
	cin >> s;
	int len = strlen(s), last = 0;
	sort(s, s+len, greater<char>());
	last = s[len - 1] - '0';
	if (!isThreeMul(s) || last != 0)
		cout << -1;
	else
		cout << s;
}