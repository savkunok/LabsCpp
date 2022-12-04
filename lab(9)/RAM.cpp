#include "RAM.h"

MySpace::RAM::RAM(){
	cout << "constr RAM" << endl;
	nameOfRAM = "noName";
}

MySpace::RAM::RAM(string nameOfRAM)
{
	cout << "constr RAM" << endl;
	
	this->nameOfRAM = nameOfRAM;
	
}

MySpace::RAM::~RAM()
{
	cout << "destr RAM" << endl;
}

void MySpace::RAM::setNameOfRAM(string nameOfRAM)
{
	this->nameOfRAM = nameOfRAM;
}

void MySpace::RAM::showRAMInfo()
{
	cout << "nameOfRAM: " << nameOfRAM << endl;

}
