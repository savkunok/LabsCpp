#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Exception 
{
    private:
    string m_error;
public:
	Exception(string Exception) : m_error(Exception){}
    string what(){
        return m_error;
    }
};


class Airport
{
private:
    int plane_number;
    int people_per_day;
    std::string name;

public:
    Airport(int plane_number_, int people_per_day_, std::string name_) : plane_number(plane_number_), people_per_day(people_per_day_), name(name_)
    {}
    Airport(){
        plane_number=0;
        people_per_day=0;
        name="";
    }
    friend std::ostream& operator<<(std::ostream& str, Airport& class_){
        str << class_.plane_number << ' ' << class_.people_per_day << ' ' << class_.name << std::endl;
        return str;
    }
    friend std::istream& operator>>(std::istream& str, Airport& class_){
        str >> class_.plane_number >> class_.people_per_day >> class_.name;
        return str;
    }
    void AirportSet(int a, int b, std::string c)
    {
        plane_number = a;
        people_per_day = b;
        name = c;
    }
    void binWrite(std::ofstream& b)
    {
        b.write((char*)&plane_number, sizeof(plane_number));
        b.write((char*)&people_per_day, sizeof(people_per_day));
        b.write((char*)&name, sizeof(name));
    }
    void binRead(std::ifstream& b)
    {
        b.read((char*)&plane_number, sizeof(plane_number));
        b.read((char*)&people_per_day, sizeof(people_per_day));
        b.read((char*)&name, sizeof(name));
    }
    std::string GetName(){
        return name;
    }

    static void search(std::string toSearch, Airport& Airport1)
    {
        try
        {
            bool found = false;
            std::ifstream det("laba.bin", std::ios::binary);
            std::ofstream newdet("temp.bin", std::ios::binary);
            while (!det.eof())
            {
                det.read((char*)&Airport1, sizeof(Airport1));
                if (Airport1.GetName() == toSearch)
                {
                    std::cout << "found name:" << toSearch << std::endl;
                    found = true;
                }
                else {
                    newdet.write((char*)&Airport1, sizeof(Airport1));
                }
            }
            if (found == false)
            {
                throw Exception("there no such airporn to view\n");
            }
            
        }
        catch(Exception ex)
        {
            std::cout<<ex.what();
        }       
        remove("laba.bin");
        rename("temp.bin", "laba.bin");
    }
    ~Airport(){};

};


int main()
{
    Airport Airport1;
    /////////     TXT     /////////
    std::cout << "Write into txt file: " << std::endl;
    std::ofstream iofile("laba.txt");
    for (int i=0; i<5; i++)
    {
        int a,b;
        std:string String;
        std::cout << "Enter plane number at the " << i+1 << " airport" << std::endl;
        std::cin >> a; 
        std::cout << "Enter people per day at the" << i+1 << " airport" << std::endl;
        std::cin >> b;
        std::cout << "Enter name of the " << i+1 << " airport" << std::endl;
        std::cin >> String;
        Airport1.AirportSet(a, b, String);
        iofile << Airport1 << std::endl;
        std::cout << Airport1;
    }
    std::cout << "Read from txt file: " << std::endl;
    std::ifstream text("laba.txt");
    for (int i = 0; i < 5; i++)
    {
        text >> Airport1;
        std::cout << Airport1;
    }
    /////////     BIN     /////////
    std::cout << "Write into bin file: " << std::endl;
    std::ofstream bin("laba.bin", std::ios::binary);
    for (int i = 0; i < 5; i++)
    {
        int a,b;
        std::string String;
        std::cout << "Enter plane number at the " << i+1 << " airport" << std::endl;
        std::cin >> a; 
        std::cout << "Enter people per day at the" << i+1 << " airport" << std::endl;
        std::cin >> b;
        std::cout << "Enter name of the " << i+1 << " airport" << std::endl;
        std::cin >> String;
        Airport1.AirportSet(a, b, String);
        Airport1.binWrite(bin);
    }
    ///////// search and view /////////
    std::cout << "Enter airport name u want to view in binary file" << std::endl;
    std::string searchVal;
    std::cin >> searchVal;
    Airport::search(searchVal, Airport1);
    std::ifstream bin1("laba.bin", std::ios::binary);
    Airport1.binRead(bin1);
    std::cout << "Read: " << Airport1;
    std::cout << "All info in bin file:" << std::endl;
   
    return 0;
}
