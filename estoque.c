#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/estoque.h"
#include <limits.h>

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
    Medicamento* novo = (Medicamento*) malloc (sizeof(Medicamento));
    if(novo == NULL){
        printf("Erro de alocação!\n");
        exit(1);
    }
    strcpy(novo->nome,nome);
    novo->codigo = codigo;
    novo->valor = valor;
    //Copiando data de validade
    for(int i = 0; i < 3; i++){
        novo->data[i] = data_de_validade[i];
    }
    fprintf(fp,"MEDICAMENTO %s %d ADICIONADO\n",nome,codigo);
    fclose(fp); // É necessário fechar fp para salvar o medicamento em "saida.txt"
    return novo;
}

//TODO: Remover isso daqui
void LeMedicamento(Medicamento* medicamento){
    printf("NOME: %s, CODIGO: %d, VALOR: %f, DATA:%d/%d/%d\n",medicamento->nome, medicamento->codigo, medicamento->valor, medicamento->data[0], medicamento->data[1], medicamento->data[2]);
}

Lista* CriaLista(){
    return NULL;
}

void LiberaLista(Lista* l){
    Lista* aux = l;
    Lista* temp;

    while(aux != NULL){
        temp = aux->prox;
        free(aux->m);
        free(aux);
        aux = temp;
    }
}

Lista * InsereListaMedicamento (Lista * l , Medicamento * m){
    Lista* novo = (Lista*) malloc (sizeof(Lista));
    
    if(novo == NULL){
        printf("Erro de memória\n");
        exit(1);
    }

    novo->m = m;
    novo->prox = l;
    return novo;
}

Lista * RetiraListaMedicamento (FILE * fp , Lista * l , int id_medicamento){
    
    if(VerificaListaMedicamento(fp, l, id_medicamento)){
        return l;
    }
    
    Lista* ant;
    Lista* p = l;

    while(p != NULL && p->m->codigo != id_medicamento){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return l;
    }

    if(ant == NULL){
        l = l->prox;
    } else {
        ant->prox = p->prox;
    }
    fprintf(fp,"MEDICAMENTO %s %d RETIRADO\n",p->m->nome, id_medicamento);
    fclose(fp);
    free(p);
    return l;
}

/* Atualiza o preço*/
Lista* AtualizaPrecoMedicamento (FILE* fp, Lista* l , int id_medicamento, float valor){
    if(VerificaListaMedicamento(fp, l, id_medicamento)){
        return l;
    }

    for(Lista* aux = l; aux != NULL; aux = aux->prox){
        if(aux->m->codigo == id_medicamento){
            aux->m->valor = valor;
            fprintf(fp,"PRECO ATUALIZADO %s %d %.1f\n",aux->m->nome, id_medicamento, valor);
            break;
        }
    }
    fclose(fp);
    return l;
}

int VerificaListaMedicamento ( FILE * fp , Lista * p , int id_medicamento ){
    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->codigo == id_medicamento) return 0;
    }
    fprintf(fp,"MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
    fclose(fp);
    return 1;
}

int VerificaListaValidade ( FILE * fp , Lista * p , int * data ){
    int remedios_vencidos = 0;
    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        int vencido = 0;
        if(data[2] > aux->m->data[2]){ // Verificando o ano
            remedios_vencidos = vencido = 1;
            
        } else if(data[2] >= aux->m->data[2] && data[1] > aux->m->data[1]){ // Verificando o mês
            remedios_vencidos = vencido = 1;

        } else if(data[2] >= aux->m->data[2] && data[1] >= aux->m->data[1] && data[0] > aux->m->data[0]){ // Verificando o dia
            remedios_vencidos = vencido = 1;

        }
        if(vencido) fprintf(fp,"MEDICAMENTO %s %d VENCIDO\n",aux->m->nome, aux->m->codigo);
    }
    fclose(fp);
    return remedios_vencidos;
}

void ImprimeListaMedicamentos (FILE* fp, Lista * p ){
    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        fprintf(fp,"%s %d %.1f %d %d %d\n",aux->m->nome,aux->m->codigo,aux->m->valor,aux->m->data[0],aux->m->data[1],aux->m->data[2]);
    }
    fclose(fp);
}

Lista * OrdenaListaValor (Lista* p){
    Medicamento* temp;
    
    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        for(Lista* aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(aux->m->valor > aux2->m->valor){
                temp = aux->m;
                aux->m = aux2->m;
                aux2->m = temp;
            }
        }
    }
    
    return p;
}

Lista * OrdenaListaVencimento (Lista* p ){

    Medicamento* temp;

    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        for(Lista* aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(aux->m->data[2] > aux2->m->data[2]){ //Ordenando pelo ano
            temp = aux->m;
            aux->m = aux2->m;
            aux2->m = temp;
            }
        }
    }

    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        for(Lista* aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(aux->m->data[2] >= aux2->m->data[2] && aux->m->data[1] > aux2->m->data[1]){ //Ordenando pelo mês
            temp = aux->m;
            aux->m = aux2->m;
            aux2->m = temp;
            }
        }
    }

    for(Lista* aux = p; aux != NULL; aux = aux->prox){
        for(Lista* aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox){
            if(aux->m->data[2] >= aux2->m->data[2] && aux->m->data[1] >= aux2->m->data[1] && aux->m->data[0] > aux2->m->data[0]){ //Ordenando pelo dia
            temp = aux->m;
            aux->m = aux2->m;
            aux2->m = temp;
            }
        }
    }
    return p;
}