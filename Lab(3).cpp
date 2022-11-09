#include <iostream>  
#include <string>  
  
class factory                                               //B  
{  
private:  
    std :: string name;  
public:  
    factory(){}; 
    factory(std :: string string){ 
        this->name= string; 
    } 
    ~factory(){}    
    void setName(std :: string string){  
        this->name= string;  
    }  
    void getName(){  
        std::cout << "Name: " << this->name << std::endl;  
    }  
};  
  
  
  
class shop :  public factory                                 //P1  
{  
private:  
    std :: string productName; 
public:  
    shop(){}; 
    shop(std :: string string,std :: string string2){ 
        this->setName(string); 
        this->productName=string2; 
    } 
    ~shop(){}    
    void setShopData(std :: string string,std :: string string2) 
    {    
        this->setName(string); 
        this->productName=string2;  
    }  
    void getShopData() 
    { 
        getName(); 
        std::cout << "Product name: "<< this->productName << std::endl;  
    } 
 
}; 
 
 
 
class machine : virtual public shop                                 //P11 
{ 
private: 
    int cost;  
public: 
    machine(){}; 
    machine(std::string string,std::string string2, int cost1){ 
        this->setShopData(string,string2); 
        this->cost = cost1; 
    }; 
    ~machine(){}; 
    void setMachineData(std::string string,std::string string2, int cost1 ){   //name, product, cost 
        this->setShopData(string,string2); 
        this->cost = cost1; 
    } 
    void getMachineData() 
    { 
        getShopData(); 
        std::cout << "Machine Cost: "<< cost << std::endl; 
    } 
}; 
 
 
class worker : public factory                                 //P2  
{  
private:  
    std :: string jobTitleName; 
public:  
    worker(){}; 
    worker(std :: string string,std :: string string2){ 
        this->setName(string); 
        this->jobTitleName=string2;  
    } 
    ~worker(){}    
    void setWorkerData(std :: string string,std :: string string2)   // name, title 
    {    
        this->setName(string); 
        this->jobTitleName=string2;  
    }  
    void getWorkerData() 
    { 
        getName(); 
        std::cout << "Title: "<< this->jobTitleName << std::endl;  
    } 
 
}; 
 
 
class workerPlace : virtual public worker                                //P21 
{ 
private: 
    int id;  
public: 
    workerPlace(){}; 
    workerPlace(std::string string,std::string string2, int id1){ 
        this->setWorkerData(string,string2); 
        this->id = id1; 
    } 
    ~workerPlace(){}; 
    void setWorkerPlaceData(std::string string,std::string string2, int id1 ){ //name, title for  work, id 
        this->setWorkerData(string,string2); 
        this->id = id1; 
    } 
    void getWorkerPlaceData() 
    { 
        getWorkerData(); 
        std::cout << "Worker place id: " << id << std::endl; 
    } 
}; 
 
 
class workerPlaceInfo : public workerPlace, public machine 
{ 
private: 
    int selary; 
public: 
    workerPlaceInfo(){}; 
    workerPlaceInfo(std::string string1,std::string string2, int id, std::string string3,std::string string4, int cost, int selary1){ 
        this->setWorkerPlaceData(string1,string2,id); 
        this->setMachineData(string3,string4,cost); 
        this->selary= selary1; 
    }; 
    ~workerPlaceInfo(){}; 
    void setWorkerPlaceInfo(std::string string1,std::string string2, int id, std::string string3,std::string string4, int cost, int selary1 ){ 
        //name workerPlace, title for work, id, machine name, product name, product, cost , selary 
        this->setWorkerPlaceData(string1,string2,id); 
        this->setMachineData(string3,string4,cost); 
        this->selary= selary1; 
    } 
    void getWorkerPlaceInfo(){ 
        getWorkerPlaceData(); 
        getMachineData(); 
        std::cout << "Worker selary: " << selary << std::endl; 
    } 
}; 
 
 
 
  
int main() { 
    workerPlaceInfo workerPlaceInfo1;  
    workerPlaceInfo1.setWorkerPlaceInfo("ToyInginerPlace","ToyInginer",1,"InginerTable","Toy",100,5000); 
    //name workerPlace, title for work, id, machine name, product name, product, cost , selary
    workerPlaceInfo1.getWorkerPlaceInfo(); 
  
    return 0;  
}
