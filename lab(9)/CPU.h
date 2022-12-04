#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace MySpace {
	class CPU {
	public:
		CPU();
		CPU(string nameOfCPU);
		~CPU();
		void setNameOfCPU(string nameOfCPU);
		void showCPUInfo();
		
	private:
		string nameOfCPU;
		
	};

}