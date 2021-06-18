copycontent: main.o
	gcc -o copycontent main.c

.PHONY: clean

clean:
	-rm *.o copycontent