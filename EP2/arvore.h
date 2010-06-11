#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// no da arvore
typedef struct estr
{
        int chave;
        estr *prox;
} NO;

// funcoes a implementar em trabalho.cpp
bool excluirAncestrais(NO **raiz, int chave);
bool excluirNivel(NO **raiz, int n);
char *aluno1();
char *aluno2();
char *nrousp1();
char *nrousp2();
char *turma();
