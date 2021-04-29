#include <iostream>

using namespace std;
class Storage{
private:
    int nData;
    int strg[20];
public:
    Storage(int nsize) {
        nData = nsize;
        cout << "자료 " << nData << "개 입력 : ";
        for (int i = 0; i < nData; i++)
            cin >> strg[i];
    }
    void showList(){
        cout << nData << ":";
        for (int i = 0; i < nData; i++)
            cout << strg[i] << " ";
        cout << endl;
    }
    int multipleN(int n){
        int sum = 0;
        for (int i = 0; i < nData; i++)
            if (strg[i] % 3 == 0)
                sum++;
        return sum;
    }
    void add_Strg(Storage s2){
        for (int i = nData; i < nData + s2.nData; i++)
            strg[i] = s2.strg[i-nData];
        nData = nData + s2.nData;
    }
};
int main() {
    Storage s1(4);
    s1.showList();

    Storage s2(10);
    s2.showList();

    cout << "3의 배수는 " << s1.multipleN(3) << "개 입니다." << endl;
    s1.add_Strg(s2);
    s1.showList();
    return 0;
}
