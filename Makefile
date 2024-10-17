remp: main.o FIFO.o LRU.o LFU.o Second_Chance.o
	gcc -o remp main.o FIFO.o LRU.o LFU.o Second_Chance.o
	
Remplacents.o: main.c Memoire.h
	gcc -c main.c
	
FIFO.o: FIFO.c Memoire.h
	gcc -c FIFO.c
	
LRU.o: LRU.c 
	gcc -c LRU.c
	
LFU.o: LFU.c 
	gcc -c LFU.c
	
second.o: second.c 
	gcc -c Second_Chance.c
	



clean:
	rm -f main.o FIFO.o LRU.o LFU.o Second_Chance.o
	rm -f remp
	
