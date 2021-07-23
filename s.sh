#isso é temporario, fazer makefile depois

g++ -c metodos.cpp
g++ -c main.cpp
g++ -std=c++17 -Wall -Wshadow -fsanitize=address -o main metodos.o main.o

rm metodos.o
rm main.o
