#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define VALOR_PADRAO                0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0


void Inicio(const char *nome_do_arquivo, FILE **arquivo, int *m, int *k, int *n) {

   *arquivo = fopen(nome_do_arquivo, "r");
   
   fscanf(*arquivo, "%d %d %d", m, k, n);

}


void Distribuicao(FILE **arquivo, FILE **f, int m, int k, int n, int num_blocos) {
   
   // Criação dos arquivos "F"
   f = (FILE**) calloc(m, sizeof(FILE*));
   
   int i,j;
   for (i = 0; i < m; i++) {
      char nome[100];
      sprintf(nome, "f%d", i);
      
      f[i] = fopen(nome, "w");
   }
   
   int bloco = 0;
   long int num[k];
   
   for (i = 0; i < num_blocos; i++) {
      for (j = 0; j < k; j++) {
         num[j] = VALOR_PADRAO;
   
         fscanf(*arquivo, "%i", &num[j]);
      }
   
      sort(num, k);
      SalvaF(f, num, k, i%m);
   }
   
   for (i = 0; i < m; i++) {
      fclose(f[i]);
   }

}

int Merge(FILE **arquivo, FILE **f, int m, int k, int n, int num_blocos) {
   
   FILE *g;
   
   int num = 0;
   int passo = 1;
   
   do {
      num = MergeSort(arquivo, f, g, m, &k, n, num_blocos, passo, passo%2);
      passo++;
   } while (num > 1);
   
   return passo;
   
}


int MergeSort(FILE **arquivo, FILE **f, FILE **g, int m, int *k, int n, int num_blocos, int passo, int l) {

   //printf("\nINICIANDO MERGESORT\n");
   
   // Criação dos arquivos
   f = (FILE**) calloc(m, sizeof(FILE*));
   g = (FILE**) calloc(m, sizeof(FILE*));
   
   int i,j;
   for (i = 0; i < m; i++) {
      char nomef[100];
      char nomeg[100];
      sprintf(nomef, "f%d", i);
      sprintf(nomeg, "g%d", i);
      
      if (l) {
         f[i] = fopen(nomef, "r");
         g[i] = fopen(nomeg, "w");
      } else {
         f[i] = fopen(nomef, "w");
         g[i] = fopen(nomeg, "r");
      }
   }
   
   num_blocos = arredonda_cima((double)n/(double)(*k));
   int num_blocos_arquivo = arredonda_cima((double)num_blocos / (double)m);
   
   //printf("TESTE: %d, %d, %d\n", (*k), num_blocos_arquivo, m);
   
   int k_novo = (*k) * potencia(m, passo);
   
   int x,y;
   for (x = 0; x < num_blocos_arquivo; x++) {
   
      int num_arquivo[k_novo];
      
      int kaka;
      for (kaka = 0; kaka < k_novo; kaka++) {
         num_arquivo[kaka] = VALOR_PADRAO;
      }
      
      int indice = 0;
      
      int cont = 0;
      for (y = 0; y < m; y++) {
         
         int z;
         for (z = 0; z < (*k); z++) {
            if (l) {
               fscanf(f[y], "%i ", &num_arquivo[indice]);
            } else {
               fscanf(g[y], "%i ", &num_arquivo[indice]);
            }
            
            indice++;
         }
         
      }
      
      mergeSort(num_arquivo, k_novo);
      
      for (kaka = 0; kaka < k_novo; kaka++) {
         //printf("%d, ", num_arquivo[kaka]);
         
         if (num_arquivo[kaka] != VALOR_PADRAO) fprintf(l?g[x]:f[x], "%d ", num_arquivo[kaka]);
      }
      printf("\n\n\n");
      
   }
   
   (*k) = k_novo;
   
   for (i = 0; i < m; i++) {
      fclose(f[i]);
      fclose(g[i]);
   }
   
   return num_blocos_arquivo;
   
}

void merge(int vec[], int vecSize) {
  int mid;
  int i, j, k;
  int* tmp;
 
  tmp = (int*) malloc(vecSize * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = vecSize / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    if (vec[i] < vec[j]) {
      tmp[k] = vec[i];
      ++i;
    }
    else {
      tmp[k] = vec[j];
      ++j;
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < vecSize) {
      tmp[k] = vec[j];
      ++j;
      ++k;
    }
  }
  else {
    while (i < mid) {
      tmp[k] = vec[i];
      ++i;
      ++k;
    }
  }
 
  for (i = 0; i < vecSize; ++i) {
    vec[i] = tmp[i];
  }
 
  free(tmp);
}
 
void mergeSort(int vec[], int vecSize) {
  int mid;
 
  if (vecSize > 1) {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }
}

void MergeParte(int num_arquivo[], int num[], int k_novo, int k, int passo) {

   if (passo = 1) {
      
   }
   
}

void SalvaF(FILE **f, long int num[], int k, int i) {

   int j;
   for (j = 0; j < k; j++) {
      if (num[j] != VALOR_PADRAO)
         fprintf(f[i], "%d ", num[j]);
   }
   
}


int arredonda_cima(double x)
{
   int ans = (int)x;
   if (ans == x)
      return (ans);
   else return (ans + 1);
}


int potencia(long int a, int b) {

   if (b <= 0)
      return 1;

   return a * potencia(a, b-1);
}

void sort(long int array[], int k) {
   int i,j;
   for (i = 0; i < k; i++) {
      for (j = 0; j < k; j++) {
         if (array[i] < array[j]) {
            long int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
         }
      }
   }
}


int main(int argc, char *argv[]) {
   
   if (argc < 3) {
      printf("Faltando argumentos.");
   }
   
   
   FILE *arquivo;
   int m, k, n;
   
   // Abre o arquivo e retorna os valores das seguintes variáveis.
   Inicio(argv[1], &arquivo, &m, &k, &n);
   
   FILE **f;
   int num_blocos = arredonda_cima((double)n/(double)k);
   
   Distribuicao(&arquivo, f, m, k, n, num_blocos);
   int arq = Merge(&arquivo, f, m, k, n, num_blocos);
   
   if (arq%2) {
      rename("f0", argv[2]);
   } else {
      rename("g0", argv[2]);
   }
   
   return 0;

}
