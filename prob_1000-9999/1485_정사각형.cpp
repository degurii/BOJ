/*
문제
네 점이 주어졌을 때, 네 점을 이용해 정사각형을 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 네 줄로 이루어져 있으며, 점의 좌표가 한 줄에 하나씩 주어진다.
점의 좌표는 -100,000보다 크거나 같고, 100,000보다 작거나 같은 정수이다. 같은 점이 두 번 이상 주어지지 않는다.

출력
각 테스트 케이스마다 입력으로 주어진 네 점을 이용해서 정사각형을 만들 수 있으면 1을, 없으면 0을 출력한다.
*/







/*
solution:
생각나는대로 짬
모든 변의 길이가 같고, 두 대각선의 길이가 같으면 정사각형
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
	double x, y;
	Node(double x = 0, double y = 0) :x(x), y(y) {}
} p[5];
int t;

double dist(Node x, Node y) {
	return sqrt((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		bool ok = false;
		for (int i = 1; i < 5; i++) cin >> p[i].x >> p[i].y;
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				if (i == j)continue;
				int a = 0, b = 0;
				for (int k = 1; i < 5; i++)
					if (k != i && k != j) {
						a = k;
						break;
					}
				for (int k = 1; k < 5; k++)
					if (k != i && k != j && k != a) {
						b = k;
						break;
					}

				if ((dist(p[i], p[a]) == dist(p[i], p[j]) || dist(p[i], p[b]) == dist(p[i], p[j])) && dist(p[i], p[j]) == dist(p[a], p[b]) && (dist(p[i], p[a]) == dist(p[j], p[b]) && dist(p[i], p[b]) == dist(p[j], p[a]))) {
					ok = true;
					break;
				}
			}
			if (ok)break;
		}
		cout << ok << '\n';
	}
}
