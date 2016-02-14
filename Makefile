objs = main.o RSA.o functions.o

Program: $(objs)
	g++ -o RSA.out $(objs)

main.o: RSA.h main.cpp
	g++ -c main.cpp

RSA.o: functions.h RSA.h RSA.cpp
	g++ -c RSA.cpp

functions.o: functions.h functions.cpp
	g++ -c functions.cpp


clean:
	rm $(objs)