all: trabalho

trabalho: trabalho1.o estoque.o leitura.o
	gcc -Wall -o trabalho build/trabalho1.o build/estoque.o build/leitura.o

trabalho1.o: trabalho1.c
	gcc -c -Wall trabalho1.c
	mkdir -p build
	mv trabalho1.o build

estoque.o: estoque.c 
	gcc -c -Wall estoque.c
	mkdir -p build
	mv estoque.o build

leitura.o: leitura.c 
	gcc -c -Wall leitura.c
	mkdir -p build
	mv leitura.o build

clean:
	rm build/*.o
	rm trabalho