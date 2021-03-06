/*
입력
Your program is to read from standard input.
The input consists of a single line that contains an integer, n (1 ≤ n ≤ 1,000,000,000)

출력
Your program is to write to standard output. Print exactly one line.
If the given number n is a happy number, print out HAPPY; otherwise, print out
*/
#include <iostream>
using namespace std;

int n;
bool check[1000];
bool dfs(int x) {
	if (x == 1)
		return true;
	if (check[x])
		return false;
	
	check[x] = true;
	int val = 0;
	for (int i = x; i > 0; i /= 10) {
		int k = i % 10;
		val += k * k;
	}
	dfs(val);
}
int main() {
	cin >> n;
	int val = 0;
	for (int i = n; i > 0; i /= 10) {
		int k = i % 10;
		val += k * k;
	}
	if (dfs(val))
		cout << "HAPPY";
	else
		cout << "UNHAPPY";
}