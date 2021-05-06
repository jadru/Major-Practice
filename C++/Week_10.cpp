#include<iostream>
#include<string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0){ this->radius = radius; }
	int getRadius() { return radius;  }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name = "Circle") {
		setRadius(radius);
		this->name = name;
	}
	void show(){
		cout << "반지름이 " << getRadius() << "인 " << name << endl ;
	}
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
};

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point{
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "BLACK") {
		move(x, y);
		this->color = color;
	}
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() { cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl; }
};

void q_1(){
	NamedCircle waffle(3, "waffle");
	waffle.show();
}

void q_2() {
	NamedCircle pizza[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 1; i <= 5; i++){
		int radius; string name;
		cout << i << ">> ";
		cin >> radius >> name;
		pizza[i - 1].setName(name);
		pizza[i - 1].setRadius(radius);
	}
	int max = pizza[0].getRadius();
	string name = pizza[0].getName();
	for (int i = 0; i < 5; i++){
		if (max < pizza[i].getRadius()){
			max = pizza[i].getRadius();
			name = pizza[i].getName();
		}
	}
	cout << "가장 면적이 큰 피자는 " << name << "입니다." << endl;
}

void q_3() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}

void q_4(){
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}

int main() {
	q_1();
	q_2();
	q_3();
	q_4();
}
