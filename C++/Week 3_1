#include <iostream>
#include <string>
using namespace std;
class Color{
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b){ red = r; green = g; blue = b; }
	void setColor(int r, int g, int b){ red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};
int main(){
	Color screenColor(255, 0, 0); // 빨간색
	Color *p;
	p = &screenColor; // p가 screenColor의 주소를 가지도록
	p->show(); // Red색상 출력
	Color *colors = new Color[3]; // Color의 일차원 배열 colors 선언
	p = colors; // p가 color의 주소를 
	p[0].setColor(255, 0, 0); // 빨강색 설정
	p[1].setColor(0, 255, 0); // 초록색 설정
	p[2].setColor(0, 0, 255); // 파랑색 설정
	for (int i = 0; i < 3; i++)
		p[i].show();
	return 0;
}
