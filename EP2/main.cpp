#include "arvore.h"
#include <stdio.h>
#include <time.h>

NO* criarNovoNo(int ch);
bool inserirAux(NO *raiz, int ch);
void criar_abb_aleatorio(NO **raiz, int num);
void criar_abb(NO **raiz, int num);

void ident(NO *p, int h);

void exibe_abb_em_ordem(NO *raiz);

int main() {
	char resp = 'h';
	int num = 0;
	
	printf("Se desejar arvore aleatoria digite 'a'\nCaso contrário digite outra letra\n");
	scanf("%c",&resp);
	
	NO *raiz = NULL; 
	if(resp == 'a'){
		printf("Qual o numero de NOs desejados, além da raiz?\n");
		scanf("%i",&num);
		
		criar_abb_aleatorio(&raiz, num);
		
		printf("Árvore ANTES da exclusao:\n\n");
		ident(raiz, 0);
		
		printf("Qual nivel deve ser excluído?\n");
		scanf("%i",&num);
		excluirNivel(&raiz, num);

		printf("Árvore APOS da exclusao:\n\n");
		ident(raiz, 0);
	}
	else{
		printf("Use -1 para raiz sem filhos, 0  para raiz com um filho,\n1 para raiz com dois filhos, qualquer outro numero irá gerar arvore geral\nQue contém todos os casos\n");
		scanf("%i",&num);
		criar_abb(&raiz, num);

		printf("Árvore ANTES da exclusao:\n\n");
		ident(raiz, 0);

		printf("Qual nivel deve ser excluído?\n");
		scanf("%i",&num);
		excluirNivel(&raiz, num);

		printf("Árvore APOS da exclusao:\n\n");
		ident(raiz, 0);
		
	}
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
	//teste para arvore com um nivel
	if(num == -1){
		(*raiz) == criarNovoNo(5);
	}
	//teste para arvore com dois niveis, raiz e um filho
	else if(num == 0){
		(*raiz) = criarNovoNo(5);
		inserirAux(*raiz, 1);
	}	
	//teste para arvore com dois niveis, raiz e dois filhos
	else if(num == 1){
		(*raiz) = criarNovoNo(5);
		inserirAux(*raiz, 1);
		inserirAux(*raiz, 8);
	}
	//teste para arvore geral
	else {
		(*raiz) = criarNovoNo(5);

		inserirAux(*raiz, 1);
		inserirAux(*raiz, 3);
		inserirAux(*raiz, 6);
		inserirAux(*raiz, 7);
		inserirAux(*raiz, 2);
		inserirAux(*raiz, 4);
		
	}
}

void criar_abb_aleatorio(NO **raiz, int num)
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
