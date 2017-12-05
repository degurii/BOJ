/*
문제
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 어떤 인접한 원소끼리를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때, 묶은 수는 서로 곱한 후에 더한다.
예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.
수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.
수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N이 주어진다. N은 10,000보다 작다.
둘째 줄부터 N개의 줄에, 수열의 각 수가 주어진다. 수열의 수는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

출력
수를 적절히 묶어 그 합이 최대값을 출력한다. 정답은 항상 231보다 작다.
*/





/*
solution:
양수는 큰 순서대로, 음수는 작은 순서대로 두개씩 짝지어 곱한다
짝지어지지 않은 음수가 있고 0이 있다면, 곱해서 0으로 만든다
1은 곱하지 않고 그냥 더하는게 이득
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
int n;
vector<int> neg, pos;
int zerocnt, ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			ans++;
		else if (x > 0)
			pos.push_back(x);
		else if (x < 0)
			neg.push_back(x);
		else
			zerocnt = 1;
	}
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());
	for (int i = 0, l = pos.size(); i < l - 1; i += 2) {
		ans += pos[i] * pos[i + 1];
	}
	for (int i = 0, l = neg.size(); i < l - 1; i += 2) {
		ans += neg[i] * neg[i + 1];
	}
	if (neg.size() % 2 == 1) {
		if (!zerocnt) ans += neg.back();
	}
	if (pos.size() % 2 == 1)
		ans += pos.back();
	cout << ans;
}