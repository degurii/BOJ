/*
문제
모든 소가 농장에 입장하려면 얼마나 걸리는 지 구해보자.

입력
첫 줄에 100 이하의 양의 정수 N이 주어진다.
다음 N줄에는 한 줄에 하나씩 소의 도착 시각과 검문 시간이 주어진다. 각각 1,000,000 이하의 양의 정수이다.

출력
모든 소가 농장에 입장하는 데 걸리는 최소 시간을 출력한다.
*/



/*
solution:
대충 구현한다
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[101];
int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p + 1, p + n + 1);
	int t = 0;
	for (int i = 1; i < n + 1; i++) {
		if (t < p[i].first) t = p[i].first;
		t += p[i].second;
	}
	cout << t;
}