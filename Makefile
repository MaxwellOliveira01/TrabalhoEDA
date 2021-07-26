main: main.o metodosOrdenacao.o geraNumeros.o
	g++ -std=c++17 -Wall -Wshadow -fsanitize=address -o main metodosOrdenacao.o main.o geraNumeros.o

main.o: main.cpp
	g++ -c main.cpp

geraNumeros.o: geraNumeros.cpp
	g++ -c geraNumeros.cpp

metodosOrdenacao.o: metodosOrdenacao.cpp
	g++ -c metodosOrdenacao.cpp

clean:
	rm main.o geraNumeros.o metodosOrdenacao.o