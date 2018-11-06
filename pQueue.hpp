#ifndef PQUEUE_H
#define PQUEUE_H
#include<iostream>
#include<vector>
using namespace std;


template <typename E, typename C>
class pQueue {
	private:
		vector<E>heapVec;
		int noOfElement;
	public:
		pQueue();
		pQueue(vector<E>);
		
		
		void removeMin();	
		int size() const;
		bool empty() const;
		E& min();

		class locator{
			private:
				int i;
				E e;
				pQueue *pQ;
			public:
				locator(){
					this->i=0;
				}
				locator(pQueue<E,C> *pQ){
					this->pQ = pQ;
				}
				locator(int i, E e){
					this->i = i;
					this->e = e;
				}
				void setIndex(int i){
					this->i=i;
				}
				int getIndex(){
					return this->i;
				}
				void setElement(E e){
					this->e = e;
				}
				E getElement(){
					return this->e;
				}
				E operator*(){
				 return this->e;
				}
				void operator=(locator l){
					this->i=l.getIndex();
					this->e=l.getElement();
				}
				void operator++(){
						(this->i)++;
					(this->e) = (pQ->heapVec[this->i]);
				}
				bool operator !=(locator l){
						return (this->i != l.getIndex());
				}
				bool operator ==(locator l){
						return (this->i == l.getIndex());
				}
		}lastElmnt;

		locator begin(){
			locator loc;
			loc.setIndex(1);
			loc.setElement(heapVec[1]);
			return loc;
		}

		locator end(){
			locator loc;
			loc.setIndex(noOfElement);
			loc.setElement(heapVec[noOfElement]);
			return loc;
		}
		
		locator getLastElmntLoc(){
			return this->lastElmnt;
		}
		
		locator upHeapBubbling(int i){
			E t;
			C c;
			while( i>1 && c(heapVec[i/2],heapVec[i])){
				t = heapVec[i/2];
				heapVec[i/2] = heapVec[i];
				heapVec[i] = t;
				i/=2;
			}
			locator loc;
			loc.setIndex(i);
			loc.setElement(heapVec[i]);
			return loc;
		}
		
		locator downHeapBubbling(int i){
			if (i==0){
				locator loc;
			loc.setIndex(1);
			loc.setElement(heapVec[1]);
			return loc;
			}
			E t;
			C c;
			while(i<(noOfElement/2) &&(((2*i <= noOfElement) && c(heapVec[i],heapVec[2*i])) || (((2*i+1) <= noOfElement) && c(heapVec[i],heapVec[2*i+1]))))
				{
				if(c(heapVec[2*i],heapVec[2*i+1])){
				t = heapVec[i];
				heapVec[i] = heapVec[2*i+1];
				heapVec[2*i+1] = t;
				i=i*2+1;
				}
				else{
					t = heapVec[i];
					heapVec[i] = heapVec[2*i];
					heapVec[2*i] = t;
					i*=2;
				}
			}
			locator loc;
			loc.setIndex(i);
			loc.setElement(heapVec[i]);
			return loc;
	}
		
		locator insert(const E& e){
			this->noOfElement++;
			heapVec.push_back(e);
			this->lastElmnt = upHeapBubbling(noOfElement);
			return lastElmnt;
		}

		locator replace(locator& l, E& e){
			int i = l.getIndex();
			heapVec[i]=e;
			locator loc;
			if(i==1)
				loc=downHeapBubbling(1);
			else if(i==noOfElement)
				loc=upHeapBubbling(noOfElement);
			else{
				C c;
				if(c(heapVec[i/2],heapVec[i]))
					loc=upHeapBubbling(i);
				else
					loc=downHeapBubbling(i);
			}
			(this->lastElmnt)=loc;
			return loc;		
		}

		void remove(locator& l){
			int i = l.getIndex();
			E t = heapVec[i];
			heapVec[i]=heapVec[noOfElement];
			heapVec[noOfElement]=t;
			heapVec.pop_back();
			locator temp;
			this->lastElmnt= downHeapBubbling(i);
			(this->lastElmnt).setIndex(1);
			(this->lastElmnt).setElement(heapVec[1]);
			this->noOfElement--;
		}
};

template <typename E, typename C>
pQueue<E,C>::pQueue(){
	this->noOfElement=0;
}

template <typename E, typename C>
pQueue<E,C>::pQueue(vector<E> vec){
	this->noOfElement=vec.size();
	E e;
	locator temp;
	heapVec.clear();
	heapVec.push_back(e);
	for(int i=0; i<this->noOfElement; i++)
		this->heapVec.push_back(vec[i]);
	this->lastElmnt.setIndex(noOfElement);
	this->lastElmnt.setElement(heapVec[noOfElement]);
	for(int i=(this->noOfElement/2);i>0;i--){
		temp=downHeapBubbling(i);
	}
}

template <typename E, typename C>
int pQueue<E,C>::size() const{
	return this->noOfElement;
}

template <typename E, typename C>
bool pQueue<E,C>::empty() const{
	return this->noOfElement==0;
}

template <typename E, typename C>
E& pQueue<E,C>::min() {
	return (heapVec[1]);
}

template <typename E, typename C>
void pQueue<E,C>::removeMin(){
	E t = heapVec[1];
	heapVec[1]=heapVec[noOfElement];
	heapVec[noOfElement]=t;
	heapVec.pop_back();
	locator temp = downHeapBubbling(1);
	this->noOfElement--;
}


#endif
