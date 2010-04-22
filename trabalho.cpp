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

//Inverte toda a lista ligada de NOs
//a partir do NO no (primeiro no)
NO *inverterTudo(NO* no){
    int pos = 1;
    NO* ant = no->prox;
    NO* atual = no;
    NO* p;
    while(atual){
        if(pos == 1){
            NO* novo = (NO*) malloc(sizeof(NO));
            novo->letra = atual->letra;
            novo->prox = NULL;
            if(ant == NULL) return novo;
            else{
                pos++;
                atual = ant;
                ant = atual->prox;
                p = novo;
            }
        }
        else{
            NO* novo = (NO*) malloc(sizeof(NO));
            novo->letra = atual->letra;
            novo->prox = p;
            if(ant == NULL) return novo;
            else{
                atual = ant;
                ant = atual->prox;
                p = novo;
            }
        }
    }
	return p;
}

//Ligar o NO inicio que foi passado como para
//metro com o NO p (retorno da função) e passar um
//ponteiro por referencia para obter o elemento
//que se ligará ao NO fim 
NO* inverteEntreDoisNOs(NO *inicio, NO *fim){
    NO *atual = inicio->prox;
    NO *ant = atual->prox;

    //Para o NO inicio->prox
    NO *first = (NO*) malloc(sizeof(NO));
    first->letra = atual->letra;
    first->prox = NULL;
    NO *p = first;
	atual = ant;
	ant = atual->prox;

    //Para os NOs entre NO inicio e NO fim
    while(atual != fim){
        NO *novo = (NO*) malloc(sizeof(NO));
        novo->letra = atual->letra;
        novo->prox = p;
        p = novo;
        atual = ant;
        ant = atual->prox;
    }
    return p;
}

//Destroi a lista ligada de NOs
void destruir(NO *no){
	NO* atual = no;
    NO* prox;
    while (atual) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

// somente para turma 94
NO *codificar (NO *frase){
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
	
    //Copia do NO frase passado por parametro
    NO* copia = copiar(frase);

    //1ª etapa:

    //2ª etapa: pronta!
    inverterTudo(copia);

    //Libera memoria deletando o NO copia =)
	destruir(copia);
}


