output: Source.o Funkcijos.o Generavimas.o
	g++ Source.o Funkcijos.o Generavimas.o -o output

Source.o: Source.cpp
	g++ -c Source.cpp

Funkcijos.o: Funkcijos.cpp Funkcijos.h
	g++ -c Funkcijos.cpp

Generavimas.o: Generavimas.cpp Generavimas.h
	g++ -c Generavimas.cpp

clean:
	rm *.o output