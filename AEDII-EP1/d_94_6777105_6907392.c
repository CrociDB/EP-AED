#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef double tweight;

typedef struct tdisjointset{
  int qtsets;
  int *p;
  int *rank;
}tdisjointset;

typedef struct tedge {
  int v1;
  int v2;
  tweight weight;
}tedge;

typedef struct tedgearray {
  int qtedges;
  tedge *edges;
}tedgearray;


/********** 
  Funcoes referentes a conjuntos disjuntos
 **********/ 
 
void Create_DisjointSet(tdisjointset *S, int qtsets){
	S->qtsets = qtsets; // Numero de conjuntos disjuntos	
	S->p = (int) malloc(qtsets * sizeof(int)); // Variavel do representante do conjunto
	S->rank = (int) malloc(qtsets * sizeof(int)); // Variavel do peso da aresta para chegar ao No

   int i;
   for (i = 0; i < qtsets; i++) {
      S->p[i]= i; // Inicialmente cada No é seu proprio representante
      S->rank[i] = 0; // Inicialmente o peso de todas as arestas eh zero
   }

	/*
	* Como são iniciados conjuntos unitarios cada No eh o proprio representante 
	* e o peso para se chegar a tal No eh zero
	*/
}	     

int Find_Set(tdisjointset *S, int x) {
	/* Verifica se x eh representante de seu conjunto
	* Caso seja, entao apenas retorna o representante do conjunto
	* Caso contrario ele atualiza o representante do conjunto
	* utilizando como resposta o retorno de um novo Find_Set
	* que passa o mesmo conjunto e o representante atual
	* do conjunto como parametros
	*/	
	if(x != S->p[x]) S->p[x] = Find_Set(S, S->p[x]);
	return S->p[x];
}    

void Link(tdisjointset *S, int x, int y) {
	/*
	* Verifica qual entre os dois vertices (x e y)
	* tem maior peso, se for y, entao x sera
	* o novo representante do conjunto, caso contrario
	* y eh o novo representante.
	* Contudo se o peso for o mesmo,
	* entao o peso de y eh atualizado somando-se
	* um ao seu peso
	*/
	if (S->rank[x] > S->rank[y]) {
	   S->p[y] = x;
	} else {
	   S->p[x] = y;
	   if (S->rank[x] == S->rank[y]) {
	      S->rank[y] = S->rank[y] + 1;
	   }
	}
	
}

void Union(tdisjointset *S, int x, int y) {
	/*
	* Realiza um link entre o representante de X e 
	* o representante de Y do conjunto S
	*/
	Link(S,Find_Set(S, x),Find_Set(S, y));
}

// Funcao criada para auxialiar testes do algoritmo
void Print_DisjointSet(tdisjointset *S) {

   printf("Imprimindo Conjuntos Disjuntos:\n");

   int i;
   for (i = 0; i < S->qtsets; i++) {
      printf(" ~> P[%d] = %d, RANK = %d\n", i, S->p[i], S->rank[i]);
   }

} 



/********** 
  Funcoes referentes a grafos e ao algoritmo de Kruskal
 **********/ 

int Read_Edges(char* filename, tedgearray *E, int *qtvert) {
  FILE *fp;
  int qtedges;
  int v1, v2;
  tweight weight;
  int ide;
  
  fp = fopen(filename, "rt");
  if (fp==NULL)
     return(0);
  
  if (fscanf(fp, "%d %d", qtvert, &qtedges)!=2) 
    return(0);
        
  E->qtedges = qtedges;
  E->edges = calloc(qtedges, sizeof(tedge));
  
  //  printf("vertices: %d ; arestas: %d \n", *qtvert, qtedges);
  
  for (ide=0;ide<qtedges;ide++) {
    if (fscanf(fp, "%d %d %lf", &v1, &v2, &weight)!=3) {
      fclose(fp);
      free(E->edges);
      return(0);
    }

    //  printf("%d - %d - %d - %lf\n",  ide, v1, v2, weight);

    if (v1<0 || v1>=*qtvert || v2<0 || v2>=*qtvert || weight<0) {
      fclose(fp);
      free(E->edges);
      return(0);
    }
    E->edges[ide].v1 = v1;
    E->edges[ide].v2 = v2;
    E->edges[ide].weight = weight;
  }  
  fclose(fp);
  
  return(1);
}      

// Funcao utilizada para auxiliar os testes do funcionamento do codigo
void Print_Edges(tedgearray *E) {
   int i;

   printf("Imprimindo os edges:\n");

   for (i = 0; i < E->qtedges; i++) {
      printf(" ~> V1: %d, V2: %d, TWEIGHT: %f\n", E->edges[i].v1, E->edges[i].v2, E->edges[i].weight);
   }
}

/*
* Funcao que realiza uma simples troca entre duas variaveis 
* e eh utilizada pelo QuickSort
*/
void swap(tedge* a, tedge* b) {
  tedge tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

/* 
* QuickSort recurssivo adaptado para ordenar pelo peso
* o array do tipo tedge (para isso basta utilizar a variavel
* weight como criterio de ordenacao)
*/
void sort(tedge array[], int begin, int end) {
   int pivot = array[begin].weight;
   int i = begin + 1, j = end, k = end;
   tedge t;
 
   while (i < j) {
      if (array[i].weight < pivot) i++;
      else if (array[i].weight > pivot) {
         j--; k--;
         t = array[i];
         array[i] = array[j];
         array[j] = array[k];
         array[k] = t; }
      else {
         j--;
         swap(&array[i], &array[j]);
      }  
   }
   i--;
   swap(&array[begin], &array[i]);	
   if (i - begin > 1)
      sort(array, begin, i);
   if (end - k   > 1)
      sort(array, k, end);			
}

/*
* Algoritmo de Kruskal
*/
void Kruskal(tedgearray *edges, int num_vertices, char *text) {
   tdisjointset set; // Variavel que representara o conjunto
   
   Create_DisjointSet(&set, num_vertices); // aqui os conjuntos unitarios sao criados
   
   sort(edges->edges, 0, edges->qtedges); // Ordena em ordem crescente por peso das arestas
   
   int i;
   for (i = 0; i < edges->qtedges; i++) {
	  /* Para cada par de arestas v1 e v2 
      * verifica se possuem representantes diferentes 
	  * e caso sejam aplica a operacao Union
	  */
	  int v1 = edges->edges[i].v1;
      int v2 = edges->edges[i].v2;
      if (Find_Set(&set, v1) != Find_Set(&set, v2)) {
         // Guardando a resposta para ser colocada no arquivo de saida
         char line[100];
         sprintf(line, "  %d    %d     %.5f\n", v1, v2, edges->edges[i].weight);
         strcat(text, line);
         
         Union(&set, v1, v2);
      }
   }

}
 
int main (int argc, char *argv[]) {
   // Declare suas variaveis
   tedgearray edges;
   int qtvert = 0;

   // Leitura das arestas do grafo
   if (argc < 3) {
      printf("FALTANDO ARGUMENTOS!\n");
      return 0;
   }

   if (Read_Edges(argv[1], &edges, &qtvert) == 0) printf("Erro na leitura de arquivo"); // Erro
	
   //Print_Edges(&edges);

   char text[4096] = ""; // Variavel que guarda a resposta do algoritmo
   Kruskal(&edges, qtvert, text); // Execucao do algoritmo de Kruskal
   
   // Criar o arquivo de saida...
   FILE *saida = fopen(argv[2], "w");
   fprintf(saida, "%s", text);
   fclose(saida);
   
   return 1;

}
