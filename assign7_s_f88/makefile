#Makefile

brackets: CharStackDriver.o CharStack.o
	g++ CharStackDriver.o CharStack.o -o brackets

CharStackDriver.o: CharStackDriver.cpp CharStack.h
	g++ -c CharStackDriver.cpp

CharStack.o: CharStack.cpp CharStack.h
	g++ -c CharStack.cpp

clean:
	rm *.o

cleanclean:
	rm *.o brackets

run:
	./brackets
