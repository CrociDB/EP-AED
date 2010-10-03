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
	/* Pseudo-code */
	//p[x] = x
	//ordem[x] = 0
	
	S->qtsets = qtsets;
	
	S->p = (int) malloc(qtsets * sizeof(int));
	S->rank = (int) malloc(qtsets * sizeof(int));

   int i;
   for (i = 0; i < qtsets; i++) {
      S->p[i]= i;
      S->rank[i] = 0;
   }
}	     

int Find_Set(tdisjointset *S, int x) {
	/* Pseudo-code */
	//if x != p[x]
	//then p[x] = Find_Set(p[x])
	//return p[x]
	
	if(x != S->p[x]) S->p[x] = Find_Set(S, S->p[x]);
	return S->p[x];
}    

void Link(tdisjointset *S, int x, int y) {
	/* Pseudo-code */
	//if ordem[x] > ordem[y]
	//	then p[y] = x
	//else p[x] = y
	//if ordem[x] == ordem[y]
	//then ordem[y] = ordem[y] + 1
	
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
	/* Pseudo-code */
	//Link(Find_Set(x),Find_Set(y))
	
	Link(S,Find_Set(S, x),Find_Set(S, y));
}

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

void Print_Edges(tedgearray *E) {
   int i;

   printf("Imprimindo os edges:\n");

   for (i = 0; i < E->qtedges; i++) {
      printf(" ~> V1: %d, V2: %d, TWEIGHT: %f\n", E->edges[i].v1, E->edges[i].v2, E->edges[i].weight);
   }
}


void swap(tedge* a, tedge* b) {
  tedge tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

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




void Kruskal(tedgearray *edges, int num_vertices, char *text) {
   tdisjointset set;
   
   Create_DisjointSet(&set, num_vertices);
   
   sort(edges->edges, 0, edges->qtedges);
   
   
   
   int i;
   for (i = 0; i < edges->qtedges; i++) {
      int v1 = edges->edges[i].v1;
      int v2 = edges->edges[i].v2;
      if (Find_Set(&set, v1) != Find_Set(&set, v2)) {
         // Aqui ele só dá Union...
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
   if (argc < 2) {
      printf("FALTANDO ARGUMENTOS!");
      return 0;
   }

   if (!Read_Edges(argv[1], &edges, &qtvert)) return 1; // Erro

   //Print_Edges(&edges);

   char text[1024] = "";
   Kruskal(&edges, qtvert, text);
   
   // Criar o arquivo de saida...
   FILE *saida = fopen(argv[2], "w");
   fprintf(saida, "%s", text);
   fclose(saida);

}
