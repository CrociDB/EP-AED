#include<stdlib.h>
#include<stdio.h>

typedef double tweight;

/* 
  tipo estruturado tdisjointset: contem o numero de elementos
  e os vetores de informacoes de cada elemento: seu representante e seu rank
*/
typedef struct tdisjointset{
  int qtsets;  // numero de subconjuntos
  int *p;      // representante de cada elemento
  int *rank;   // rank de cada elemento (limite superior de sua altura)
}tdisjointset;

/* 
  tipo estruturado tedge: 
    vertice origem, vertice destino, peso
*/
typedef struct tedge {
  int v1;
  int v2;
  tweight weight;
}tedge;

/* 
  tipo estruturado tedgearray
    contem o numero de arestas e o arranjo de arestas
*/
typedef struct tedgearray {
  int qtedges;
  tedge *edges;
}tedgearray;


/********** 
  Funcoes referentes a conjuntos disjuntos
 **********/ 

/* Create_DisjointSet: Inicializa a estrutura S, criando conjuntos 
   unitarios */
void Create_DisjointSet(tdisjointset *S, int qtsets){
	/* Pseudo-code */
	//p[x] = x
	//ordem[x] = 0
	
	S->qtsets = qtsets;
	S->p = ;
	S->rank = ;
}	     
	// Pseudo-codigo do Make_Set sera que � esse Create_DisjointSet?
	//Cade o x?
 	/* Pseudo-code */
	//p[x] = x
	//ordem[x] = 0 

/*  Find_Set(S,x): determina o representante do elemento x.
    Pseudo-c�digo no livro do Cormen et al  */
int Find_Set(tdisjointset *S, int x) {
	/* Pseudo-code */
	//if x != p[x]
	//then p[x] = Find_Set(p[x])
	//return p[x]
	
	if(x != S->p) S->p = Find_Set(&S, S->p);
	return S->p;
}    

/*  Link: subrotina da funcao Union, tem como entradas 
    raizes x e y de duas sub-arvores, e transforma
    a raiz da arvore mais alta como representante dos 
    elementos da arvore mais baixa */
void Link(tdisjointset *S, int x, int y) {
	/* Pseudo-code */
	//if ordem[x] > ordem[y]
	//	then p[y] = x
	//else p[x] = y
	//if ordem[x] == ordem[y]
	//then ordem[y] = ordem[y] + 1
	
}

/* Union(S,x,y): faz a uniao das raizes das arvores de x e de y*/
void Union(tdisjointset *S, int x, int y) {
	/* Pseudo-code */
	//Link(Find_Set(x),Find_Set(y))
	Link(&S,Find_Set(&S, x),Find_Set(&S,y));
}

/* Print_DisjointSet: imprime o representante de cada elemento 
   (opcional, servirah para depurar o codigo)
void Print_DisjointSet(tdisjointset *S) {

} 
*/


/********** 
  Funcoes referentes a grafos e ao algoritmo de Kruskal
 **********/ 

/*
  Read_Edges(filename, E)
  Le um arquivo contendo as arestas de um grafo n�o orientado com pesos
  Lay-out: 
    A 1a linha deve conter o n�mero de vertices e o numero de arestas do grafo,
    separados por espa�o.
    A 2a linha em diante deve conter a informacao de cada aresta, que consiste
    no indice do vertice de origem, indice do vertice de destino e o peso da 
    aresta, tambem separados por espacos.
    Observa��es: 
      Os vertices devem ser indexados de 0 a |V|-1
      As arestas devem ser indexadas de 0 a |E|-1
      Os pesos das arestas sao numeros racionais nao negativos.
      
  Saida: E: Estrutura contendo o arranjo de arestas preenchido
         qtvert: numero de vertices do grafo lido
  
  Exemplo: O arquivo abaixo contem um grafo com 6 vertices (0,1,2,3,4,5,6) e 
  10 arestas. 
  
  6	10
  0	1	6
  0	2	1
  0	3	5
  1	2	2
  1	4	5
  2	3	2
  2	4	6
  2	5	4
  3	5	4
  4	5	3

  Codigo de saida:
    1: leitura bem sucedida
    0: erro na leitura do arquivo
*/
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

/*
  Funcao Print_Edges: imprime o conjunto de arestas armazenadas
  (opcional, serve para depurar o c�digo)
void Print_Edges(tedgearray *E) {

}
*/

/* Funcao auxiliar de compara��o entre pesos das arestas, utilizada pelo quicksort */
int comp(const void *a, const void *b) {

};

     
int main (int argc, char *argv[]) {
  // Declare suas variaveis
    
  // Leitura das arestas do grafo
    
  /* 
    Algoritmo de Kruskal:
    - Crie as componentes conexas unitarias;
    - Ordene as arestas em ordem crescente de pesos (use o QUICKSORT);
    - Para cada aresta (u,v) do arranjo de arestas:
        se u e v pertencem a componentes conexas distintas da arvore, 
          faca a uniao dessas duas componentes e escolha (u,v) para inserir na arvore; 
          caso contrario, ignore a aresta (u,v)
  */   


	/* Pseudo-code */
	//Kruskal(G,w)
	// A = 0
	//for cada vertice v de V[G]
	//	do Make_Set(v)
	//ordernar as arestas de E por peso e w nao descrescente
	//for cada aresta (u,v) de E, em rodem de peso n�o descrescente
	//	do if Find_Set(u) != Find_Set(v)
	//		then A = Union(A, (u,v))
	//return A
	
	//Entendi menos ainda este daqui

}
