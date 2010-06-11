#include "arvore.h"
#include <stdio.h>
#include <time.h>

NO* criarNovoNo(int ch);
bool inserirAux(NO *raiz, int ch);
void criar_abb(NO **raiz, int num);

void ident(NO *p, int h);

void exibe_abb_em_ordem(NO *raiz);

int main() 
{
	NO *raiz = NULL; 

	criar_abb(&raiz, 15);

	ident(raiz, 0);

}

NO* criarNovoNo(int ch){
   NO *novoNo = (NO*)malloc(sizeof(NO));
   novoNo->esq = NULL;
   novoNo->dir = NULL;
   novoNo->chave = ch;
   return novoNo;
}

/* funcao auxiliar (recursiva) para insercao */
bool inserirAux(NO *raiz, int ch){
  if (raiz->chave > ch) {
    if (raiz->esq == NULL) {
      raiz->esq = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->esq, ch);
  }else{
    if (raiz->dir == NULL) {
      raiz->dir = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->dir, ch);
  }
}

void criar_abb(NO **raiz, int num)
{
	srand(time(NULL));

	(*raiz) = criarNovoNo(rand() % 50);

	int i;
	for (i = 0; i < num; i++)
	{
		inserirAux(*raiz, rand() % 50);
	}
}

void exibe_abb_em_ordem(NO *raiz){
  if (raiz == NULL) return;
  exibe_abb_em_ordem(raiz->esq);
  printf("%d ",raiz->chave);
  exibe_abb_em_ordem(raiz->dir);
}

void ident(NO *p, int h)
{
	int i;
	
	if (p) {
		ident(p->dir, h + 1);
	
		for (i = 1; i <= h; i++) printf ("     ");
		printf("%d\n", p->chave);
		
		ident(p->esq, h+1);
	}
}