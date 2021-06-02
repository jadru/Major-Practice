#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	Circle& operator++(){
		radius++;
		return *this;
	}
	Circle operator++(int x){
		Circle tmp = *this;
		radius++;
		return tmp;
	}
	friend Circle operator+(int op1, Circle op2);
};

Circle operator+(int op1, Circle op2){
	Circle tmp;
	tmp.radius = op2.radius + op1;
	return tmp;
}

void prac_4_5(){
	while (true){
		string input;
		cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl << ">>";
		getline(cin, input);
		if (input == "exit") break;
		srand((unsigned)time(0));
		int n = rand() % input.length();
		for (int i = 0; i < input.length(); i++){
			if (n == i){
				input[i] = rand() % 25 + 97;
			}
		}
		cout << input << endl;
	}
}

void prac_4_6(){
	while (true){
		string input;
		cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl << ">>";
		getline(cin, input);
		if (input == "exit") break;
		string inverse = ""; int cnt = 0;
		for (int i = 0; i < input.length(); i++){
			if (input[i] == ' ' || i + 1 == input.length()){
				for (int j = cnt; j <= i; j++) {
					inverse = input[j] + inverse;
				}
				cnt = i;
			}
		}
		cout << inverse << endl;
	}
}

void prac_7_8() {
	Circle a(5), b(4);
	++a; // 반지름을 1 증가시킨다
	b = a++; // 반지름을 1 증가시킨다.
	a.show();
	b.show();
}

void prac_7_9() {
	Circle a(5), b(4);
	b = 1 + a; // b의 반지름을 a의 반지름에 1을 더한 것으로 변경
	a.show();
	b.show();
}

int main(){

	prac_4_5();
	prac_4_6();
	prac_7_8();
	prac_7_9();

	return 0;
}
