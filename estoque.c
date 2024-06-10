#include <stdio.h>
#include <string.h>
#include "estoque.h"

struct medicamento{
    char nome[20];
    int codigo;
    float valor;
    int data[3];
};

struct lista{
    Medicamento* m;
    Lista* prox;
};

Medicamento* CriaMedicamento (FILE* fp , char* nome , int codigo ,float valor ,int * data_de_validade ){
    
}

Lista* CriaLista(){

}

Lista * InsereListaMedicamento ( FILE * fp , Lista * l , Medicamento * m ){

}

Lista * RetiraListaMedicamento ( FILE * fp , Lista * l , int id_medicamento ){

}

int VerificaListaMedicamento ( FILE * fp , Lista * p , int id_medicamento ){

}

int VerificaListaValidade ( FILE * fp , Lista * p , int * data ){

}

void ImprimeListaMedicamentos ( FILE * fp , Lista * p ){

}

Lista * OrdenaListaValor (Lista* p ){

}

Lista * OrdenaListaVencimento (Lista* p ){
    
}

int LerArquivo(){ 
    FILE * arquivo;

    arquivo = fopen("entrada.txt","r");

    if(arquivo == NULL){
        printf("O arquivo \"entrada.txt\" não existe.");
        return 1;
    }

    if(fgetc(arquivo) == EOF){
        printf("O arquivo está vazio.");
    }

    rewind(arquivo);

    char frase[255];

    while(1){
        if(feof(arquivo)){
            break;
        }
        fscanf(arquivo,"%s",frase);

        printf("%s\n",frase);
        if(!strcmp(frase,"MEDICAMENTO")){
            fgets(frase,255,arquivo);
            printf("teste: %s",frase);
            
        } else if(!strcmp(frase,"RETIRA")){

        } else if(!strcmp(frase,"IMPRIME_LISTA")){

        } else if(!strcmp(frase,"ATUALIZA_PRECO")){

        } else if(!strcmp(frase,"VERIFICA_VALIDADE")){

        } else if(!strcmp(frase,"VERIFICA_LISTA")){

        } else if(!strcmp(frase,"ORDENA_LISTA_VALIDADE")){

        } else if(!strcmp(frase,"FIM")){

        } 
    }


    return 0;
}