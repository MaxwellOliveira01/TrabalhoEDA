main: main.o metodosOrdenacao.o geraNumeros.o contaDuracao.o
	g++ -std=c++17 -Wall -Wshadow -fsanitize=address -O2 -o main metodosOrdenacao.o main.o geraNumeros.o contaDuracao.o

main.o: main.cpp
	g++ -c main.cpp

geraNumeros.o: sources/geraNumeros.cpp
	g++ -c sources/geraNumeros.cpp

metodosOrdenacao.o: sources/metodosOrdenacao.cpp
	g++ -c sources/metodosOrdenacao.cpp

contaDuracao.o: sources/contaDuracao.cpp
	g++ -c sources/contaDuracao.cpp

clean:
	rm main.o geraNumeros.o metodosOrdenacao.o contaDuracao.o