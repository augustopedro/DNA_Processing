/*
 * Algoritmos e Estruturas de Dados III
 * @authors Pedro Augusto, Pedro Victor, Rogério Dias
 * Casamento de Padrões em sequências de DNA
 */


/**
 * @file KnuthMorrisPratt.h
 * @brief Cabeçalho para as funções do código-fonte KnuthMorrisPratt.c
 */

#ifndef _DNA_H
#define _DNA_H

#ifdef  __cplusplus
extern "C" {
#endif

    int *compute_prefix_function(char *pattern, int psize);
    int KnuthMorrisPratt(char *target, int tsize, char *pattern, int psize);

#ifdef  __cplusplus
}
#endif

#endif
