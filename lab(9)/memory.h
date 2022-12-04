#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace MySpace {
	class memory {    
	public:
		memory();
		memory(string MemorySize);
		~memory();
		void setMemorySize(string MemorySize);
		void showMemoryInfo();
		
	private:
		string MemorySize;
		
	};

}