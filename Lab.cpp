#include<iostream>
#include "Lab.h"
using namespace std;

Lab::Lab() {
	this->name = "none";
	this->area = 0.0;
	this->numDoor = 0;
	this->loc_X = 0;
	this->loc_Y = 0;
	this->numComp = 0;
}

Lab::Lab(string name, float area, int numDoor, int loc_X, int loc_Y, int numComp) {
	this->name = name;
	this->area = area;
	this->numDoor = numDoor;
	this->loc_X = loc_X;
	this->loc_Y = loc_Y;
	this->numComp = numComp;
}

void Lab::print(){
	cout<<"Lecture Hall name : "<<name<<endl;
	cout<<"Area : "<<area<<endl;
	cout<<"Number of doors : "<<numDoor<<endl;
	cout<<"Location : ( "<<loc_X<<" , "<<loc_Y<<" )"<<endl;
	cout<<"Number of computer : "<<numComp<<endl;
}

float Lab::getArea(){
	return this->area;
}
int Lab::getNumComp(){
	return this->numComp;
}

string Lab::getName(){
	return this->name;
}

int Lab::getNumDoor(){
	return this->numDoor;
}

int Lab::getLoc_X(){
	return this->loc_X;
}
int Lab::getLoc_Y(){
	return this->loc_X;
}
