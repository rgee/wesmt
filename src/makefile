oglapp: GameApp.o Vector2D.o Particle.o Well.o Mass.o Well.o GameplayState.o GameApp.o StateManager.o AABB.o ../libs/GLee.o TextFileUtil.o
	g++ -Wall -g -o oglapp.exe AABB.o StateManager.o Mass.o Well.o ../libs/GLee.o GameplayState.o GameApp.o TextFileUtil.o Vector2D.o Particle.o `sdl-config --static-libs --libs` /usr/local/lib/libfmodex.dylib
 
AABB.o: AABB.cpp AABB.h
	g++ -Wall -c AABB.cpp
 
Mass.o: Mass.cpp Mass.h
	g++ -Wall -c Mass.cpp
 
GLee.o: ../libs/GLee.c ../libs/GLee.h
	g++ -Wall -c ../libs/GLee.c

GameApp.o: GameApp.cpp GameApp.h
	g++ -Wall -c GameApp.cpp
 
Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -Wall -c Vector2D.cpp
 
Particle.o: Particle.cpp Particle.h
	g++ -Wall -c Particle.cpp

Well.o: Well.cpp Well.h
	g++ -Wall -c Well.cpp
 
StateManager.o: StateManager.cpp StateManager.h
	g++ -Wall -c StateManager.cpp

TextFileUtil.o: TextFileUtil.cpp TextFileUtil.h
	g++ -Wall -c TextFileUtil.cpp 

GameplayState.o: GameplayState.cpp GameplayState.h IGameState.h
	g++ -Wall -c GameplayState.cpp
 
clean:
	rm -f *.o oglapp.exe