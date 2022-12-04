#include <iostream>
#include "PersonalComp.h"
using namespace std;



int main()
{
  try {
		MySpace::PersonalComp w1 = MySpace::PersonalComp(1000,"Computer_1","4,2Gz","1TB","1TB","windows 10","16GB");
		cout << endl;
		w1.showInfo();
		cout << endl;
	} catch (exception ex) {
		cout << ex.what() << endl;
	}
    return 0;
}
