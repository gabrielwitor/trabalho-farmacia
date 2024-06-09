#include <stdio.h>

// Tipo que define o medicamento
typedef struct medicamento Medicamento;

// Tipo que define a lista
typedef struct lista Lista;

/* Cria um novo medicamento */
Medicamento* CriaMedicamento (FILE* fp , char* nome , int codigo , float valor , int* data_de_validade);

Lista* CriaLista();

/* Insere um medicamento em uma lista */
Lista* InsereListaMedicamento (FILE* fp, Lista* l, Medicamento* m);

/* Retira um medicamento de uma determinada lista */
Lista* RetiraListaMedicamento (FILE* fp, Lista* l , int id_medicamento);

/* Verifica se um medicamento e s t presente em uma determinada lista */
int VerificaListaMedicamento (FILE* fp, Lista* p, int id_medicamento);

/* Verifica se existe um medicamento vencido em uma determinada lista */
int VerificaListaValidade (FILE* fp, Lista* p, int * data);

/* Imprime todos os medicamentos de uma lista */
void ImprimeListaMedicamentos (FILE* fp, Lista* p);

/* Ordena Lista pelo valor do medicamento */
Lista* OrdenaListaValor (Lista* p);

/* Ordena Lista pela data de vencimento do medicamento */
Lista* OrdenaListaVencimento (Lista* p);