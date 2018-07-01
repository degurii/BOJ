/*
문제
현재 대한민국 해군에 소속되어있는 준하는 문제를 풀기 위해 매일같이 사이버 지식 정보방 통칭 싸지방에 다닌다. 그러나 최근 문제가 생겼다. 싸지방에 사람이 몰려 컴퓨터 수가 모자라게 된 것이다. 이런 사태를 도저히 용납할 수 없었던 준하는 곧 전역하는 선임을 설득해 민원을 넣도록 하는 데 성공했다.
마침내 부대에서는 민원을 받아들이기로 하였고, 컴퓨터를 증설하기로 했다. 또한, 컴퓨터 간의 사용률에 따라 다른 성능의 컴퓨터를 설치하고자 한다.
하지만 예산이 부족해 사람 수 만큼 컴퓨터를 살 수가 없었다. 고심에 고심을 거듭한 준하는 모든 사람이 항상 정해진 시간에 싸지방을 이용한다는 사실을 발견했다.

컴퓨터가 있는 자리에는 1번부터 순서대로 번호가 매겨져 있다.
모든 사람은 싸지방에 들어왔을 때 비어있는 자리 중에서 번호가 가장 작은 자리에 앉는 것이 규칙이다.
준하가 발견한 사실과 이용 규칙을 가지고,
모든 사람이 기다리지 않고 싸지방을 이용할 수 있는 컴퓨터의 최소 개수와 자리별로 몇 명의 사람이 사용했는가를 구하시오.

입력
첫째 줄에 사람의 수를 나타내는 N이 주어진다. (1≤N≤100,000)
둘째 줄부터 N개의 줄에 걸쳐서 각 사람의 컴퓨터 이용 시작 시각 P와 종료 시각 Q가 주어진다. (0≤P<Q≤1,000,000)
시작 시각이나 종료 시각이 다른 사람과 겹치는 경우는 없다.

출력
첫째 줄에 사람이 모든 사람이 기다리지 않아도 되는 컴퓨터의 최소 개수 X를 출력한다.
둘째 줄에는 1번 자리부터 X번 자리까지 순서대로 각 자리를 사용한 사람의 수를 띄어쓰기 간격으로 출력한다.
*/





/*
solution:
시간에 따라 정렬하는데, 누구인지, 들어온건지 나온건지도 같이 저장한다.
들어온걸 1, 나간걸 -1이라 저장했다.

비어있는 자리를 체킹해야하는데 가장 작은 자리부터 빠져야 하므로
자동으로 정렬이 되는 set을 사용한다.

빠른 시간부터 보면서
현재 싸지방에 있는 인원과 들어왔던 인원의 최댓값도 업데이트 한다.

누군가 들어오는 경우,
  i) set이 비어있다면
    남는 자리가 없다는 말이고, 이는 cur == max이다.
    따라서 다음 번호의 컴퓨터를 주면 된다.
  ii) set이 비어있지 않다면
    set의 첫번째 원소(가장 작은 값)를 자리로 배정해준다.

  자리를 배정해 준 뒤 해당 좌석의 사용인원수를 하나 증가시킨다.

누군가 나가는 경우,
  해당하는 사람이 사용하던 좌석을 set에 넣어둔다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n;
vector<int> snum;
vector<pair<int, pair<int, int> > > p; // 시간, 사람, 출/입
set<int> seat;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	snum.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		p.push_back({ u,{i, 1} });
		p.push_back({ v, {i, -1} });
	}
	sort(p.begin(), p.end());
	vector<int> ans(n + 1);
	int cur = 0, maxi = 0;
	for (int i = 0, l = p.size(); i < l; i++) {
		auto tmp = p[i];
		int e = tmp.second.second;
		int t = tmp.first;
		int now = tmp.second.first;
		if (e > 0) {
			cur++;
			maxi = (maxi > cur) ? maxi : cur;
			if (seat.empty()) {
				snum[now] = cur;
			}
			else {
				snum[now] = *(seat.begin());
				seat.erase(seat.begin());
			}
			ans[snum[now]]++;
		}
		else {
			cur--;
			seat.insert(snum[now]);
		}
	}
	cout << maxi << '\n';
	for (int i = 1; i < maxi + 1; i++) {
		cout << ans[i] << ' ';
	}
}