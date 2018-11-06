#ifndef LEC_H
#define LEC_H
#include <string>
using namespace std;

class Lec {
	private:
		string name;
		int numDoor,loc_X,loc_Y,numChair;
		float area;
	public:
		Lec();
		Lec(string, float, int, int, int, int);
		void print();
		int getNumChair();
		string getName();
		float getArea();
		int getNumDoor();
		int getLoc_X();
		int getLoc_Y();
		void operator = (Lec L1){
			this->name = L1.getName();
			this->area = L1.getArea();
			this->numDoor = L1.getNumDoor();
			this->loc_X = L1.getLoc_X();
			this->loc_Y = L1.getLoc_Y();
			this->numChair = L1.getNumChair();
    }
};

class CompareLec
{
public:
    bool operator() (Lec L1, Lec L2){
        return (L1.getNumChair() > L2.getNumChair());
    }
};

#endif
