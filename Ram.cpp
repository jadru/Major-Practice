#include "Ram.h"
#include <iostream>
using namespace std;

char Ram::read(int address){
	address -= 100;
	return mem[address];
}

void Ram::write(int address, char value){
	address -= 100;
	mem[address] = value;
}

Ram::Ram(){

}

Ram::~Ram(){
	cout << "메모리 제거됨";
}
