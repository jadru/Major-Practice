#include<iostream>
#include<string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0){
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	Book& operator+= (int price);
	Book& operator-= (int price);
	friend bool operator== (Book &a, int price) {
		if (a.price == price) return true;
		else return false;
	}
	friend bool operator== (Book &a, string title) {
		if (a.title == title) return true;
		else return false;
	}
	friend bool operator== (Book &a, Book b) {
		if (a.title == b.title&&a.price == b.price&&a.pages == b.pages) return true;
		else return false;
	}

	friend bool operator! (Book &a){
		if (a.price == 0) return true;
		else return false;
	}
};

Book& Book::operator+= (int price) {
	this->price += price;
	return *this;
}
Book& Book::operator-= (int price) {
	this->price -= price;
	return *this;
}

class Color{
public:
	int R, G, B;
	Color(int R = 255, int G = 0, int B = 255){
		this->R = R; this->G = G; this->B = B;
	}
	void show(){
		cout << R << ' ' << G << ' ' << B << endl;
	}
	friend Color operator+ (Color &a, Color &b){
		Color c;
		c.R = a.R + b.R;
		if (c.R > 255) c.R = 255;
		c.G = a.G + b.G;
		if (c.G > 255) c.G = 255;
		c.B = a.B + b.B;
		if (c.B > 255) c.B = 255;
		return c;
	}
	friend bool operator== (Color &a, Color &c){
		if (a.R == c.R&&a.G == c.G&&a.B == c.B) return true;
		else false;
	}
	
};

void Q1(){
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
void Q2() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}

void Q3(){
	Book book("벼룩시장", 0, 50);
	if (!book) cout << "공짜다" << endl;
}

void Q5(){
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음" << endl;
	else
		cout << "보라색 아님" << endl;
}

int main(void){
	Q1();
	Q2();
	Q3();
	Q5();
	return 0;
}

