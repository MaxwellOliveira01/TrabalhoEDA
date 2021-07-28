main: main.o metodosOrdenacao.o geraNumeros.o contaDuracao.o
	g++ -std=c++17 -Wall -Wshadow -fsanitize=address -O2 -o main metodosOrdenacao.o main.o geraNumeros.o contaDuracao.o

main.o: main.cpp
	g++ -c main.cpp

geraNumeros.o: geraNumeros.cpp
	g++ -c geraNumeros.cpp

metodosOrdenacao.o: metodosOrdenacao.cpp
	g++ -c metodosOrdenacao.cpp

contaDuracao.o: contaDuracao.cpp
	g++ -c contaDuracao.cpp

clean:
	rm main.o geraNumeros.o metodosOrdenacao.o contaDuracao.o