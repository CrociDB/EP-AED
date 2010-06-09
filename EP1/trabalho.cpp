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


int numNaoVogal(NO *no)
{
	NO *p = no;
	int num = 0;
	
	while (p)
	{
		if (p->letra == 'a' || p->letra == 'e' || p->letra == 'i' || p->letra == 'o' || p->letra == 'u' || 
			p->letra == 'A' || p->letra == 'E' || p->letra == 'I' || p->letra == 'O' || p->letra == 'U' || p->letra == '\r')
		{
			break;
		}
		p = p->prox;
		num++;
	}
	
	return num;
}


NO *copiar(NO* no){
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->letra = no->letra;
	if(!no->prox){
		novo->letra = no->letra;
	}
	else{
		novo->prox = copiar(no->prox);
	}
	return novo;
}

NO *adicionaNoCabeca(NO *lista) {

	int num = numNaoVogal(lista);

	if (num > 1)
	{	
		NO *head = (NO*) malloc(sizeof(NO));	
		head->letra = '\r';
		head->prox = lista;
		
		return head;
	}
	
	return lista;
	
}

NO *removeNoCabeca(NO *lista) {

	if (lista->letra == '\r')
	{	
		NO *p = lista;
		lista = lista->prox;
		
		free(p);
	}
	
	return lista;
	
}

void inverterTudo(NO **lista)
{
	NO *atual = (*lista)->prox;
	NO *ant = *lista;
	
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
	
	NO *prox = atual->prox;
	
	int i = 0;
	
	//printf("--Num: %d\n", num);
	//print_test(*p_inicio, num+1);
	
	while (i < num-1)
	{
		atual->prox = ant;
		
		ant = atual;
		atual = prox;
	
		if (prox)
		{
			prox = prox->prox;
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


void inverterNaoVogal(NO *lista)
{
	NO *p = lista;
	NO *ant = NULL;
	
	while (p)
	{
		int num = numNaoVogal(p);
		//printf("Out: %d\n", num);
		
		if (num > 1)
		{
			inverteLista(&p, &ant, num);
		}
		
		ant = p;
		p = p->prox;
	}
}

// somente para turma 94
NO *codificar (NO *frase){
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
	
    //Copia do NO frase passado por parametro
    NO* copia = copiar(frase);
    
    // Gambiarra =D
    copia = adicionaNoCabeca(copia);

    //1ª etapa:
    inverterNaoVogal(copia);
    
    // Gambiarra (parte II) =D
    copia = removeNoCabeca(copia);

    //2ª etapa:
    inverterTudo(&copia);
	
	return copia;
}


