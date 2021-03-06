/*
사전이 주어졌을 때, 이 모듈을 사용하면서 이와 같이 각 단어를 입력하기 위해 버튼을 눌러야 하는 횟수의 평균을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스의 첫째 줄에 사전에 속한 단어의 개수 N이 주어지며(1 ≤ N ≤ 10^5),
이어서 N개의 줄에 1~80글자인 영어 소문자로만 이루어진 단어가 하나씩 주어진다.
이 단어들로 사전이 구성되어 있으며, 똑같은 단어는 두 번 주어지지 않는다.
각 테스트 케이스마다 입력으로 주어지는 단어의 길이 총합은 최대 106이다.

출력
각 테스트 케이스마다 한 줄에 걸쳐 문제의 정답을 소수점 둘째 자리까지 반올림하여 출력한다.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string words[100001];
struct Trie {
	struct Node {
		int abc[26];
		bool valid;
		int numChild;
		Node(): valid(false), numChild(0){
			for (int i = 0; i < 26; i++) abc[i] = -1;
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
	
	void add(int node, string &s, int idx) {
		if (idx == s.size()) {
			p[node].valid = true;
			return;
		}
		int c = s[idx] - 'a';
		if (p[node].abc[c] == -1) {
			p[node].abc[c] = init();
			p[node].numChild++;
		}
		int child = p[node].abc[c];
		add(child, s, idx + 1);
	}
	void add(string &s) {
		add(root, s, 0);
	}

	int search(int node, string &s, int idx, int val) {
		if (idx == s.size()) {
			return val;
		}
		
		int c = s[idx] - 'a';
		int child = p[node].abc[c];
		if (idx == 0 || p[node].numChild > 1 || p[node].valid) {
			val++;
		}
		return search(child, s, idx + 1, val);
	}
	int search(string &s) {
		return search(root, s, 0, 0);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cout << fixed;
	cout.precision(2);

	int n;
	while (cin >> n) {
		Trie trie;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> words[i];
			trie.add(words[i]);
		}
		for (int i = 0; i < n; i++) {
			sum += trie.search(words[i]);
		}
		cout << (double)sum / n << '\n';
	}
}