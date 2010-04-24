#include "palavras.h"

// crie neste arquivo as funcoes solicitadas e todas as demais rotinas necessarias para sua execucao
// tendo em mente que apenas o que esta implementado neste arquivo sera testado para fins de avaliacao
// do seu trabalho. Nao modifique as assinaturas destas funcoes, nem o conteudo de palavras.h, ou seu
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
void excluirPalavra(NO *frase, NO *palavra)
{
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
}

NO *copiar(NO* no){
	if(!no->prox){
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = no->letra;
		novo->letra = no->letra;
		return novo;
	}
	else{
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->letra = no->letra;
		novo->prox = copiar(no->prox);
		return novo;
	}
	return NULL;
}

void inverterTudo(NO **lista)
{
	NO *atual = (*lista)->prox;
	NO *ant = (*lista);

	NO *prox = NULL;
	
	if (atual)
		prox = atual->prox;
		
	while (atual)
	{
		atual->prox = ant;
		
		ant = atual;
		atual = prox;
	
		if (prox)
		{
			prox = prox->prox;
		}
	}
	
	(*lista)->prox = NULL;
	*lista = ant;
}

void inverteLista(NO **p_inicio, NO **p_ant, int num)
{
	NO *atual = (*p_inicio)->prox;
	NO *ant = *p_inicio;
	
	NO *next = atual->prox;
	
	int i = 0;
	
	//printf("--Num: %d\n", num);
	//print_test(*p_inicio, num+1);
	
	while (i < num-1)
	{
		atual->prox = ant;
		
		ant = atual;
		atual = next;
	
		if (next)
		{
			next = next->prox;
		}
		
		i++;
	}
	
	if ((*p_ant))
	{
		(*p_ant)->prox = ant;
	}
	
	(*p_inicio)->prox = atual;
	
	//print_test(*p_inicio, num+1);
}

bool ehVogal(NO *no){
	if (no->letra == 'a' || no->letra == 'e' || no->letra == 'i' || no->letra == 'o' || no->letra == 'u' || 
		no->letra == 'A' || no->letra == 'E' || no->letra == 'I' || no->letra == 'O' || no->letra == 'U'){
		return true;
	}
	return false;
}

int numNaoVogal(NO *no)
{
	NO *p = no;
	int num = 0;
	
	while (p)
	{
		if (ehVogal(p)) break;
		p = p->prox;
		num++;
	}
	
	return num;
}


void inverterNaoVogal(NO *lista)
{
	NO *p = lista->prox;
	NO *anterior = lista;
	//NO *p = lista;
	//NO *anterior = NULL;
	
	while (p)
	{
		int num = numNaoVogal(p);
		//printf("Out: %d\n", num);
		
		if (num > 1)
		{
			inverteLista(&p, &anterior, num);
		}
		
		anterior = p;
		p = p->prox;
	}
}

void gambiarra(NO **no){
	NO *vogal = (*no);
	NO *first = (*no);
	NO *ant = NULL;
	while(!ehVogal(vogal)){
		ant = vogal;
		vogal = vogal->prox;
	}
	ant->prox = first;
	first->prox = vogal;
}

// somente para turma 94
NO *codificar (NO *frase){
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
	
    //Copia do NO frase passado por parametro
    NO* copia = copiar(frase);

    //1ª etapa:
    inverterNaoVogal(copia);
	if(!ehVogal(copia)) gambiarra(&copia);

    //2ª etapa:
    inverterTudo(&copia);

    //Libera memoria deletando o NO copia =)
	//destruir(copia);
	
	return copia;
}


