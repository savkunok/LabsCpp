#include "memory.h"

MySpace::memory::memory(){
	cout << "constr memory" << endl;
	MemorySize = "noName";
}

MySpace::memory::memory(string MemorySize)
{
	cout << "constr memory" << endl;
	
	this->MemorySize = MemorySize;
	
}

MySpace::memory::~memory()
{
	cout << "destr memory" << endl;
}

void MySpace::memory::setMemorySize(string MemorySize)
{
	this->MemorySize = MemorySize;
}

void MySpace::memory::showMemoryInfo()
{
	cout << "MemorySize " << MemorySize << endl;

}
