main: main.o metodosOrdenacao.o geraNumeros.o contaDuracao.o moduloDeTestes.o moduloDeAprendizagem.o
	g++ -std=c++17 -Wall -Wshadow -fsanitize=address -O2 -o main metodosOrdenacao.o main.o geraNumeros.o contaDuracao.o moduloDeTestes.o moduloDeAprendizagem.o

main.o: main.cpp
	g++ -c main.cpp

geraNumeros.o: sources/geraNumeros.cpp
	g++ -c sources/geraNumeros.cpp

metodosOrdenacao.o: sources/metodosOrdenacao.cpp
	g++ -c sources/metodosOrdenacao.cpp

contaDuracao.o: sources/contaDuracao.cpp
	g++ -c sources/contaDuracao.cpp

moduloDeTestes.o: sources/moduloDeTestes.cpp
	g++ -c sources/moduloDeTestes.cpp

moduloDeAprendizagem.o: sources/moduloDeAprendizagem.cpp
	g++ -c sources/moduloDeAprendizagem.cpp

clean:
	rm main.o geraNumeros.o metodosOrdenacao.o contaDuracao.o moduloDeTestes.o moduloDeAprendizagem.o