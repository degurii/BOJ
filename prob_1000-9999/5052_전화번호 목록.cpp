/*
문제
전화번호 목록이 주어진다. 이 때, 이 목록이 일관성이 있는지 없는지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 50)
각 테스트 케이스의 첫째 줄에는 전화번호의 수 n이 주어진다. (1 ≤ n ≤ 10000)
다음 n개의 줄에는 목록에 포함되어 있는 전화번호가 하나씩 주어진다. 전화번호의 길이는 길어야 10자리이며, 목록에 있는 두 전화번호가 같은 경우는 없다.

출력
각 테스트 케이스에 대해서, 일관성 있는 목록인 경우에는 YES, 아닌 경우에는 NO를 출력한다.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie {
	struct Node {
		int abc[10];
		bool valid, haveChild;
		Node() :valid(false), haveChild(false) {
			for (int i = 0; i < 10; i++) abc[i] = -1;
		}
	};

	vector<Node> p;
	int root;

	int init() {
		p.emplace_back();
		return (int)p.size() - 1;
	}
	Trie() {
		root = init();
	}

	bool add(int node, string &s, int idx) {
		if (idx == s.size()) {
			p[node].valid = true;
			if (p[node].haveChild) return false;
			return true;
		}
		
		int c = s[idx] - '0';
		
		if (p[node].abc[c] == -1) {
			p[node].abc[c] = init();
			p[node].haveChild = true;
		}
		
		int child = p[node].abc[c];
		if (p[child].valid) return false;
		return add(child, s, idx + 1);
	}
	bool add(string &s) {
		return add(root, s, 0);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n;
		Trie trie;
		bool ans = true;
		while (n--) {
			cin >> s;
			if (!trie.add(s))
				ans = false;
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}