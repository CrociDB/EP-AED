#include "palavras.h"

// crie neste arquivo as funcoes solicitadas e todas as demais rotinas necessarias para sua execucao
// tendo em mente que apenas o que esta implementado neste arquivo sera testado para fins de avaliacao
// do seu trabalho. Nao modifique as assinaturas destas funcoes, nem o conteudo de palavras.h, ou seu
// programa nao passara nos testes.

char *aluno1() {
	return ("Filipe Marques Pereira");  // escreva aqui o seu nome
}

char *aluno2() {
	return ("XXXXXXXXXXXX");  // escreva aqui o seu nome
}

char *nrousp1() {
	return ("6777105"); // escreva aqui o seu nro USP
}

char *nrousp2() {
	return ("XXXXXXX"); // escreva aqui o seu nro USP
}

char *turma() {
	return ("94"); // escreva aqui o nro da sua turma com 2 digitos
}

// somente para turma 04
void excluirPalavra(NO *frase, NO *palavra)
{
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
}

// somente para turma 94
NO *codificar (NO *frase){
     // implemente aqui a funcao solicitada ou deixe como esta (sem apagar)
	NO* a = copiar(frase); //Copia do NO frase passado por parametro
}

NO* copiar(NO* no){
	if(!no->prox){
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->chave = no->chave;
		novo->prox = no->prox;
		return novo;
	}
	else{
		NO* novo = (NO*) malloc(sizeof(NO));
		novo->chave = no->chave;
		novo->prox = copiar(no->prox);
		return novo;
	}
	return NULL;
}
