/*
입력
The input consists of a single line of text of no more than 250 characters. At least one character will be a letter.

출력
Output consists of a graph with 26 horizontal bars.
The letters of the alphabet (upper case) form the y axis, in alphabetical order from top to bottom.
Each is followed by a space, a vertical bar, another space then a star for every time that letter appears in the supplied text.
There are no spaces between the stars.
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int abc[26];
int main() {
	getline(cin, s);
	for (int i = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			abc[s[i] - 'a']++;
		else if ('A' <= s[i] && s[i] <= 'Z')
			abc[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << char(i + 'A') << " | ";
		for(int j=0; j<abc[i];j++)
			cout.put('*');
		cout << '\n';
	}
	
}