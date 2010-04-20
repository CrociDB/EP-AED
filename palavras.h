#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// elemento da lista
typedef struct estr
{
        char letra;
        estr *prox;
} NO;

// funcoes a implementar em trabalho.cpp
void excluirPalavra(NO *frase, NO *palavra);
NO *codificar (NO *frase);
char *aluno1();
char *aluno2();
char *nrousp1();
char *nrousp2();
char *turma();
