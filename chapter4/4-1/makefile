output: main.o getline.o strrindex.o
	gcc main.o getline.o strrindex.o -o output

main.o: main.o
	gcc -c main.c

getline.o: getline.o
	gcc -c getline.c

strrindex.o: strrindex.o
	gcc -c strrindex.c

run:
	./output

go: output run
	
clean: 
	rm *.o output
# target: dependencies 
# 	action