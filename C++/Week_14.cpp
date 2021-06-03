#include<iostream>
#include<string>
using namespace std;

class Circle{
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = ""){
		this->radius; this->name = name;
	}
	friend istream& operator >> (istream& ins, Circle &a);
	friend ostream& operator << (ostream& stream, Circle a);
};

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = ""){
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}

	friend istream& operator >> (istream& ist, Phone &a);
	friend ostream& operator << (ostream& stream, Phone a);
};

class Check{
	friend istream& operator >> (istream& ist, Check prompt);
};
istream& operator >> (istream& ins, Circle &a){
	cout << "반지름 >> ";
	ins >> a.radius;
	cout << "이름 >> ";
	ins >> a.name;
	return ins;
}
ostream& operator << (ostream& stream, Circle a){
	stream << "(반지름" << a.radius << "인 " << a.name << ")";
	return stream;
}
istream& operator >> (istream& ist, Phone &a){
	cout << "이름:";
	ist >> a.name;
	cout << "전화번호:";
	ist >> a.telnum;
	cout << "주소:";
	ist >> a.address;
	return ist;
}
ostream& operator << (ostream& stream, Phone a){
	stream << "(" << a.name << "," << a.telnum << "," << a.address << ")";
	return stream;
}
istream& operator >> (istream& ist, Check prompt){
	cout << "암호?";
	return ist;
}
bool search(int a, int x[], int cnt){
	for (int i = 0; i < cnt; i++){
		if (x[i] == a)
			return true;
	}
	return false;
}
void prac_10_4(){
	int x[] = { 1, 10, 100, 5, 4 };
	if (search(100, x, 5)) cout << "100이 배열 x에 포함되어 있다";
	else cout << "100이 배열 x에 포함되어 있지 않다";
}
void prac_11_8(){
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
void prac_11_9() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}
void prac_11_10(){
	Check prompt;
	string password;
	while (true) {
		cin >> prompt >> password;
		if (password == "C++"){
			cout << "login success!!" << endl;
			break;
		}
		else{
			cout << "login fail. try again!!" << endl;
		}
	}
}

int main(){
	prac_10_4();
	//prac_11_8();
	//prac_11_9();
	//prac_11_10();
	return 0;
}
