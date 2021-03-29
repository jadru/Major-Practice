#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string a; int cnt = 0; int *alpabet = new int[26] { 0, };
public:
	Histogram(string s){
		a = s + '\n';
	}
	void put(string s){
		a = a + s;
	}
	void putc(char c){
		a = a + c;
	}
	void print(){
		for (int i = 0; i < a.length(); i++){
			char c = a.at(i);
			if ('A' <= c && c <= 'Z')
				c = c + 32;
			if ('a' <= c && c <= 'z'){
				alpabet[c - 'a']++;
				cnt++;
			}
		}
		cout << a << endl << endl << "총 알파벳 수 " << cnt
			<< endl << endl;
		for (int i = 0; i < 26; i++){
			cout << (char)('a' + i) << " (" << alpabet[i] << ")\t: ";
			for (int j = 0; j < alpabet[i]; j++)
				cout << "*";
			cout << endl;
		}
	}
};
int main(){
	Histogram elvisHisto("Wish men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
	return 0;
}
