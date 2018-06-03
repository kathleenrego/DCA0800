#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funcoes.h"


void printMatrix (int rows, int columns, float matrix[10][10]) {
    //Esta funcao printa a matriz para que ela possa ser visualizada pelo usuario
    int i, j;

    printf("\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (columns == 1) {
                //Para o caso de especial de haver apenas uma coluna
                printf(" | %8.3f |", matrix[i][j]);
            } else if (j == 0) {
                //Imprime um valor na extremidade esquerda da matriz
                printf(" | %8.3f ", matrix[i][j]);
            } else if (j == columns - 1) {
                //Imprime um valor extremidade direita da matriz
                printf("%8.3f |", matrix[i][j]);
            } else {
                //Imprime valores cuja posicao nao se enquadra nos casos anteriores
                printf("%8.3f ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void setMatrixValue (int row, int column, float matrix[10][10]) {
    int x;
    printf("Digite um valor: ");
    scanf("%d", &x);

    matrix[row - 1][column -1] = x;
}

void sumMatrices (float firstMatrix [10][10], float secondMatrix [10][10], float resultMatrix [10][10], int rows, int columns) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

void subMatrices (float firstMatrix [10][10], float secondMatrix [10][10], float resultMatrix [10][10], int rows, int columns) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
}

void multMatrices (float firstMatrix [10][10], float secondMatrix [10][10], float resultMatrix [10][10], int columns1, int columns2) {
    //Multiplica as duas matrizes
    int i, j, k, l;
    k = 0;
    i = 0;

    for (i = 0; i < columns2; i++) {
        for (k = 0; k < columns2; k++) {
            resultMatrix[i][k] = 0;
            l = 0;
            for (j = 0; j < columns1; j++) {
            resultMatrix[i][k] = resultMatrix[i][k] + firstMatrix[i][j]*secondMatrix[l][k];
            l++;
            }
        }
        k++;
    }
}

void writeMatrix (float matrix[10][10], int rows, int columns) {
    //Esta funcao permite ao usuario digitar todos os valores da matriz de uma vez
    int i, j;

    printf("Digite os valores da matriz: \n");

    //O loop faz o usuario digitar os valores ordenados primeiro por linha e, depois, por coluna
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void fileMatrix (float matrix [10][10], int rows, int columns) {
    //Fornece os valores da matriz a partir de um arquivo ja existente
    //O numero de fileiras e colunas deve ser igual aquele da matriz do arquivo
    FILE *arq;
    char locale[100];
    int i, j;

    printf("Insira a localizacao do arquivo: ");
    scanf("%s", &locale);

    arq = fopen(locale, "r");

    if (arq == NULL) {
        printf("Esse arquivo nao existe");
    }

    //O loop obtem os valores contidos no arquivo e os passa a matriz
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            fscanf(arq, "%f", &matrix[i][j]);
        }
    }

    fclose(arq);
    printf("\n");
}

