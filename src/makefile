oglapp: oglapp.o vector2.o
	g++ -o oglapp.exe oglapp.o vector2.o -lGL -lGLU -lSDL


oglapp.o: oglapp.cpp 
	g++ -c oglapp.cpp 
	
vector2.o: vector2.cpp vector2.h
	g++ -c vector2.cpp
 
clean:
	rm -f *.o oglapp.exe
