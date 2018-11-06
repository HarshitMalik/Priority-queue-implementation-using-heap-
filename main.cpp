#include<iostream>
#include<fstream>
#include<vector>
#include "pQueue.hpp"
#include "functions.h"
#include "Lab.h"
#include "Lec.h"
using namespace std;

int main(){
	
	int choice;
	char c;

	vector <Lec> lecList;
	vector <Lab> labList;
	readLabData(labList);
	readLecData(lecList);

	pQueue<Lab,CompareLab>labPriorQ(labList);
	pQueue<Lec,CompareLec>lecPriorQ(lecList);
	pQueue<Lab,CompareLab>::locator locLab(&labPriorQ);
	pQueue<Lec,CompareLec>::locator locLec(&lecPriorQ);
	
	do{
		cout<<"\n  ===== MAIN MENU =====\n";
		cout<<" 1) Insert\n 2) Get minimum\n 3) Remove minimum\n 4) Remove last element\n";
		cout<<" 5) Replace last Element\n 6) Get size \n 7) Print Last element\n 8) Print List in Order\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
						{
							int ch1;
							cout<<"  Add\n 1) Labs\n 2) Lecture halls\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1)
									addLabManually(labPriorQ);
							else if(ch1 == 2)
									addLecManually(lecPriorQ);
							else
								cout<<"Invalid choice !\n";
							break;
						}
			case 2:{
							int ch1;
							cout<<" 1) Get minimum Lab\n 2) Get minimmum Lecture halls\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1){
								cout<<" Lab with minimum area :\n\n";
									labPriorQ.min().print();
							}
							else if(ch1 == 2){
								cout<<" Lecture hall with minimum chairs :\n\n";
									lecPriorQ.min().print();
							}
							else
								cout<<"Invalid choice !\n";
						break;
						}
			case 3:{
							int ch1;
							cout<<" 1) Remove minimum Lab\n 2) Remove minimmum Lecture hall\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1){
								labPriorQ.removeMin();
								cout<<" Lab with minimum area removed !\n";
							}
							else if(ch1 == 2){
								lecPriorQ.removeMin();
								cout<<" Lecture hall with minimum chairs removed !\n";
							}
							else
								cout<<"Invalid choice !\n";
						break;
						}
			case 4:{
							int ch1;
							cout<<" 1) Remove last added Lab\n 2) Remove last added Lecture hall\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1){
								locLab = labPriorQ.getLastElmntLoc();
								labPriorQ.remove(locLab);	
								cout<<"\nLast lab removed !\n";
							}
							else if(ch1 == 2){
								locLec = lecPriorQ.getLastElmntLoc();
								lecPriorQ.remove(locLec);
								cout<<"\nLast lecture hall removed !\n";
							}
							else
								cout<<"Invalid choice !\n";
							break;
							}
			case 5:{
							int ch1;
							cout<<" 1) Replace last added Lab\n 2) Replace last added Lecture hall\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1){
								string name;
								int numDoor, numComp,location_X,location_Y;
								float area;	
								cout<<"Enter name of new lab :  ";
								cin>>name;
								cout<<"Enter area of the new lab  :  ";
								cin>>area;
								cout<<"Enter number of doors :  ";
								cin>>numDoor;	
								cout<<"Enter x co-ordinate of location  :  ";
								cin>>location_X;
								cout<<"Enter y co-ordinate	of location  :  ";
								cin>>location_Y;
								cout<<"Enter number of computers in new lab  :  ";
								cin>>numComp; 
								Lab *tempLab = new Lab(name, area, numDoor, location_X, location_Y, numComp);
								locLab = labPriorQ.getLastElmntLoc();
								labPriorQ.replace(locLab,*tempLab);
								cout<<"\nLast lab replaced !\n";
							}
							else if(ch1 == 2){
								string name;
								int numDoor, numChair,location_X,location_Y;
								float area;	
								cout<<"Enter name of new lecture hall :  ";
								cin>>name;
								cout<<"Enter area of the new lecture hall  :  ";
								cin>>area;
								cout<<"Enter number of doors :  ";
								cin>>numDoor;	
								cout<<"Enter x co-ordinate of location  :  ";
								cin>>location_X;
								cout<<"Enter y co-ordinate	of location  :  ";
								cin>>location_Y;
								cout<<"Enter number of chairs in new lecture hall  :  ";
								cin>>numChair;
								Lec *tempLec = new Lec(name, area, numDoor, location_X, location_Y, numChair);
								locLec = lecPriorQ.getLastElmntLoc();
								lecPriorQ.replace(locLec,*tempLec);
								cout<<"\nLast lecture hall replaced !\n";
							}
							else
								cout<<"Invalid choice !\n";
							break;
						}
			case 6:{
							int ch1;
							cout<<" 1) Get Lab list Size\n 2) Get Lecture halls list size\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1)
								cout<<" Size is : "<<labPriorQ.size()<<endl;
							else if(ch1 == 2)
								cout<<" Size is : "<<lecPriorQ.size()<<endl;
							else
								cout<<"Invalid choice !\n";	
						break;
						}
			case 7:{
							int ch1;
							cout<<" 1) Last added Lab\n 2) Last added Lecture hall\nEnter your choice : ";
							cin>>ch1;
							if(ch1 == 1){
								cout<<"\nLast lab details :\n";
								(*labPriorQ.getLastElmntLoc()).print();
							}
							else if(ch1 == 2){
								cout<<"\nLast lecture hall :\n";
								(*lecPriorQ.getLastElmntLoc()).print();
							}
							else
								cout<<"Invalid choice !\n";
							break;
						}
			case 8:{
						int ch1;
						cout<<" 1) Print lab list \n 2) Print lecture hall list\nEnter your choice : ";
						cin>>ch1;
						cout<<endl;
						if(ch1==1)
							printLabInOrder(labPriorQ);
						else if(ch1==2){
							printLecInOrder(lecPriorQ);
						}						
						else
								cout<<"Invalid choice !\n";	
						break;
						}
			default: cout<<" Invalid choice!\n";
						break;
		}
	cout<<"\nShow menu again ? (y/n)  :  ";
	cin>>c;
	}while(c=='y' || c=='Y');
	return 0;
}


