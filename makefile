all: rand.o
	gcc -o rand rand.c
rand.o: rand.c
	gcc -c rand.c
run: all
	./rand
