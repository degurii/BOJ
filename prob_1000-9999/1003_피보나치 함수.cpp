/*
N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 구성되어있다.
첫째 줄에 N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
*/


/*
solution:
n<=40이므로 O(2^N)으로 다해보는건 불가능하다.
dp를 이용하는데 피보나치값이 아니라 0과 1의 개수를 저장한다
*/
#include <iostream>
using namespace std;

struct Node{
	int z, o;
	Node(int z=0, int o=0): z(z), o(o){}
	Node operator + (const Node &other) {
		return Node(z + other.z, o + other.o);
	}
}d[41];

Node fib(int n) {
	if (n == 0) 
		return Node(1, 0);
	else if (n == 1) 
		return Node(0, 1);
	
	if (d[n].z != 0 || d[n].o != 0)
		return d[n];
	return d[n] = fib(n - 1) + fib(n - 2);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Node a = fib(n);
		cout << a.z << ' ' << a.o << '\n';
	}
}