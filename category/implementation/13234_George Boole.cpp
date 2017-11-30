/*
����
In this problem you��ll read one of such operations and write the correct result.

�Է�
Read a single line from the standard input. The line will contain three words with the format:
value1 operation value2.
The fields value1 and value2 will be either true or false.
The field operation will be either AND or OR.

���
Print either true or false.
*/
#include <iostream>
#include <string>
using namespace std;

string a, o, b;
bool x, y;
int main() {
	cin >> a >> o >> b;
	x = (a == "true") ? 1 : 0;
	y = (b == "true") ? 1 : 0;
	bool result = (o == "AND") ? x&y : x | y;
	if (result) cout << "true";
	else cout << "false";

}