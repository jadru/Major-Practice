#include <iostream>
using namespace std;

class Stack {
private:
    int *array;
    int pos;
public:
    Stack() {
        array = new int[3];
        pos = -1;
    }
    Stack& operator <<(int a) {
        pos++;
        array[pos] = a;
        return *this;
    }
    bool operator !(){
        if (pos == -1)
            return true;
        else
            return false;
    }
    Stack& operator >>(int &a) {
        a = array[pos];
        pos--;
        return *this;
    }
    ~Stack(){
        delete [] array;
    }
};

int main(){
    Stack stack;
    stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
    while(true) {
        if(!stack) break; // stack empty;
        int x;
        stack >> x; // 스택의 탑에 있는 정수 팝
        cout << x << ' ';
    }
    return 0;
}