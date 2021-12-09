/*
#include <iostream>

int main() {
	int* p = new int; // 할당
	*p = 10;

	std::cout << *p << std::endl;

	delete p; // 할당 해제
	return 0;
}*/

/*
#include <iostream>

int main() {
	int a = 5;
	delete& a;
	return 0;
}
*/

#include <iostream>

int main() {
	int arr_size; // 배열의 크기를 잡을 변수 정의
	std::cout << "array size : ";
	std::cin >> arr_size; // 값을 입력 받음 
	int* list = new int[arr_size]; // list에 new를 이용하여 크기가 arr_size인 int 배열을 생성 
	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}
	for (int i = 0; i< arr_size; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}
	delete[] list;
	return 0;
}