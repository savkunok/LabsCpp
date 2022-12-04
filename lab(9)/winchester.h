#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace MySpace {
	class Winchester {    
	public:
		Winchester();
		Winchester(string WinchesterSize);
		~Winchester();
		void setWinchesterSize(string WinchesterSize);
		void showWinchesterInfo();
		
	private:
		string WinchesterSize;
		
	};

}