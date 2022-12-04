#include "PersonalComp.h"

MySpace::PersonalComp::PersonalComp()
{
	cout << "constr PersonalComp" << endl;
}

MySpace::PersonalComp::PersonalComp(int cost,string forComputer,string forCPU, string forMemory,string forWinchester,string forProgramme,string ForRAM ):
	computer(forComputer,forCPU,forMemory,forWinchester,forProgramme,ForRAM)
{
	cout << "Constr PersonalComp" << endl;
	this->cost = cost;
}

MySpace::PersonalComp::~PersonalComp()
{
	cout << "destr PersonalComp" << endl;
}

void MySpace::PersonalComp::showInfo()
{
	computer::showCoputerInfo();
	cout << "cost= " << cost << endl;
}