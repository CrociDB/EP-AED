#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VALOR_PADRAO                0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0+-+-+-+0x0


void Inicio(const char *nome_do_arquivo, FILE **arquivo, int *m, int *k, int *n) {

   *arquivo = fopen(nome_do_arquivo, "r");
   
   fscanf(*arquivo, "%d %d %d", m, k, n);

}


void Distribuicao(FILE **arquivo, FILE **f, int m, int k, int n) {
   
   // Criação dos arquivos "F"
   f = (FILE**) calloc(m, sizeof(FILE*));
   
   int i,j;
   for (i = 0; i < m; i++) {
      char nome[100];
      sprintf(nome, "f%d", i);
      
      f[i] = fopen(nome, "w");
   }
   
   int bloco = 0;
   int num_blocos = arredonda_cima((double)n/(double)k);
   long int num[k];
   
   for (i = 0; i < num_blocos; i++) {
      for (j = 0; j < k; j++) {
         num[j] = VALOR_PADRAO;
   
         fscanf(*arquivo, "%i", &num[j]);
      }
   
      sort(num, k);
      SalvaF(f, num, k, i%m);
   }
   
   // Lendo os blocos...

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
   
   Distribuicao(&arquivo, f, m, k, n);
   
   
   //printf("%d %d %d", num_arquivos, num_elem_bloco, num_elem);
   
   
   return 0;

}
