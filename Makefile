FLAGS = -Wall -Werror -g -std=c++14
FILE1 = program1
FILE2 = List
FILE3 = Planet
FILE4 = Vector
FILE5 = Star

all: $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o
	g++ $(FLAGS) $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o -o $(FILE1)

$(FILE1).o: $(FILE1).cpp
	g++ -c $(FLAGS) $(FILE1).cpp -o $(FILE1).o

$(FILE2).o: $(FILE2).cpp
	g++ -c $(FLAGS) $(FILE2).cpp -o $(FILE2).o

$(FILE3).o: $(FILE3).cpp
	g++ -c $(FLAGS) $(FILE3).cpp -o $(FILE3).o

$(FILE4).o: $(FILE4).cpp
	g++ -c $(FLAGS) $(FILE4).cpp -o $(FILE4).o

$(FILE5).o: $(FILE5).cpp
	g++ -c $(FLAGS) $(FILE5).cpp -o $(FILE5).o

run: all
	./$(FILE1)

memcheck: all
	valgrind ./$(FILE1)

clean:
	rm -rf *.o $(FILE1)
