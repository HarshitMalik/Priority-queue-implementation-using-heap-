#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<vector>
#include "pQueue.hpp"
#include "Lab.h"
#include "Lec.h"

void readLabData(vector<Lab>&);
void readLecData(vector<Lec>&);
void addLecManually(pQueue<Lec,CompareLec>& pQ);
void addLabManually(pQueue<Lab,CompareLab>& pQ);
void printLabInOrder(pQueue<Lab,CompareLab> pQ);
void printLecInOrder(pQueue<Lec,CompareLec> pQ);
Lab addLab(string, float, int, int, int, int);
Lec addLec(string, float, int, int, int, int);

#endif
