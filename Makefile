#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: start
	./start

start: obj obj/ruchy.o obj/plansza.o

obj:
	mkdir obj

obj/ruchy.o: src/ruchy.cpp  inc/ruchy.hh 
	g++ -c ${CXXFLAGS} -o obj/ruchy.o src/ruchy.cpp

obj/plansza.o: src/plansza.cpp inc/plansza.hh
	g++ -c ${CXXFLAGS} -o obj/plansza.o src/plansza.cpp


clean:
	rm -f obj/*.o start
