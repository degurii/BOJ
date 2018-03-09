/*
문제
어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 
주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

출력
주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.
*/


/*
d[n]: n을 제곱수들의 합으로 표현할 때 항의 최소개수
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	fill(&d[1], &d[n+1], 0x3f3f3f3f);
	d[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j*j <= i; j++) {
			d[i] = min(d[i], d[i - j * j]);
		}
		d[i]++;
	}
	cout << d[n];
}