/*
N�� �־����� ��, fibonacci(N)�� ȣ������ ��, 0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �����Ǿ��ִ�.
ù° �ٿ� N�� �־�����. N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
�� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.
*/


/*
solution:
n<=40�̹Ƿ� O(2^N)���� ���غ��°� �Ұ����ϴ�.
dp�� �̿��ϴµ� �Ǻ���ġ���� �ƴ϶� 0�� 1�� ������ �����Ѵ�
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