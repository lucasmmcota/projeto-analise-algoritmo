CC = gcc
CFLAGS = -g -Wall

TARGET = tp
SOURCE = tp

ALGORITMOS = algoritmo_guloso.c forca_bruta.c operacoes.c programacao_dinamica.c

all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(SOURCE) $(ALGORITMOS) $(TARGET).c

clean: 
	$(RM) $(SOURCE) saida.txt