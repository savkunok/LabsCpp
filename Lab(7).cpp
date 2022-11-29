#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
string FileName1 = "file1.txt";
string FIleName2 = "file2.txt";
string FileName3 = "file3.bin";
class Exception
{
private:
    std::string msg = "Exception";
public:
    Exception(std::string _msg) : msg(_msg) {}
    const char* what() const noexcept { return msg.c_str(); }
};
    
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
    //// WRITE ////
    void writeTextText(){
		ofstream ofs;
		ofs.open(FileName1, ios::app);
		if (!ofs.is_open()) {
			throw Exception("File open error");
		}
		ofs << *this << "\n";
		ofs.close();
	}
    void writeTextBin(){
		ofstream ofs;
		ofs.open(FIleName2, ios::app);
		if (!ofs.is_open()) {
			throw Exception("File open error");
		}
		ofs.write((char*)this, sizeof(Airport));
		ofs.close();
	}
	void writeBinBin(){
		ofstream o;
		o.open(FileName3, ios::app);
		o.write(reinterpret_cast<char*>(this), sizeof(Airport));
		o.close();
	}
	//// READ ////
    static void readTextText() {
		ifstream fin;
		fin.open(FileName1);
		if (!fin.is_open()) {
			throw Exception("File open error");
		}

		string str;
		while (getline(fin, str)) {
			int ind = 0;
			cout << str << endl;
		}
		fin.close();
	}

	static void readTextBin() {
		ifstream fin;
		fin.open(FIleName2);
		if (!fin.is_open()) {
			throw Exception("File open error");
		}
		Airport t;
		while (fin.read((char*)&t, sizeof(Airport)))
		{
			cout << t << endl;
		}
		fin.close();
	}

	static void readBinBin() {
		ifstream i;
		i.open(FileName3);
		if (!i.is_open()) {
			throw Exception("File open error");
		}
		Airport temp;
		while (i.read(reinterpret_cast<char*>(&temp), sizeof(Airport))){
			cout << temp << endl;
		}
		i.close();
	}
    //// FIND ////
    static bool findTxtTxt(std::string name) {
		ifstream i;
		i.open(FileName1);
		Airport temp;
		bool flag = true;
		while (i >> temp) {
			if (temp.name == name) {
				cout << temp << endl;
				return true;
			}
		}
		return false;
	}

	static bool findTxtBin(std::string name) {
		ifstream i;
		i.open(FIleName2);
		Airport temp;
		bool flag = true;
		while (i.read(reinterpret_cast<char*>(&temp), sizeof(temp))){
			if (temp.name == name) {
				cout << temp << endl;
				return true;
			}
		}
		return false;
	}

	static bool findBinBin(std::string name) {
		ifstream i;
		i.open(FileName3);
		Airport temp;
		bool flag = true;
		while (i.read(reinterpret_cast<char*>(&temp), sizeof(temp))){
			if (temp.name == name) {
				cout << temp << endl;
				return true;
			}
		}
		return false;
	}
    //////// DELETE ///////
    static void deleteObjTxtTxt(std::string name) {
		if (findTxtTxt(name)) {
			ifstream i;
			ofstream o1;
			i.open(FileName1);
			o1.open(FileName1 + ".tmp",ios::app);
			if (!i.is_open() || !o1.is_open()) {
				throw Exception("File open error");
			}
			Airport t;
			while (i>>t) {
				if (t.name != name) {
					o1 << t <<"\n";
				}
			}
			i.close();
			o1.close();
			remove("file1.txt");
			rename("file1.txt.tmp", "file1.txt");
		}
	}

	static void deleteObjTxtBin(std::string name) {
		if (findTxtBin(name)) {
			ifstream i;
			ofstream o1;
			i.open(FIleName2);
			o1.open(FIleName2 + ".tmp");
			if (!i.is_open() || !o1.is_open()) {
				throw Exception("File open error");
			}
			Airport t;
			while (i.read(reinterpret_cast<char*>(&t),sizeof(t))) {
				if (t.name != name) {
					o1.write(reinterpret_cast<char*>(&t), sizeof(t));
				}
			}
			i.close();
			o1.close();
			remove("file2.txt");
			rename("file2.txt.tmp", "file2.txt");
		}
	}

	static void deleteObjBinBin(std::string name) {
		if (findBinBin(name)) {
			ifstream i;
			ofstream o1;
			i.open(FileName3);
			o1.open(FileName3 + ".tmp");
			if (!i.is_open() || !o1.is_open()) {
				throw Exception("File open error");
			}
			Airport t;
			while (i.read(reinterpret_cast<char*>(&t), sizeof(t))) {
				if (t.name != name) {
					o1.write(reinterpret_cast<char*>(&t), sizeof(t));
				}
			}
			i.close();
			o1.close();
			remove("file3.bin");
			rename("file3.bin.tmp", "file3.bin");
		}
	}

	friend ostream& operator<<(ostream& os, Airport& Airport1) {
		os << Airport1.planes << " " << Airport1.people << " " << Airport1.name;
		return os;
	}

	friend istream& operator>>(istream& in, Airport& Airport1) {
		in >> Airport1.planes >> Airport1.people >> Airport1.name;
		return in;
	}
    ~Airport(){}
};


int main()
{
    vector<Airport> arr{
		Airport(11,10000,"Ftoroi"),
		Airport(22,15000,"Pervi"),
		Airport(33,20000,"Sheremetievo"),
		Airport(44,40000,"Boranovichi"),
		Airport(55,35000,"BeloOzersk"),
		Airport(66,23000,"ozer")
	};
    try {
		for (auto el : arr) {
				el.writeTextText();
				el.writeTextBin();
			    el.writeBinBin();
		}
        cout << "Text file text mode" << endl;
		Airport::readTextText();
		cout << endl;

        cout << "----------deleting-------------" << endl;
        Airport::deleteObjTxtTxt("Sheremetievo");
        cout << "Text file text mode" << endl;
		Airport::readTextText();
		cout << endl;

    }catch (Exception ex) {
		cout << ex.what();
	}
    return 0;
}



