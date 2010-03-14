oglapp: GameApp.o Vector2D.o Particle.o
	g++ -Wall -g -o oglapp.exe GameApp.o Vector2D.o Particle.o `sdl-config --static-libs --libs`

GameApp.o: GameApp.cpp GameApp.h
	g++ -Wall -c GameApp.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -Wall -c Vector2D.cpp
	
Particle.o: Particle.cpp Particle.h
	g++ -Wall -c Particle.cpp
 
clean:
	rm -f *.o oglapp.exe
