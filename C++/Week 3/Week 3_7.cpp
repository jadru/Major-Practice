#include <iostream>
#include <string>
using namespace std;

class Circle {
	int r; // 원 반지름 값
public:
	void setRadius(int radius) {
		r = radius;
	}
	double getArea() {
		return r * r * 3.14;
	}
};

int main(){
	Circle *c = new Circle[3];
	for (int i = 0; i < 3; i++){
		int f;
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> f;
		(c + i)->setRadius(f);
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++){
		if ((c + i)->getArea() > 100.0){
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다.";
	return 0;
}
