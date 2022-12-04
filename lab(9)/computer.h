#pragma once
#include "CPU.h"
#include "memory.h"
#include "winchester.h"
#include "programme.h"
#include "RAM.h"

#include <iostream>
#include <string>
using namespace std;

namespace MySpace {

	class computer : public CPU, public memory, public Winchester, public Programme, public RAM  {
	private:
		string name;
	public:
		computer();
		computer(string forComputer,string forCPU, string forMemory,string forWinchester,string forProgramme,string ForRAM);
		~computer();
		void showCoputerInfo();
	};
}