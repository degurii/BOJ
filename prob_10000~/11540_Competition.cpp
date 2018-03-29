/*
문제
Bob and Alice are participating in a programming contest as a team.
The contest has N problems which must be solved in order.
Naturally there are some problems that they cannot solve, in that case they can skip it.
There may be also problems that only Bob or Alice alone can solve.
They want to solve all the problems possible switching as few times as possible who is at the computer programming the solution.
Given the number of problems and the problems that Bob and Alice can solve,
calculate the minimum number of switches between the usage of the computer.
Anyone can start using it.

입력
The first line contains three integers N (1 ≤ N ≤ 10^9), A (1 ≤ A ≤ min(N, 5 ∗ 10^4)) and B (1 ≤ B ≤ min(N, 5 ∗ 10^4)).
The next line contains A unique integers denoting the problems Alice can solve.
The following line contains B unique integers denoting the problems Bob can solve.
The first problem is denoted by the number 1, the second by number 2, the N-th by N, and so on.

출력
Print the minimum number of switches between the usage of the computer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<int> p, q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> a >> b;
	for (int i = 0; i < a; i++) {
		int x;
		cin >> x;
		p.push_back(x);
	}
	for (int j = 0; j < b; j++) {
		int x;
		cin >> x;
		q.push_back(x);
	}
	
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	int ans = 0;
	bool c = false; // true: a, false: b
	int i = 0, j = 0;
	while (p[i] != q[j]) {
		i++;
		j++;
	}
	
	while(i < a && j < b){
		if (p[i] < q[j]) {
			i++;
			ans++;
		}
		else if (p[i] > q[j]) {
			j++;
			ans++;
		}
		else {
			i++;
			j++;
		}
	}
	cout << ans;
	
}






