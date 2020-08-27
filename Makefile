# repeat_check
all: repeat_check

repeat_check: repeat_check.o
	g++ repeat_check.o -o repeat_check

repeat_check.o: repeat_check.cpp
	g++ -c repeat_check.cpp

clean:
	rm -rf *.o repeat_check
