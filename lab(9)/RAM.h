#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace MySpace {
	class RAM {
	public:
		RAM();
		RAM(string nameOfRAM);
		~RAM();
		void setNameOfRAM(string nameOfRAM);
		void showRAMInfo();
		
	private:
		string nameOfRAM;
		
	};

}