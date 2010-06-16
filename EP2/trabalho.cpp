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

void __bst_research_node(NO **p, NO **aux)
{
	if (!(*p)->dir)
	{
		(*aux)->chave = (*p)->chave;
		if (!(*p)->esq)
		{
			*aux = *p;
			*p = NULL;
		}
		else {
			*aux = *p;
			*p = (*p)->esq;
		}
	}
	else
		__bst_research_node(&(*p)->dir, aux);
}


bool __bst_remove_node(NO **p)
{
	// Now I know I have to delete this NODE...
	NO *aux = *p;
	
	if (!(*p)->esq) *p = (*p)->dir;
	else if (!(*p)->dir) *p = (*p)->esq;
	else __bst_research_node(&((*p)->esq), &aux);
	
	free(aux);
	
	return true;
}

bool percorre_abb(NO** atual, int contador_de_nivel, int nivel_desejado){
	//cheguei no nivel	
	
	if(!atual) return false;
	
	if(contador_de_nivel == nivel_desejado){
		
		return __bst_remove_node(atual);
	}
	else{	
		bool esq = false, dir = false;
		contador_de_nivel++;
		if((*atual)->esq){
			esq = percorre_abb(&(*atual)->esq, contador_de_nivel, nivel_desejado);	
		}
		if((*atual)->dir){
			dir = percorre_abb(&(*atual)->dir, contador_de_nivel, nivel_desejado);		
		}
		
		return esq || dir;
	}
}

// somente para turma 94
bool excluirNivel(NO **raiz, int n)
{	
	return percorre_abb(raiz, 1, n);
}
