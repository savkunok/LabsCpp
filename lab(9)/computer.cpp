#include "computer.h"


MySpace::computer::computer()
{
	cout << "constr computer" << endl;
	name = "noName";

}

MySpace::computer::computer(string forComputer,string forCPU, string forMemory,string forWinchester,string forProgramme,string forRAM)
{
	cout << "constr computer" << endl;
	this->name = forComputer;
    this->setNameOfCPU(forCPU);
    this->setMemorySize(forMemory);
    this->setWinchesterSize(forWinchester);
    this->setNameOfProgramme(forProgramme);
    this->setNameOfRAM(forRAM);
}

MySpace::computer::~computer()
{
	cout << "destr computer" << endl;
}

void MySpace::computer::showCoputerInfo()
{   
    showCPUInfo;
    showMemoryInfo;
    showWinchesterInfo;
    showProgrammeInfo;
    showRAMInfo;
	cout <<"name: "<< name <<endl;
}