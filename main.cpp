#include "palavras.h"

// Método pra inicializar uma lista com uma frase.
void init_lista_frase(NO **head, char *frase)
{
	NO *p = NULL;
	NO *ant = NULL;
	*head = NULL;
	
	if (strlen(frase) == 0) return;
	
	*head = (NO*) malloc(sizeof(NO));
	(*head)->prox = NULL;
	(*head)->letra = frase[0];
	
	ant = *head;
	
	int i;
	for (i = 1; i < strlen(frase); i++) {
		p = (NO*) malloc(sizeof(NO));
		p->prox = NULL;
		p->letra = frase[i];
		
		ant->prox = p;
			
		ant = p;
	}
}

void imprime_lista_frase(NO *head)
{
	NO *p = head;
	
	printf("\n");
	
	while (p) {
		printf("%c", p->letra);
		p = p->prox;
	}
	
	printf("\n");
}

int main() 
{

    // inclua aqui o codigo necessario para testar o seu programa,
    // mas lembre-se que apenas o que esta em trabalho.cpp sera
    // avaliado. Cuidado para nao deixar nenhum codigo essencial
    // ao funcionamento do seu EP nesta area!!!
    
    printf("Aluno 1: %s, Nro. USP: %s\nAluno 2: %s, Nro. USP: %s\n\n", aluno1(), nrousp1(), aluno2(), nrousp2());
    
    NO *lista;
    init_lista_frase(&lista, "ESTRUTURAS DE DADOS E MUITO LEGAL.");
    
    imprime_lista_frase(lista);
}
