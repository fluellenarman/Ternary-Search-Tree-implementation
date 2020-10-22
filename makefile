project1.out: main.o TST.o
	g++ main.o TST.o -o project1.out

main.o: main.cpp TST.h
	g++ -c main.cpp

TST.o: TST.cpp TST.h
	g++ -c TST.cpp

clean:
	rm *.o project1.out

#target: dependencies
#	action