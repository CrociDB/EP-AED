#include "arvore.h"

// crie neste arquivo as funcoes solicitadas e todas as demais rotinas necessarias para sua execucao
// tendo em mente que apenas o que esta implementado neste arquivo sera testado para fins de avaliacao
// do seu trabalho. Nao modifique as assinaturas destas funcoes, nem o conteudo de arvore.h, ou seu
// programa nao passara nos testes.

char *aluno1() {
	return ("Filipe Marques Pereira");  // escreva aqui o seu nome
}

char *aluno2() {
	return ("Bruno Croci de Oliveira");  // escreva aqui o seu nome
}

char *nrousp1() {
	return ("6777105"); // escreva aqui o seu nro USP
}

char *nrousp2() {
	return ("6907392"); // escreva aqui o seu nro USP
}

char *turma() {
	return ("94"); // escreva aqui o nro da sua turma com 2 digitos
}

// somente para turma 04
bool excluirAncestrais(NO **raiz, int chave)
{
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
}

int maior_esquerda(NO** p, NO** pai){
	while((*p)->dir){
		pai = p;
		*p = (*p)->dir;
	}
	return (*p)->chave;
}

void um_filho(NO* atual, NO* pai){
	if (pai->esq == NULL && pai->dir == NULL) printf("i remove it\n");
	else if(pai->esq == atual){
		if(atual->esq) pai->esq = atual->esq;
		else pai->esq = atual->dir;	
	} 
	else{
		if(atual->esq) pai->dir = atual->esq;
		else pai->dir = atual->dir;	
	}
	free(atual);
	printf("done\n");
}
void sem_filho(NO* atual, NO* pai){
	if (pai->esq == NULL && pai->dir == NULL){
		printf("freedom\n");
	}
	else if(pai->esq == atual) pai->esq = NULL;
	else if(pai->dir == atual) pai->dir = NULL;
	free(atual);
}

void dois_filhos(NO* atual){
	int chave = -1;
	NO* p = atual->esq;
	NO* p2 = atual;
	chave = maior_esquerda(&p, &p2);
	atual->chave = chave;
	if(p->esq || p->dir){
		um_filho(p, p2);
	}
	else sem_filho(p, p2);
}

bool percorre_abb(NO* atual, NO* pai, int contador_de_nivel, int nivel_desejado){
	//cheguei no nivel	
	if(contador_de_nivel == nivel_desejado){
		if(!atual) return false;		
		//se o nivel existir faca uma das tres
		else if(atual->esq && atual->dir){
			dois_filhos(atual);	
		}
		else if(atual->esq || atual->dir){
			um_filho(atual, pai);		
		}
		else sem_filho(atual, pai);
		return true;	
	}
	else{	
		bool esq = false, dir = false;
		contador_de_nivel++;
		if(atual->esq){
			esq = percorre_abb(atual->esq, atual, contador_de_nivel, nivel_desejado);	
		}
		if(atual->dir){
			dir = percorre_abb(atual->dir, atual, contador_de_nivel, nivel_desejado);		
		}
		
		return esq || dir;
	}
}

// somente para turma 94
bool excluirNivel(NO **raiz, int n)
{	
	NO* pai_raiz = (NO*) malloc(sizeof(NO));
	pai_raiz->esq = NULL;
	pai_raiz->dir = NULL;
	pai_raiz->chave = -1;
	return percorre_abb(*raiz, pai_raiz, 1, n);
}
