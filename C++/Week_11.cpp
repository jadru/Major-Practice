#include<iostream>
#include<string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; // src를 다른 단위로 변환한다.
	virtual string getSourceString() = 0; // src 단위 명칭
	virtual string getDestString() = 0; // dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run(){
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
protected:
	string getSourceString() { return "원"; }
	string getDestString() { return "달러"; }
	double convert(double src) { return src / Converter::ratio; }
public:
	WonToDollar(double ratio) : Converter(ratio){}
};

class KmToMile : public Converter {
protected:
	string getSourceString() { return "Km"; }
	string getDestString() { return "Mile"; }
	double convert(double src) { return src / Converter::ratio; }
public:
	KmToMile(double ratio) : Converter(ratio){}
};

class LoopAdder {
	string name;
	int x, y, sum;
	void read() {
		cout << name << ":" << endl;
		cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
		cin >> x >> y;
	}
	void write(){
		cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
	}
protected:
	LoopAdder(string name = ""){
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run(){
		read();
		sum = calculate();
		write();
	}
};

class ForLoopAdder : public LoopAdder{
protected:
	virtual int calculate(){
		int sum = 0;
		for (int i = getX(); i <= getY(); i++){
			sum += i;
		}
		return sum;
	}
public:
	ForLoopAdder(string name = "") : LoopAdder(name){

	}
};

class WhileLoopAdder : public LoopAdder{
protected:
	virtual int calculate(){
		int sum = 0;
		int i = getX();
		int j = getY();
		while (i <= j){
			sum += i;
			i++;
		}
		return sum;
	}
public:
	WhileLoopAdder(string name = "") : LoopAdder(name){

	}
};

class DoWhileLoopAdder : public LoopAdder{
protected:
	virtual int calculate(){
		int sum = 0;
		int i = getX();
		do{
			sum += i;
			i++;
		} while (i <= getY());
		return sum;
	}
public:
	DoWhileLoopAdder(string name = "") : LoopAdder(name){

	}
};

//class GameObject { // 추상클래스
//protected:
//	int distance; // 한번 이동 거리
//	int x, y; // 현재 위치
//public:
//	GameObject(int startX, int startY, int distance){ // 초기 위치와 이동거리 설정
//		this->x = startX, this->y = startY;
//		this->distance = distance;
//	}
//	virtual ~GameObject() {}; // 가상 소멸자
//
//	virtual void move() = 0; // 이동한 후 새로운 위치로 x, y 변경
//	virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴
//
//	int getX() { return x; }
//	int getY() { return y; }
//	bool collide(GameObject *p){ // 이 객체가 객체 p와 충돌했으면 true 리턴
//		if (this->x == p->getX() && this->y == p->getY())
//			return true;
//		else
//			return false;
//	}
//};
//
//class Human : public GameObject{
//public:
//	Human()
//};

void prac_1(){
	WonToDollar wd(1010); // 1달러에 1010원
	wd.run();
}
void prac_2() {
	KmToMile toMile(1.609344);
	toMile.run();
}
void prac_3() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}
void prac_4() {
	WhileLoopAdder whileloop("While Loop");
	DoWhileLoopAdder dowhileloop("Do while Loop");

	whileloop.run();
	dowhileloop.run();
}

//void openChallenge(){
//	cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl << endl;
//	char gameboard[10][20] = { '-', };
//}
int main(){
	prac_1();
	prac_2();
	prac_3();
	prac_4();
	return 0;
}
