#ifndef LAB_H
#define LAB_H
#include <string>
using namespace std;

class Lab {
	private:
		string name;
		int numDoor,loc_X,loc_Y,numComp;
		float area;
	public:
		Lab();
		Lab(string, float, int, int, int, int);
		void print();
		float getArea();
		string getName();
		int getNumDoor();
		int getNumComp();
		int getLoc_X();
		int getLoc_Y();
		void operator = (Lab L1){
			this->name = L1.getName();
			this->area = L1.getArea();
			this->numDoor = L1.getNumDoor();
			this->loc_X = L1.getLoc_X();
			this->loc_Y = L1.getLoc_Y();
			this->numComp = L1.getNumComp();
    }
};

class CompareLab
{
public:
    bool operator() (Lab L1, Lab L2){
        return (L1.getArea() > L2.getArea());
    }
};

#endif
