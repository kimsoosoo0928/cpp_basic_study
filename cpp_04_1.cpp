// 객체란, 변수들과 참고 자료들로 이루어진 소프트웨어 덩어리 이다.
// 객체가 현실 세계에서의 존재하는 것들을 나타내기 위해서는 추상화라는 과정이 필요하다.

// 외부에서 어떠한 객체의 인스턴스 변수의 값을 바꾸지 못하고 오직 객체[의 인스턴스 함수를 통해서만 가능하다.
/*

Animal animal;
// 초기화 과정 생략 

animal.food += 100; // --> 불가능 
animal.food.increase_food(100); // --> 가능

// 인스턴스 메소드를 통해서 간접적으로 조절하는 것을 캡슐화라고 부릅니다.
*/

#include <iostream>

class Animal {
private:
	int food;
	int weight;

public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}

	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "이 동물의 food    : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
}; 

int main() {
	Animal animal; // Animal 클래스의 인스턴스 animal을 만들게 된 것
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}

