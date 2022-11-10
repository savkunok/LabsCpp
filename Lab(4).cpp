#include <iostream>
#include <windows.h>

using namespace std;

class TV              //B
{
protected:
	string name;

public:
	TV(){}

	TV(string name)
    {
		this->name = name;
		cout << "constr TV" << endl;
	}

	virtual ~TV()
	{
		cout << "TV Tool" << endl;
	}

	virtual int cost() = 0;
	virtual void display() = 0;
};

class newTV : public virtual TV    //P1
{
protected:
	int Cost;
    int minCost;
    int maxCost;

public:
	newTV()
	{
		Cost = 0;
        minCost = 0;
        maxCost = 0;
	}

	newTV(string name, int minCost, int maxCost ) : TV(name)
	{
		this->minCost = minCost;
        this->maxCost = maxCost;
        this->Cost = (minCost+maxCost)/2;
		cout << "constr NewTV" << endl;
	}

	~newTV() override
	{
		cout << "distr NewTV" << endl;
	}

	int cost() override
	{
		return Cost;
	}

	void display() override
	{
		cout << "Name is " << name << ", it new TV and it average cost is " << Cost << "$" << endl;
	}
};

class oldTV : public virtual TV         //P2
{
protected:
	int Cost;
    int minCost;
    int maxCost;
public:
	oldTV()
	{
		Cost = 0;
        minCost = 0;
        maxCost = 0;
	}

	oldTV(string name, int minCost, int maxCost ) : TV(name)
	{
		this->minCost = minCost;
        this->maxCost = maxCost;
        this->Cost = (minCost+maxCost)/2;
		cout << "constr oldTV" << endl;
	}

	~oldTV() override
	{
		cout << "distr oldTV" << endl;
	}

	int cost() override
	{
		return Cost;
	}

	void display() override
	{
		cout << "Name is " << name << ", it cost " << Cost << "$ "  << endl;
	}
};

class Samsung : public newTV       //P11
{
protected:
	int costOther;
	int costTV;

public:
	Samsung()
	{
	    costOther = 0;
        costTV = 0;
	}

	Samsung(string name, int minCost, int maxCost, int costOther) : TV(name), newTV(name, minCost, maxCost)
	{
		
		this->costOther = costOther;
        this->costTV = newTV::cost();
		cout << "constr Samsung" << endl;
	}

	~Samsung() override
	{
		cout << "distr Samsung" << endl;
	}

	int cost() override
	{
		return costTV + costOther;
	}

	void display() override
	{
		cout << "Name is " << name << ", it new TV and it cost " << costTV + costOther << "$ it cost of TV is " <<
			costTV << "$, cost of other parts is " << costOther << "$ " << endl;

	}
};

int main()
{
	TV* NewTV = new newTV("SamsngTV", 1000, 2000);
	TV* OldTV = new oldTV("oldTV", 1980, 1990);
	TV* samsung = new Samsung("Samsung A12HD", 1000, 2000, 200);

	TV* tvs[] = { NewTV, OldTV, samsung };

	for (int i = 0; i < 3; i++)
	{
		tvs[i]->display();
		cout << "And it cost: " << tvs[i]->cost() << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete tvs[i];
	}
}
