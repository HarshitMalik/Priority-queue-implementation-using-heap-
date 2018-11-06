#include<iostream>
#include "Lec.h"
using namespace std;

Lec::Lec() {
	this->name = "none";
	this->area = 0.0;
	this->numDoor = 0;
	this->loc_X= 0;
	this->loc_Y = 0;
	this->numChair = 0;
}

Lec::Lec(string name, float area, int numDoor, int loc_X, int loc_Y, int numChair) {
	this->name = name;
	this->area = area;
	this->numDoor = numDoor;
	this->loc_X = loc_X;
	this->loc_Y = loc_Y;
	this->numChair = numChair;
}

void Lec::print(){
	cout<<"Lecture Hall name : "<<this->name<<endl;
	cout<<"Area : "<<this->area<<endl;
	cout<<"Number of doors : "<<this->numDoor<<endl;
	cout<<"Location : ( "<<this->loc_X<<" , "<<this->loc_Y<<" )"<<endl;
	cout<<"Number of chairs : "<<this->numChair<<endl;
}

int Lec::getNumChair(){
	return this->numChair;
}

string Lec::getName(){
	return this->name;
}

float Lec::getArea(){
	return this->area;
}

int Lec::getNumDoor(){
	return this->numDoor;
}

int Lec::getLoc_X(){
	return this->loc_X;
}
int Lec::getLoc_Y(){
	return this->loc_X;
}
