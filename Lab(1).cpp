#include <iostream>
#include <string>
#include <vector>


static int ID = 0;

class Accountant;

class Worker{
private:
	int id;
	std :: string name;
	int selary;
public:
    Worker(){

    }
    Worker(int a, std::string b, int c){
        this->id=a;
        this->name=b;
        this->selary=c;
    }
	~Worker()
	{
		std::cout << "Destructor complete work\n";
	}
	void getData();
	void in();
	friend Accountant;
};

class Accountant{
public:
	void changeSelary(Worker* arr);
};

void Worker::getData(){
	std::cout << "Worker id is " << id << " name is " << name << " and his selary is " << selary << "$" << std::endl;
}

void Accountant::changeSelary(Worker* arr){
		while (1){
			std::cout << "Enter selary of worker with name " << (*arr).name << ": ";
			int tmp;
			std::cin >> tmp;
			if (tmp < 0){
				std::cout << "You write is wrong selary and its < 0" << std::endl;
			}
			else{
				(*arr).selary=tmp;
				break;
			}
		}
}

void Worker::in(){
	std::cout << "Enter name: ";
	std::cin >> name;
	id = ID;
	ID++;
	std::cout << "Enter selary: ";
	std::cin >> selary;
}

int main(){
	int id, cost = 0;
	std::string name;
	Worker* arr;
	arr = new Worker[3];
	for (int i = 0; i < 3; i++){
		arr[i].in();
	}
	for (int i = 0; i < 3; i++){
		arr[i].getData();
	}
	Accountant prodavec;

	for (int i = 0; i<1;){
		std::cout << "Do u want to change someone's selary?(enter 1 if yes)" << std::endl;
		int tmp;
		std::cin>>tmp;
		if (tmp==1){
			std::cout << "Enter id of worker you want to change selary" << std::endl;
			int id;
			std::cin>>id;
			prodavec.changeSelary(&arr[id]);
		}
		else{
			break;
		}
	}
	for (int i = 0; i < 3; i++){
		arr[i].getData();
	}
}
