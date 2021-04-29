#include <iostream>

using namespace std;
class Storage{
private:
    int nData;
    int *strg;
public:
    Storage(int nsize) {
        nData = nsize;
        strg = new int[nData];
        cout << "자료 " << nData << "개 입력 : ";
        for (int i = 0; i < nData; i++){
            cin >> strg[i];
            for (int j = 0; j < i; j++)
                if (strg[j] == strg[i]){
                    cout << "<중복>";
                    i--;
                }
        }
    }
    void showList(){
        cout << nData << ":";
        for (int i = 0; i < nData; i++)
            cout << strg[i] << " ";
        cout << endl;
    }
    void add_Strg(Storage s2){
        int temp[nData + s2.nData];
        int equals = 0;
        for (int i = 0; i < nData; i++)
            temp[i] = strg[i];
        for (int i = 0; i < s2.nData; i++){
            bool same = false;
            int is_not_same = s2.strg[i];
            for (int j = 0; j < nData; j++){
                if (strg[j] == is_not_same){
                    equals++;
                    same = true;
                    break;
                }
            }
            if (!same) temp[nData + i - equals] = s2.strg[i]; 
        }
        free(strg);
        for (int i = 0; i < nData + s2.nData - equals; i++)
            strg[i] = temp[i];
        nData = nData + s2.nData - equals;
    }
    ~Storage(){
        delete [] strg;
    }
};
int main() {
    Storage s1(4);
    s1.showList();

    Storage s2(10);
    s2.showList();

    s1.add_Strg(s2);
    s1.showList();
    return 0;
}
