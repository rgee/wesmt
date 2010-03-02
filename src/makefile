oglapp: oglapp.o vector2D.o
	g++ -o oglapp.exe oglapp.o vector2D.o -lGL -lGLU -lSDL


oglapp.o: oglapp.cpp 
	g++ -c oglapp.cpp 
	
vector2D.o: vector2D.cpp vector2D.h
	g++ -c vector2D.cpp
 
clean:
	rm -f *.o oglapp.exe
