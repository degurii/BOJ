/*
문제
어떤 용량을 원하는 사람을 줄에서 빼 버리면,
같은 용량을 원하는 사람들이 연속되어 있는 구간의 길이중 가장 긴 값이 최대가 되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다.
둘째 줄부터 N개 줄에는 줄을 서 있는 순서대로 각 사람이 원하는 용량 B(i)가 주어진다.
B(i)는 0보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
상근이가 만들 수 있는 가장 길이가 긴 같은 용량을 원하는 사람의 연속 구간의 길이를 출력한다.
*/









/*
이런류의 문제를 풀 때 항상 배열 맨 끝쪽에서 ans판단을 안해줘서 한두번씩 틀리게 된다.
기억해놔야 할듯.

solution:
n<=1000이므로 O(N^2)로 푼다
모두 같은 수면 저렇게 안풀리니
처음에 아무 수도 뺴지 않았을 때의 답을 먼저 구해준다.
*/
#include <iostream>
using namespace std;

int n, p[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int ans = 1, cur = 1;
	for (int i = 0; i < n - 1; i++) {
		if (p[i] == p[i + 1]) {
			cur++;
		}
		else {
			ans = (ans > cur) ? ans : cur;
			cur = 1;
		}
	}
	ans = (ans > cur) ? ans : cur;
	for (int i = 0; i < n; i++) {
		cur = 0;
		int last = -1;
		for (int j = 0; j < n; j++) {
			if (p[i] == p[j]) continue;
			if (last == -1) {
				cur++;
				last = p[j];
				continue;
			}
			else if (last != p[j]) {
				if (ans < cur) ans = cur;
				cur = 0;
			}
			cur++;
			last = p[j];
		}
		if (ans < cur) ans = cur;
	}
	cout << ans;
}