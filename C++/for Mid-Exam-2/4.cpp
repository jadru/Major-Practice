#include <iostream>
using namespace std;

class item {
public:
    int iPrice;
    string iName;
    item(); // 키보드에서 item의 이름과 가격을 입력하여 멤버 변수 초기화
    void setPrice(int cprice); // cprice로 가격 변경
};
item::item(){
    cout << "이름과 가격 입력 >> ";
    cin >> iName >> iPrice;
}
void item::setPrice(int cprice){

}

class Storage{
private:
    int nData;
    item *itemStrg;
public:
    Storage(int nsize) {
        nData = nsize;
        itemStrg = new item[nData];
    }
    void showList(){
        for (int i = 0; i < nData; i++)
            cout << itemStrg[i].iName << "항목은 " << itemStrg[i].iPrice << "원" << endl;
    }
    void changePrice(string s, int newprice);
    ~Storage() {
        delete [] itemStrg;
    }
};
void Storage::changePrice(string s, int newprice){
    for (int i = 0; i < nData; i++)
        if (itemStrg[i].iName == s)
            itemStrg[i].iPrice = newprice;
}
int main() {
    Storage items(5);
    items.showList();

    string s;
    int newprice;
    cin >> s >> newprice;
    items.changePrice(s, newprice);
    items.showList();
    return 0;
}