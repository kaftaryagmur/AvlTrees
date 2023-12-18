All: compile run 

compile: 
	g++ -I ./include/ -o ./lib/AvlNode.o -c ./src/AvlNode.cpp
	g++ -I ./include/ -o ./lib/Avl.o -c ./src/Avl.cpp
	g++ -I ./include/ -o ./lib/RootArray.o -c ./src/RootArray.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./lib/StackArray.o -c ./src/StackArray.cpp

	g++ -I ./include/ -o ./bin/Test ./lib/AvlNode.o ./lib/Avl.o ./lib/RootArray.o ./lib/Stack.o ./lib/StackNode.o ./lib/StackArray.o ./src/Test.cpp
	
run:
	./bin/Test
