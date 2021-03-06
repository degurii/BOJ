/*
입력
첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다. 그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다.

출력
첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool check[101], ans[101];
int p[101];
bool dfs(int now, int start) {
	if (check[now]) return (now == start) ? true : false;
	check[now] = true;
	if (dfs(p[now], start))
		return true;
	return check[now] = false;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		cin >> p[i];
	for (int i = 1; i < n + 1; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, i);
		for (int j = 1; j < n + 1; j++)
			if (check[j]) ans[j] = true;
	}
	int a = 0;
	for (int i = 1; i < n + 1; i++)
		if (ans[i]) a++;
	cout << a << '\n';
	for (int i = 1; i < n + 1; i++)
		if (ans[i]) cout << i << ' ';
}