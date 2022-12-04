#include "winchester.h"

MySpace::Winchester::Winchester(){
	cout << "constr Winchester" << endl;
	WinchesterSize = "noName";
}

MySpace::Winchester::Winchester(string WinchesterSize)
{
	cout << "constr Winchester" << endl;
	
	this->WinchesterSize = WinchesterSize;
	
}

MySpace::Winchester::~Winchester()
{
	cout << "destr Winchester" << endl;
}

void MySpace::Winchester::setWinchesterSize(string WinchesterSize)
{
	this->WinchesterSize = WinchesterSize;
}

void MySpace::Winchester::showWinchesterInfo()
{
	cout << "WinchesterSize " << WinchesterSize << endl;

}