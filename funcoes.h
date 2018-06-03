#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED


void printMatrix (int rows, int columns, float matrix[10][10]);

void setMatrixValue (int row, int column, float matrix[10][10]);

void sumMatrices (float firstMatrix [10][10], float secondMatrix [10][10], float resultMatrix [10][10], int rows, int columns);

void subMatrices (float firstMatrix [10][10], float secondMatrix [10][10], float resultMatrix [10][10], int rows, int columns);

void multMatrices (float firstMatrix [10][10], float secondMatrix [10][10], float resultMatrix [10][10],  int colums1, int columns2);

void writeMatrix (float matrix[10][10], int rows, int columns);

void fileMatrix (float matrix[10][10], int rows, int columns);

#endif // FUNCOES_H_INCLUDED
