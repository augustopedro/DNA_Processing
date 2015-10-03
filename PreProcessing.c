/*
 * Algoritmos e Estruturas de Dados III
 * @authors Pedro Augusto, Pedro Victor, Rogério Dias
 * Casamento de Padrões em sequências de DNA
 */

/**
 * @file PreProcessing.c
 * @brief Arquivo com as funções para pré-processamento do texto
 */

#include <stdio.h>
#include <stdlib.h>
#include "PreProcessing.h"

/**
 * @brief Função para calcular o tamanho do arquivo
 * @param *arquivo Ponteiro para o arquivo
 * @return tamanho Tamanho do arquivo em questão
 */

long calcularTamanhoArquivo(FILE *arquivo) {

    /*Guarda o estado ante de chamar a função fseek*/
    long posicaoAtual = ftell(arquivo);

    /*Guarda tamanho do arquivo*/
    long tamanho;

    /*Calcula o tamanho do arquivo*/
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);

    /*Recupera o estado antigo do arquivo*/
    fseek(arquivo, posicaoAtual, SEEK_SET);

    return tamanho;
}

/**
 * @brief Função para retirar caracteres inválidos do texto de entrada a ser processado
 * @param *textoentrada Texto de entrada a ter seus caracteres desnecessários removidos
 * @param *textolimpo Texto de saída contendo apenas as sequências a serem processadas
 * @param *qtdcaracteres Quantidade de caracteres do texto de entrada
 */

void limpartexto(char *textoentrada, char *textolimpo, int qtdcaracteres) {
    int i = 0, j = 0;
    for (i = 0; i < qtdcaracteres; i++) {
        if (textoentrada[i] != ' ' && textoentrada[i] > 57 && textoentrada[i] < 122) {
            textolimpo[j] = textoentrada[i];
            j++;
        }
    }
    textolimpo[j] = '\0';
}
