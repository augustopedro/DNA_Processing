/*
 * Algoritmos e Estruturas de Dados III
 * @authors Pedro Augusto, Pedro Victor, Rogério Dias
 * Casamento de Padrões em sequências de DNA
 */

/**
 * @file KnuthMorrisPratt.c
 * @brief Arquivo com as funções para a implementação da Busca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KnuthMorrisPratt.h"

/**
 * @brief Algorimo de Knuth-Morris-Pratt
 * @param *target Sequência a ser processada
 * @param tsize Tamanho da sequência a ser processada
 * @param *pattern Padrão a ser encontrado
 * @param psize Tamanho do padrão a ser encontrado
 */
int KnuthMorrisPratt(char *target, int tsize, char *pattern, int psize) {
    int i;
    int found = -1;
    int *pi = compute_prefix_function(pattern, psize);
    int k = -1;
    if (!pi)
        return -1;
    for (i = 0; i < tsize; i++) {
        while (k > -1 && pattern[k + 1] != target[i])
            k = pi[k];
        if (target[i] == pattern[k + 1])
            k++;
        if (k == psize - 1) {
            found = 1;

            int position = i - k;

            int linha = position / 60;

            int setor = (position) % 60;

            int pos = position;

            if (setor >= 0 && setor < 10) {
                if (linha != 0) {
                    pos = pos + 5 + (linha * 21) + 1;
                } else {
                    pos = pos + 6;
                }
            }

            if (setor >= 10 && setor < 20) {
                if (linha != 0) {
                    pos = pos + 6 + (linha * 21) + 1;
                } else {
                    pos = pos + 7;
                }
            }

            if (setor >= 20 && setor < 30) {
                if (linha != 0) {
                    pos = pos + 7 + (linha * 21) + 1;
                } else {
                    pos = pos + 8;
                }
            }

            if (setor >= 30 && setor < 40) {
                if (linha != 0) {
                    pos = pos + 8 + (linha * 21) + 1;
                } else {
                    pos = pos + 9;
                }
            }

            if (setor >= 40 && setor < 50) {
                if (linha != 0) {
                    pos = pos + 9 + (linha * 21) + 1;
                } else {
                    pos = pos + 10;
                }
            }

            if (setor >= 50 && setor < 60) {
                if (linha != 0) {
                    pos = pos + 10 + (linha * 21) + 1;
                } else {
                    pos = pos + 11;
                }
            }

            printf("%d\n", pos);
        }
    }
    free(pi);
    return found;
}

/**
 * @brief Função de cálculo do prefixo
 * @param *pattern Padrão a ser procurado
 * @param psize Tamanho do padrão a ser procurado
 */
int *compute_prefix_function(char *pattern, int psize) {
    int k = -1;
    int i = 1;
    int *pi = malloc(sizeof (int) * psize);
    if (!pi)
        return NULL;

    pi[0] = k;
    for (i = 1; i < psize; i++) {
        while (k > -1 && pattern[k + 1] != pattern[i])
            k = pi[k];
        if (pattern[i] == pattern[k + 1])
            k++;
        pi[i] = k;
    }
    return pi;
}