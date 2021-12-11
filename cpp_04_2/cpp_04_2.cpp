/* 함수의 오버로딩 */
#include <iostream>

void print(int x) {
	std::cout << "int : " << x << std::endl;
}
/*void print(char x) {
	std::cout << "char : " << x << std::endl;
}*/

void print(double x) {
	std::cout << "double : " << x << std::endl;
}

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

	return 0;
}

// 함수의 이름이 같더라도 인자가 다르면 다른 함수라고 판단
// C++ 에서는 컴파일러가 알아서 적합한 인자를 가지는 함수를 찾아서 호출

