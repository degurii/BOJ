/*
문제
N개의 구간이 주어졌을 때, 이에 대한 구간 그래프의 최대 클리크를 구하시오.

입력
입력의 첫 줄에는 구간의 수를 나타내는 자연수 N(1≤N≤300,000)이 주어진다.
다음 N개의 줄에 각 구간의 시작점과 끝점을 나타내는 두 자연수 Si, Ei가 공백으로 구분되어 주어진다. (1 ≤ Si < Ei ≤ 109)

출력
첫 줄에 최대 클리크의 크기 s를 출력한다.
둘째 줄에는 클리크에 있는 정점들의 번호 s개를 공백으로 구분하여 출력한다.
출력 순서는 상관없으며, 만약 최대 클리크가 여러 가지인 경우 그 중 아무거나 출력한다.
*/


/*
solution:
시작점, 끝점 상관없이 좌표값에 따라 정렬한 뒤
어떤 점에서 겹치는 선분이 몇개인지 카운트한다.
그중 최댓값을 구한 뒤 그 선분이 어떤 선분과 겹치는지 출력한다.
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct Node {
	int val, open, num;
	Node(int v = 0, int o = 0, int n = 0) :val(v), open(o), num(n) {}
	bool operator < (const Node &o) const {
		if (val == o.val)
			return open < o.open;
		return val < o.val;
	}
};
int d[300001];
bool check[300001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<Node> p;
	for (int i = 1, s = 0, e = 0; i < n + 1; i++) {
		cin >> s >> e;
		p.push_back(Node(s, 1, i));
		p.push_back(Node(e, 2, i));
	}
	sort(p.begin(), p.end());

	int cnt = 0;
	for (Node node : p) {
		if (node.open == 1) {
			d[node.num] = cnt;
			cnt++;
		}
		else if (node.open == 2) {
			cnt--;
		}
	}
	int maxi = -1;
	int num = 0;
	for (int i = 1; i < n + 1; i++) {
		if (maxi < d[i]) {
			maxi = d[i];
			num = i;
		}
	}
	for (Node node : p) {
		if (node.open == 1) {
			if (node.num == num) {
				cout << d[node.num] + 1 << '\n';
				for (int i = 1; i < n + 1; i++) {
					if (check[i]) cout << i << ' ';
				}
				cout << node.num;
				break;
			}
			check[node.num] = true;
		}
		else if (node.open == 2) {
			check[node.num] = false;
		}
	}
}