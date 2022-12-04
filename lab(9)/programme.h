#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace MySpace {
	class Programme {
	public:
		Programme();
		Programme(string nameOfProgramme);
		~Programme();
		void setNameOfProgramme(string nameOfProgramme);
		void showProgrammeInfo();
		
	private:
		string nameOfProgramme;
		
	};

}