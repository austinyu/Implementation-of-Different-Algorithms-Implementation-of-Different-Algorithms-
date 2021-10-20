CC = gcc

all: kth kth-tests kth-experiments

kth: kth.o kth-core.o strutils.o 
	$(CC) -o $@ $^

kth-tests: kth-tests.o kth-core.o strutils.o 
	$(CC) -o $@ $^

kth-experiments: kth-experiments.o kth-core.o strutils.o 
	$(CC) -o $@ $^

kth.o: kth.c
	$(CC) -c $<

kth-core.o: kth-core.c kth-core.h
	$(CC) -c $<

strutils.o: strutils.c strutils.h
	$(CC) -c $<

clean: 
	rm -f *.o all