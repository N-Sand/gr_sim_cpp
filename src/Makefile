.DEFAULT_GOAL:=runner

# libraries are: opengl and Eigen library
LIBS = -lGL -lglut -lGLU -lGLEW 
CFLAGS = -c # this makes it compile only, not link (use on all subfiles)
# making a variable for -I flag to include Eigen headers /usr/include/eigen3
INCLUDE = -I/usr/include/eigen3 -I/usr/include/stb
run:
	./launcher

compile_all: main.o functions.o image.o ray.o
	g++ $(INCLUDE) -std=c++17 -o launcher main.o functions.o image.o ray.o $(LIBS)

main.o: main.cpp
	g++ $(INCLUDE) -std=c++17 $(CFLAGS) main.cpp

functions.o: utility/functions.cpp
	g++ $(INCLUDE) -std=c++17 $(CFLAGS) utility/functions.cpp

image.o: objects/image.cpp
	g++ $(INCLUDE) -std=c++17 $(CFLAGS) objects/image.cpp

ray.o: objects/ray.cpp
	g++ $(INCLUDE) -std=c++17 $(CFLAGS) objects/ray.cpp

clean:
	rm -rf .vscode/
	rm -f *.o
	rm -f launcher

runner: compile_all run clean
	@echo "Finished"
