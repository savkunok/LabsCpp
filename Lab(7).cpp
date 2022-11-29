#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
string FileName1 = "file1.txt";
string FIleName2 = "file2.txt";
string FileName3 = "file3.bin";

class Airport
{
private:
    int planes;
    int people;
    std::string name;
public:
    Airport(){
        planes=0;
        people=0;
        name="";
    }
    Airport(int a, int b, std::string c){
        this->name=c;
        this->people=b;
        this->planes=a;
    }

	~Airport(){}
	
};

