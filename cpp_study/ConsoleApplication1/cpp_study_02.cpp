// 참조자의 도입

/*
#include <iostream>

int change_val(int *p) { // change 함수의 인자 p에 number의 주소값을 전달
	*p = 3; // *p 를 통해 number를 참조하여 number의 값을 3으로 변경 

	return 0;
}

int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}
*/

/*
#include <iostream>

int main() {
	int a = 3;
	int& another_a =  a;
	another_a = 5;
	std::cout << "a :" << a << std::endl;
	std::cout << "another_a :" << another_a << std::endl;

	return 0;
}
*/

/*
#include <iostream>

int chage_val(int &p) {
	p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}
*/

// change_val 안에서 p = 3; 이라 하는 것은 main 함수의 number에 number = 3;

// 참조자 이해하기
/*
#include <iostream>

int main() {
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	std::cout << "x : " << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
	
	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}
*/

// 상수에 대한 참조자
/*
#include <iostream>
int main() {
	int &ref = 4;
	const int &ref = 4;
	std::cout << ref << std::endl;
}
*/
/*
// 레퍼런스의 배열과 배열의 레퍼런스
int a, b;
int& arr[2] = { a,b };
// 레퍼런스의 레퍼런스, 레페런스의 배열, 레퍼런스의 포인터는 존재할 수 없다.
*/
/*
#include <iostream>

int main() {
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr; // ref가 arr를 참조하도로고 함

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}
*/
/*
int function() {
	int a = 2;
	return a;
}

int main() {
	int b = function(); // function 안에 정의된 a라는 변수의 값이 b에 복사되었습니다. 여기서 주목할 점은 복사 되었다는 점입니다. 
	return 0; 
}
*/

/*
int& function() { // 참조자를 리턴
	int a = 2;
	return a; // a는 함수의 리턴과 함께 사라진다. 
}

int main() {
	int b = function(); // 본체는 사라지고 별명만 남아 있는 상황 
	b = 3;
	return 0;
}

// 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심해야 합니다.

*/

// 외부 변수의 레퍼런스를 리턴 
/*
int& function(int& a) {
	a = 5;
	return a; // 레퍼런스 리턴 
	// 위와 같이 인자로 받은 레퍼런스를 그대로 리턴 
	
}

int main() {
	int b = 2;
	int c = function(b);
	return 0;
}

// 전체 복사 VS 포인터 주소 복사

*/

// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기

/*
int function() {
	int a = 5;
	return a; // 리턴값은 바로 사라진다.
}

int main() {
	int& c = function();
	return 0;
	
}

*/


/*
#include <iostream>

int function() {
	int a = 5;
	return a;
}


int main() {
	const int& c = function();
	std::cout << "c : " << c << std::endl;
	return 0;

	// 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장된다.

}

*/

#include <iostream>

typedef struct Animal { // 구조체 생성
	char name[30];  // 이름
	int age; // 나이
	
	int health; // 체력
	int food; // 배부른 정도
	int clean; // 깨끗한 정도
} Animal; // typedef 를 통해 struct Animal을 Animal로 간추림


void create_animal(Animal* animal) {
	std::cout << "동물의 이름?";
	std::cin >> animal->name;
	
	std::cout << "동물의 나이?";
	std::cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal* animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;


}

void one_day_pass(Animal* animal) {
	// 하루가 지나면
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}


void show_stat(Animal* animal) {
	std::cout << animal->name << "의 상태" << std::endl;
	std::cout << "체력    : " << animal-> health<< std::endl;
	std::cout << "배부음    : " << animal-> food<< std::endl;
	std::cout << "청결    : " << animal-> clean<< std::endl;
}

int main() {
	Animal* list[10];
	int animal_num = 0;

	for (;;) {
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기" << std::endl;
		std::cout << "3. 상태 보기" << std::endl;

		int input;
		std::cin >> input;

		switch (input) {
			int play_with;
		case 1:
			list[animal_num] = new Animal;
			create_animal(list[animal_num]); // Animal의 각 값들을 초기화

			animal_num++;
			break;

		case 2:
			std::cout << "누구랑 놀게? : ";
			std::cin >> play_with;

			if (play_with < animal_num) play(list[play_with]);
			
			break;

		case 3:
			std::cout << "누구껄 보게? : ";
			std::cin >> play_with;
			if (play_with < animal_num) show_stat(list[play_with]);
			break;
			
		}

		for (int i = 0; i != animal_num; i++) {
			one_day_pass(list[i]);
		}
	}
	for (int i = 0; i != animal_num; i++) {
		delete list[i];
	}
}











