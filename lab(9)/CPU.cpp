#include "CPU.h"

MySpace::CPU::CPU(){
	cout << "constr CPU" << endl;
	nameOfCPU = "noName";
}

MySpace::CPU::CPU(string nameOfCPU)
{
	cout << "constr CPU" << endl;
	
	this->nameOfCPU = nameOfCPU;
	
}

MySpace::CPU::~CPU()
{
	cout << "destr CPU" << endl;
}

void MySpace::CPU::setNameOfCPU(string nameOfCPU)
{
	this->nameOfCPU = nameOfCPU;
}

void MySpace::CPU::showCPUInfo()
{
	cout << "nameOfCPU: " << nameOfCPU << endl;

}
