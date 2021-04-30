#include <iostream>
using namespace std;
class SortedArray {
    int size; // 현재 배열의 크기
    int *p; // 정수 배열에 대한 포인터
    void sorted(); // 정수 배열을 오름차순으로 정렬
public:
    SortedArray(); // p는 NULL로 size는 0으로 초기화
    SortedArray(SortedArray& src); // 복사 생성자
    SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달받음
    ~SortedArray(); // 소멸자
    SortedArray operator + (SortedArray& op2) {
        SortedArray temp;
        temp.size = this->size + op2.size;
        temp.p = new int[temp.size];
        for (int i = 0; i < this->size; i++){
            temp.p[i] = p[i];
        }
        for (int i = size; i < size+op2.size; i++){
            temp.p[i] = op2.p[i - size];
        }
        return temp;
    }
    SortedArray& operator =(const SortedArray& op2) {
        delete [] p;
        this->p = new int[op2.size];
        for (int i = 0; i < op2.size; i++)
            this->p[i] = op2.p[i];
        this->size = op2.size;
        sorted();
        return *this;
    }
    void show(); // 배열의 원소 출력
};
void SortedArray::sorted(){
    sort(p, p+size);
}
void SortedArray::show(){
    cout << "배열 출력 : ";
    for (int i = 0; i < size; i++)
        cout << p[i] << ' ';
}
SortedArray::SortedArray() {
    p = new int[1];
    size = 0;
    sorted();
}
SortedArray::SortedArray(SortedArray& src){
    this->size = src.size;
    p = new int[this->size];
    for (int i = 0; i < src.size; i++)
        this->p[i] = src.p[i];
}
SortedArray::SortedArray(int p[], int size) {
    this->p = new int[size];
    for (int i = 0; i < size; i++)
        this->p[i] = p[i];
    this->size = size;
    sorted();
}
SortedArray::~SortedArray() {
    delete [] p;
}

int main(){
    int n[] = { 2, 20, 6 };
    int m[] = { 10, 7, 8, 30 };
    SortedArray a(n, 3), b(m, 4), c;

    c = a + b; // +, = 연산자 작성 필요
    // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

    a.show();
    b.show();
    c.show();

    return 0;
}