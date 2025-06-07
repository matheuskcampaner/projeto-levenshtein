#include <string.h>
#include "levenshtein.h"

// Função que calcula a distância de Levenshtein entre duas strings
int levenshtein(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // Matriz de distâncias (alocada na stack)
    int d[len_s + 1][len_t + 1];

    // Inicializa primeira coluna
    for (int i = 0; i <= len_s; i++) d[i][0] = i;

    // Inicializa primeira linha
    for (int j = 0; j <= len_t; j++) d[0][j] = j;

    // Preenche a matriz com base nas operações de edição
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1; // Custo: 0 se igual, 1 se diferente

            // Calcula os custos de inserção, deleção e substituição
            int del = d[i - 1][j] + 1;
            int ins = d[i][j - 1] + 1;
            int sub = d[i - 1][j - 1] + cost;

            // Escolhe o menor custo
            d[i][j] = del < ins ? (del < sub ? del : sub) : (ins < sub ? ins : sub);
        }
    }

    // Distância final na célula inferior direita
    return d[len_s][len_t];
}

// Função que calcula a distância de Hamming entre duas strings de mesmo tamanho
int hamming(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // Retorna -1 se os tamanhos forem diferentes (Hamming exige tamanhos iguais)
    if (len_s != len_t) return -1;

    int dist = 0;

    // Conta os caracteres diferentes nas mesmas posições
    for (int i = 0; i < len_s; i++) {
        if (s[i] != t[i]) dist++;
    }

    return dist;
}
