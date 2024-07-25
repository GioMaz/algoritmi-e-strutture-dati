CC=/usr/bin/g++
CFLAGS=-DEVAL -std=gnu++11 -O2 -pipe

tsp: grader.cpp tsp.cpp
	$(CC) $(CFLAGS) -o tsp tsp.cpp grader.cpp

run: tsp
	./tsp

clean:
	rm ./tsp
