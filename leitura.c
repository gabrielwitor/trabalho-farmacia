#include "include/leitura.h"
#include <stdio.h>
#include <string.h>

FILE* abreArquivoLeitura(char* caminho){
    FILE * arquivo;
    arquivo = fopen(caminho,"r");

    if(arquivo == NULL){
        printf("O arquivo \"%s\" não foi encontrado.",caminho);
        return NULL;
    }

    if(fgetc(arquivo) == EOF){
        printf("O arquivo \"%s\" está vazio.",caminho);
        return NULL;
    }

    rewind(arquivo);
    return arquivo;
}

FILE* abreArquivoEscrita(char* caminho){
    FILE * arquivo;
    arquivo = fopen(caminho,"a+");
    return arquivo;
}

int ReconhecerPalavra(char* palavra){
    if(!strcmp(palavra,"MEDICAMENTO")){
        return 1;
    } else if(!strcmp(palavra,"RETIRA")){
        return 2;
    } else if(!strcmp(palavra,"IMPRIME_LISTA")){
        return 3;
    } else if(!strcmp(palavra,"ATUALIZA_PRECO")){
        return 4;
    } else if(!strcmp(palavra,"VERIFICA_VALIDADE")){
        return 5;
    } else if(!strcmp(palavra,"VERIFICA_LISTA")){
        return 6;
    } else if(!strcmp(palavra,"ORDENA_LISTA_VALOR")){
        return 7;
    } else if(!strcmp(palavra,"ORDENA_LISTA_VALIDADE")){
        return 8;
    } else if(!strcmp(palavra,"FIM")){
        return 9;
    } 
    return -1;
}