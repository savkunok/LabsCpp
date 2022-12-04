#include "programme.h"

MySpace::Programme::Programme(){
	cout << "constr Programme" << endl;
	nameOfProgramme = "noName";
}

MySpace::Programme::Programme(string nameProgramme)
{
	cout << "constr Programme" << endl;
	
	this->nameOfProgramme = nameOfProgramme;
	
}

MySpace::Programme::~Programme()
{
	cout << "destr Programme" << endl;
}

void MySpace::Programme::setNameOfProgramme(string nameOfProgramme)
{
	this->nameOfProgramme = nameOfProgramme;
}

void MySpace::Programme::showProgrammeInfo()
{
	cout << "nameOfProgramme: " << nameOfProgramme << endl;

}