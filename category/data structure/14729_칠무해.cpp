/*
시간 제한	메모리 제한
10 초		16 MB

문제
조(Joe)는 중앙대학교 교수이고, 논리회로 설계 과목을 담당하고 있다.
그는 수업을 하면서 7명의 학생을 제외한 나머지 학생들에게 좋은 학점을 주겠다고 약속을 하였다.
Joe 교수님을 돕기 위해서 학생들의 최종 성적이 주어질 때, 그의 연구실인 You See Lab으로 데려갈 성적이 좋지 못한 7명의 학생, 칠무해의 성적을 뽑아보자.

입력
첫째 줄에 학생의 수 N(8 ≤ N ≤ 10,000,000)이 주어진다.
둘째 줄부터 N개의 줄에는 학생들의 성적이 무작위로 주어진다. 성적은 최소 0점부터 최대 100점까지 0.001 점 단위로 부여된다.

출력
하위 7명의 성적을 점수가 낮은 순으로 각 줄마다 출력한다.
하위 7명의 성적의 커트 라인에 동점자가 있을 경우에도 7명만 출력을 하면 된다.
*/






/*
solution:
n<=10,000,000 이고, 제한시간 10초에 메모리제한 16MB이다.
모든 원소를 저장할 수 없다.

list를 이용한다.
첫 7개를 sorting하고
숫자를 입력받으면서 list의 마지막 원소(제일 큰 값) 보다 작은 경우
대소관계가 유지되게 삽입하고, 마지막 원소는 삭제한다.
*/
#pragma warning(disable:4996)
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

list<double> p;
int n;
int main() {
	scanf("%d", &n);
	double x;
	int i = 0;
	for (; i<7; i++) {
		scanf("%lf", &x);
		p.push_back(x);
	}
	p.sort();
	int s[7] = { 0, };
	for (; i < n; i++) {
		scanf("%s", s);
		double x = 0;
		for(int i=)
		if (x >= p.back()) continue;
		else {
			int j = 0;
			auto it = upper_bound(p.begin(), p.end(), x);
			p.insert(it, x);
			p.pop_back();
		}
	}
	for (auto it : p)
		printf("%.3lf\n", it);
}