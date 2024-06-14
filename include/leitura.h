#include <stdio.h>

/* Retorna um ponteiro *FILE "r" do arquivo a ser lido*/
FILE* abreArquivoLeitura(char* caminho);

/* Retorna um ponteiro *FILE "a+" do arquivo a ser escrito*/
FILE* abreArquivoEscrita(char* caminho);

/* Retorna um inteiro que representa qual das operações foi lida
-1 - Nenhuma palavra reconhecida
1 - MEDICAMENTO
2 - RETIRA
3 - IMPRIME_LISTA
4 - ATUALIZA_PRECO
5 - VERIFICA_VALIDADE
6 - VERIFICA_LISTA
7 - ORDENA_LISTA_VALOR
8 - ORDENA_LISTA_VALIDADE
9 - FIM
*/
int ReconhecerPalavra(char* palavra);