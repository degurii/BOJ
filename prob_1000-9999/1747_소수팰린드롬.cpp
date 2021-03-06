/*
문제
어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다.

출력
첫째 줄에 조건을 만족하는 수를 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> prime;
bool c[3000001];

void initP() {
	c[0] = c[1] = true;
	for (int i = 2; i < 3000001; i++) {
		if (c[i]) continue;
		for (int j = i * 2; j < 3000001; j += i) {
			c[j] = true;
		}
	}
	for (int i = n; i < 3000001; i++) {
		if (!c[i]) prime.push_back(i);
	}
}

int go() {
	for (auto now : prime) {
		int l = 0;
		int a = 10;
		for (int k = now; k > 0; k /= 10, a *= 10)l++;
		bool flag = true;
		for (int k = now; k > 0; k = (k%a) / 10) {
			a /= 100;
			if (k / a != k % 10) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return now;
		}
	}
	return 0;
}
int main() {
	cin >> n;
	initP();
	cout << go();
}