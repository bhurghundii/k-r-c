output: main.o getline.o strindex.o
	gcc main.o getline.o strindex.o -o output

main.o: main.o
	gcc -c main.c

getline.o: getline.o
	gcc -c getline.c

strindex.o: strindex.o
	gcc -c strindex.c

clean: 
	rm *.o output
# target: dependencies 
# 	action