#include <stdio.h>
#include "include/estoque.h"
#include "include/leitura.h"

#define MAX_SIZE 255

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Quantidade de argumentos insuficiente.\nPara rodar o programa, utilize: ./trabalho {arquivoDeEntrada.txt} {arquivoDeSaida.txt}\n");
        return 0;
    }

    FILE* arquivo_leitura = abreArquivoLeitura(argv[1]);

    if(arquivo_leitura == NULL){
        printf("Houve um erro na leitura do arquivo \"%s\".",argv[1]);
        return 0;
    }

    Lista* lista_medicamentos = CriaLista();

    //Loop de leitura do arquivo
    char palavra_lida[MAX_SIZE];

    char nome[MAX_SIZE];
    int codigo;
    float valor;
    int data_de_validade[3];      

    do{
        fscanf(arquivo_leitura,"%s",palavra_lida);
        printf("Palavra lida: %s\n",palavra_lida);

        switch (ReconhecerPalavra(palavra_lida)){
            
            case 1: // Leitura: MEDICAMENTO 

                fscanf(arquivo_leitura,"%s %d %f %d %d %d",nome, &codigo, &valor, &data_de_validade[0], &data_de_validade[1], &data_de_validade[2]);
                Medicamento* medicamento_lido = CriaMedicamento(abreArquivoEscrita(argv[2]), nome, codigo, valor, data_de_validade);
                lista_medicamentos = InsereListaMedicamento(lista_medicamentos,medicamento_lido);

                LeMedicamento(medicamento_lido); //TODO: Remover isso depois
                break;

            case 2: // Leitura: RETIRA

                fscanf(arquivo_leitura,"%d",&codigo);
                lista_medicamentos = RetiraListaMedicamento(abreArquivoEscrita(argv[2]),lista_medicamentos,codigo);
                break;

            case 3: // Leitura: IMPRIME_LISTA

                ImprimeListaMedicamentos(abreArquivoEscrita(argv[2]), lista_medicamentos);
                break;

            case 4: // Leitura: ATUALIZA_PRECO

                fscanf(arquivo_leitura,"%d %f", &codigo, &valor);
                AtualizaPrecoMedicamento(abreArquivoEscrita(argv[2]), lista_medicamentos, codigo, valor);
                break;

            case 5: // Leitura: VERIFICA_VALIDADE

                fscanf(arquivo_leitura,"%d %d %d", &data_de_validade[0], &data_de_validade[1], &data_de_validade[2]);
                if(!VerificaListaValidade(abreArquivoEscrita(argv[2]),lista_medicamentos,data_de_validade)){
                    FILE* arquivo_escrita = abreArquivoEscrita(argv[2]);
                    fprintf(arquivo_escrita,"MEDICAMENTO VENCIDO NAO ENCONTRADO NA LISTA\n");
                    fclose(arquivo_escrita);
                }
                break;

            case 6: // Leitura: VERIFICA_LISTA

                fscanf(arquivo_leitura,"%d", &codigo);
                VerificaListaMedicamento(abreArquivoEscrita(argv[2]), lista_medicamentos, codigo);
                break;

            case 7: // Leitura: ORDENA_LISTA_VALOR

                lista_medicamentos = OrdenaListaValor(lista_medicamentos);
                break;

            case 8: // Leitura: ORDENA_LISTA_VALIDADE

                lista_medicamentos = OrdenaListaVencimento(lista_medicamentos);
                break;

            default:

                break;
        }

    } while (ReconhecerPalavra(palavra_lida) != 9);

    LiberaLista(lista_medicamentos);
    
    return 0;
}

