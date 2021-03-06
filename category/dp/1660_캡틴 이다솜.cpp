/*
N개의 대포알로 만들 수 있는 사면체의 최소 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 입력 N이 들어온다. N은 300,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 영식이가 만들 수 있는 사면체 개수의 최소값을 출력한다.
*/
#include <iostream>
using namespace std;

int n, p[10000], cnt = 1, d[300001];
int min(int a, int b) { return a < b ? a : b; }
int main() {
	cin >> n;
	int sum = 1, j = 2;
	p[0] = 1;
	for (int i = 1, j = 2, sum = 1; 1; i++) {
		sum += j;
		j++;
		if (p[i - 1] + sum > n) break;
		p[i] = p[i - 1] + sum;
		cnt++;
	}
	for (int i = 0; i < n + 1; i++)
		d[i] = i;
	for (int i = 1; i < cnt + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (j - p[i] >= 0)
				d[j] = min(d[j], d[j - p[i]] + 1);
		}
	}
	cout << d[n];
}