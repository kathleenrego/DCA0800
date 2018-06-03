#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <time.h>


void randomm (int rows, int columns, float matrix[10][10], float Vmin, float Vmax) {
    //Esta funcao popula a matriz com valores aleatorios dentre de um intervalo
    int i, j;
    float aleatorio;
    srand(time(0));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            aleatorio = (rand()/(float)RAND_MAX)*(Vmax - Vmin) + Vmin;//Gera um valor aleatorio entre Vmin e Vmax
            matrix[i][j] = aleatorio;
        }
    }
}

int main()
{
    int nla, nca, nlb, ncb, nlc, ncc, la, ca, lb, cb;
    float A[10][10], B[10][10], C[10][10], max, min;
    nla = nca = nlb = ncb = nlc = ncc = 10;
    la = ca = lb = cb = 1;
    max = min = 0;
    int option = 0;

    while (1){

        printf("\nPROGRAMA DE MANIPULACAO DE MATRIZES \n(1) Definir o tamanho da matriz A\n(2) Definir o tamanho da matriz B\n(3) Preencher a matriz A com valores aleatorios\n(4) Preencher a matriz B com valores aleatorios\n(5) Atribuir valor para um elemento da matriz A\n(6) Atribuir valor para um elemento da matriz B\n(7) Calcular A+B\n(8) Calcular A-B\n(9) Calcular A*B\n(10) Imprimir matriz A\n(11) Imprimir matriz B\n(12) Imprimir matriz C\n(13) Escrever Matriz A\n(14) Escrever Matriz B\n(15) Adicionar valores de A por um arquivo\n(16) Adicionar valores de B por um arquivo\n(17) Sair\ndigite sua operacao: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nDigite a quantidade de linhas da matriz A: ");
                scanf("%d", &nla);
                printf("Digite a quantidade de colunas da matriz A: ");
                scanf("%d", &nca);
                if (nla > 10 || nca > 10 || nla<1 || nca < 0) {
                    nla = 10;
                    nca = 10;
                    printf("\nTamanho invalido\n");
                }
                break;
            case 2:
                printf("\nDigite a quantidade de linhas da matriz B: ");
                scanf("%d", &nlb);
                printf("Digite a quantidade de colunas da matriz B: ");
                scanf("%d", &ncb);
                if (nlb > 10 || ncb > 10 || nlb<1 || ncb < 0) {
                    nlb = 10;
                    ncb = 10;
                    printf("\nTamanho invalido\n");
                }
                break;
            case 3:
                printf("\nDigite o valor maximo: ");
                scanf("%f", &max);
                printf("Digite o valor minimo: ");
                scanf("%f", &min);
                if(max<min){
					printf("\nO valor máximo tem que ser maior que o mínimo, escolha novamente!: ");
					printf("\nDigite o valor maximo: ");
					scanf("%f", &max);
					printf("Digite o valor minimo: ");
					scanf("%f", &min);
				}
                randomm(nla, nca, A, max, min);
                break;
            case 4:
                printf("\nDigite o valor maximo: ");
                scanf("%f", &max);
                printf("Digite o valor minimo: ");
                scanf("%f", &min);
                if(max<min){
					printf("\nO valor máximo tem que ser maior que o mínimo, escolha novamente!: ");
					printf("\nDigite o valor maximo: ");
					scanf("%f", &max);
					printf("Digite o valor minimo: ");
					scanf("%f", &min);
				}
                randomm(nlb, ncb, B, max, min);
                break;
            case 5:
                printf("\nDigite a linha do elemento: ");
                scanf("%d", &la);
                printf("Digite a coluna do elemento: ");
                scanf("%d", &ca);
                if (la > nla || ca > nca || la<0 || ca<0 ) {
                    la = 1;
                    ca = 1;
                    printf("\nEssa posicao nao existe\n");
                } else {
                    setMatrixValue(la, ca, A);
                    printf("\nValor inserido com sucesso\n");
                }
                break;
            case 6:
                printf("\nDigite a linha do elemento: ");
                scanf("%d", &lb);
                printf("Digite a coluna do elemento: ");
                scanf("%d", &cb);
                if (lb > nlb || cb > ncb || lb<0 || cb<0 ) {
                    lb = 1;
                    cb = 1;
                    printf("\nEssa posicao nao existe\n");
                } else {
                    setMatrixValue(lb, cb, B);
                    printf("\nValor inserido com sucesso\n");
                }
                break;
            case 7:
                if (nla != nlb || nca != ncb) {
                    printf("\nMatrizes com tamanhos incompativeis\n");
                } else {
                    sumMatrices(A, B, C, nla, nca);
                    nlc = nla;
                    ncc = nca;
                }
                break;
            case 8:
               if (nla != nlb || nca != ncb) {
                    printf("\nMatrizes com tamanhos incompativeis\n");
                } else {
                    subMatrices(A, B, C, nla, nca);
                    nlc = nla;
                    ncc = nca;
                }
                break;
            case 9:
                if (nca != nlb) {
                    printf("\nMatrizes com tamanhos incompativeis\n");
                } else {
                    nlc = nla;
                    ncc = ncb;
                    multMatrices(A, B, C, nca, ncb);
                }
                break;
            case 10:
                printMatrix (nla, nca, A);
                break;
            case 11:
                 printMatrix (nlb, ncb, B);
                 break;
            case 12:
                printMatrix (nlc, ncc, C);
                break;
            case 13:
                writeMatrix(A, nla, nca);
                break;
            case 14:
                writeMatrix(B, nlb, ncb);
                break;
            case 15:
                fileMatrix(A, nla, nca);
                break;
            case 16:
                fileMatrix(B, nlb, ncb);
                break;
            case 17:
                exit(0);
                break;
            default:
                printf("\nInput invalido\n");
            }
    }

    return 0;
}
