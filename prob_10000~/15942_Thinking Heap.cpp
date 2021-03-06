/*
N개의 자연수를 전부 다 삽입한 후에, 자연수 k가 heap 배열의 p번째(배열의 맨 처음 공간을 0번째로 생각한다)에 위치하도록 하고 싶다.
이렇게 만드는 삽입 순서를 찾는 프로그램을 작성하시오.

입력
첫 번째 줄에 자연수 N(1 ≤ N ≤ 200,000)이 주어진다.
두 번째 줄에 자연수 k와 p(1 ≤ k, p ≤ N)가 공백으로 구분되어 주어진다.

출력
자연수 k가 heap 배열의 p번째에 위치하도록 하는 삽입 순서가 존재한다면 i번째 줄에 i번째로 삽입할 수를 출력한다.
가능한 삽입 순서가 여러 가지라면 그중 아무거나 하나를 출력해도 된다.
만약 그렇게 만드는 삽입 순서가 존재하지 않는다면 첫 번째 줄에 -1을 출력한다.
*/
#include <iostream>
#include <cmath>
using namespace std;

int n, k, p;
int c[200001];
bool check[200001];

void go(int node, int &num) {
	if (node * 2 <= n) {
		c[node * 2] = ++num;
		check[num] = true;
		go(node * 2, num);
	}
	if (node * 2 + 1 <= n) {
		c[node * 2 + 1] = ++num;
		check[num] = true;
		go(node * 2 + 1, num);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> k >> p;
	int h = (int)floor(log2(p));
	if (k <= h) {
		cout << -1;
		return 0;
	}
	
	c[p] = k;
	check[k] = true;
	for (int node = p/2, num = h; node > 0; node /= 2, num--) {
		c[node] = num;
		check[num] = true;
	}
	int num = k;
	go(p, num);
	if (num > n) {
		cout << -1;
		return 0;
	}
	for (int i = 1, j = 1; i < n + 1; i++) {
		if (c[i]) {
			cout << c[i] << '\n';
		}
		else {
			while (check[j]) {
				j++;
			}
			cout << j << '\n';
			j++;
		}
	}
}