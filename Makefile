all: code

code: main.o Lab.o Lec.o functions.o
	g++ main.o Lab.o Lec.o functions.o -o code

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

Lab.o: Lab.cpp
	g++ -std=c++14 -c Lab.cpp

Lec.o: Lec.cpp
	g++ -std=c++14 -c Lec.cpp

functions.o: functions.cpp
	g++ -std=c++14 -c functions.cpp

clean:
	rm -f *o code

run: code
		./code
