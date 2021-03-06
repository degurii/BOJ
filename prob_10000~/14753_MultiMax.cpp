/*
입력
Your program is to read from standard input.
The input starts with a line containing an integer, n (3 ≤ n ≤ 10,000), where n is the number of cards.
In the following line, n numbers on the cards are given. These numbers are integers between -1,000 and 1,000 inclusively.

출력
Your program is to write to standard output. Print exactly one line which contains the maximum product.
*/

/*
solution:
가능한 답은
+++, ++, --, --+
배열을 정렬해서
저렇게 나올 수 있는 값들을 비교해서 그 중 가장 큰 값을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		p.push_back(x);
	}
	sort(p.begin(), p.end());
	cout << max({ p[0] * p[1], p[0] * p[1] * p[n - 1], p[n - 1] * p[n - 2], p[n - 1] * p[n - 2] * p[n - 3] });
}
