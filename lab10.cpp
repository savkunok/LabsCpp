#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string path1 = "firstFile.txt";

int GetNumberOfWords(string str, const char toFind){
	int count = 0;
	for (int i = 0; i < str.length();)
	{
		int ind1 = -1;
		if ((ind1 = str.rfind(" ")) == -1) {
			break;
		}
		auto s1 = str.substr(ind1 + 1);
		if (s1.find(toFind) != -1) {
			count++;
			
		}
		str.erase(ind1);
	}
	if (str.find(toFind) != -1) {
		count++;
		
	}
	return count;
}

void readAndWrite(const char toFind) {
	try {
		fstream file1;
		file1.open(path1);
		cout << path1 << " file open" << endl;
		string str;
		int countStr = 1;
		while (getline(file1, str)) {
			cout << "Geted string " << countStr++ <<" : "<<str<< endl;
			cout<<"number of chars in the string = "<< GetNumberOfWords(str, toFind)<< endl;
			
		}
		file1.close();
		cout << path1 << " file close" << endl;

	
	} catch (exception ex) {
		cout << ex.what() << endl;
		cout << "ошибка открытия файла" << endl;
	}	
}





int main() {
	char toFind;
	cout<< "Enter char to find"<<endl;
	cin >> toFind;

	readAndWrite(toFind);
}
