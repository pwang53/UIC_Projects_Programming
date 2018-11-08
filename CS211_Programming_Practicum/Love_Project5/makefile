proj5: p5.o myStack2.o myStack.o
	g++ -o proj5 p5.o myStack2.o myStack.o

p5.o: p5.cpp StackClass.h
	g++ -c p5.cpp

myStack2: myStack2 StackClass.h
	g++ -c myStack2.cpp

myStack.o: myStack.cpp StackClass.h
	g++ -c myStack.cpp

clean:
	rm p5.o myStack2.o myStack.o
