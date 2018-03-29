/*
입력
첫째 줄에 거스름돈 액수 n(1 ≤ n ≤ 100,000)이 주어진다.

출력
거스름돈 동전의 최소 개수를 출력한다. 만약 거슬러 줄 수 없으면 -1을 출력한다.
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 5) {
		if (n == 3 || n == 1)
			cout << -1;
		else
			cout << n / 2;
		return 0;
	}
	int a = n / 5;
	n %= 5;
	
	if (n & 1) { 
		n += 5;
		a--;
	}
	cout << a + (n / 2);
}