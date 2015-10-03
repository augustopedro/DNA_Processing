/*
 * Algoritmos e Estruturas de Dados III
 * Professor: André Pimenta
 * Alunos: Pedro Augusto, Pedro Victor, Rogério Dias
 * Turma: 10A
 * Sistema Operacional: Ubuntu 12.10
 * IDE: NetBeans 7.2.2
 * Casamento de Padrões em sequências de DNA
 */


/**
 * @file main.c
 * @brief Arquivo principal com a função main e interface implementadas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KnuthMorrisPratt.h"
#include "PreProcessing.h"

int main(int argc, char *argv[]) {

    /*Verifica a quantidade de argumentos passados.*/
    if (argc != 4) {

        printf("Quantidade de argumentos inválidos!\n");

    } else {
        FILE *pt;

        /*Verifica o comando de busca.*/
        if (strcmp(argv[1], "busca_dna") == 0) {

            pt = fopen(argv[3], "r");

            /*Verifica a possibilidade de abrir o arquivo em disco.*/
            if (pt == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return EXIT_SUCCESS;

            } else {

                /*Realiza todo o processamento necessário e remoção de caracteres inválidos.*/
                int qtdcaracteres = calcularTamanhoArquivo(pt);

                char textoentrada[qtdcaracteres + 1];

                fread(textoentrada, sizeof (char), qtdcaracteres, pt);

                textoentrada[qtdcaracteres] = '\0';

                char textolimpo[qtdcaracteres];

                limpartexto(textoentrada, textolimpo, qtdcaracteres);


                /*Processamento do padrão inserido sobre o texto de entrada.*/
                int result = 0;
                result = KnuthMorrisPratt(textolimpo, strlen(textolimpo), argv[2], strlen(argv[2]));

                if (result == -1) {
                    printf("Not found!\n");
                }

                fclose(pt);
                return EXIT_SUCCESS;
            }
        }else{
            printf("Comando inválido!\n");
        }
    }
}
