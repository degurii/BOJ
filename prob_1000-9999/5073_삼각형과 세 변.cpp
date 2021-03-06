/*
문제
삼각형의 세 변의 길이가 주어질 때 변의 길이에 따라 다음과 같이 정의한다.

Equilateral :  세 변의 길이가 모두 같은 경우
Isosceles : 두 변의 길이만 같은 경우
Scalene : 세변의 길이가 모두 다른 경우
단 주어진 세 변의 길이가 삼각형의 조건을 만족하지 못하는 경우에는 "Invalid" 를 출력한다.
예를 들어 6, 3, 2 가 주어지면 가장 긴 변인 6 은 다른 두 변의 합보다 크기 때문에 삼각형의 조건을 만족하지 못한다.

세 변의 길이가 주어질 때 위 정의에 따른 결과를 출력하시오.

입력
각 줄은 1000 을 넘지 않는 양의 정수 3개가 입력되며 0 0 0 이 입력되면 종료한다.

출력
각 입력에 맞는 결과 (Equilateral, Isosceles, Scalene, Invalid) 를 출력하시오.
*/
#include <iostream>
using namespace std;

int a, b, c;
int min(int e, int f) { return e < f ? e : f; }
int max(int e, int f) { return e > f ? e : f; }
int main() {
	while (1) {
		cin >> a >> b >> c;
		if (a == 0) return 0;
		int x = min(a, min(b, c));
		int z = max(a, max(b, c));
		int y = a + b + c - x - z;
		
		if (x + y <= z)
			cout << "Invalid\n";
		else if (x == y && y == z)
			cout << "Equilateral\n";
		else if ((x == y && x != z) || (y == z && y != x))
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
	
}