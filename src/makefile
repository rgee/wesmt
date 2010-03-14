oglapp: GameApp.o Vector2D.o Particle.o
	g++ -Wall -g -o oglapp.exe GameApp.o Vector2D.o Particle.o AABB.o StateManager.o Mass.o GameplayState.o -lGL -lGLU -lSDL


GameApp.o: GameApp.cpp GameApp.h
	g++ -Wall -c GameApp.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -Wall -c Vector2D.cpp

AABB.o: AABB.cpp AABB.h
	g++ -Wall -c AABB.cpp

StateManager.o: StateManager.cpp StateManager.h
	g++ -Wall -c StateManager.cpp	

Mass.o: Mass.cpp Mass.h
	g++ -Wall -c Mass.cpp

Particle.o: Particle.cpp Particle.h
	g++ -Wall -c Particle.cpp

GameplayState.o: GameplayState.cpp GameplayState.h IGameState.h
	g++ -Wall -c GameplayState.cpp
 
clean:
	rm -f *.o oglapp.exe
