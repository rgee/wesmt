oglapp: GameApp.o Vector2D.o Particle.o Mass.o GameplayState.o GameApp.o StateManager.o AABB.o
	g++ -Wall -g -o oglapp.exe AABB.o StateManager.o Mass.o GameplayState.o GameApp.o Vector2D.o Particle.o `sdl-config --static-libs --libs`

AABB.o: AABB.cpp AABB.h
	g++ -Wall -c AABB.cpp

Mass.o: Mass.cpp Mass.h
	g++ -Wall -c Mass.cpp

GameApp.o: GameApp.cpp GameApp.h
	g++ -Wall -c GameApp.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -Wall -c Vector2D.cpp

Particle.o: Particle.cpp Particle.h
	g++ -Wall -c Particle.cpp
	
StateManager.o: StateManager.cpp StateManager.h
	g++ -Wall -c StateManager.cpp

GameplayState.o: GameplayState.cpp GameplayState.h IGameState.h
	g++ -Wall -c GameplayState.cpp
 
clean:
	rm -f *.o oglapp.exe
