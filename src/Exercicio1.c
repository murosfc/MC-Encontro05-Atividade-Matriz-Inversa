 /*Faça um programa que dadas duas matrizes A5×5 e B5×5 geradas aleatoriamente com números de 1 até
30, verifique se B é a inversa de A, isto é, se B é igual a A−1
. Se B for a inversa, a multiplicação de A
por B resulta em uma matriz identidade.
Crie e utilize uma função para verificar se a matriz resultante de A × B é uma matriz identidade.
Crie e utilize dois procedimentos: um para a geração das matrizes e outro para realizar a multiplicação
delas.
De acordo com o retorno da função de verificação, deve-se imprimir na função main: “B é inversa de A”
ou “B não é inversa de A”.
Obs.: Todas as matrizes utilizadas devem ser declaradas na função main.*/

//Aluno Felipe Muros

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void geraMatriz(int matriz[TAM][TAM]);
void multiplicaMatriz(int matrizA[TAM][TAM], int matrizB[TAM][TAM], int matrizC[TAM][TAM]);
int verificaMatriz(int matriz[TAM][TAM]);

int main(){
    int MatA[TAM][TAM], MatB[TAM][TAM], MatC[TAM][TAM];

    geraMatriz(MatA);
    geraMatriz(MatB);

    if(verificaMatriz(MatC) == 1){
        printf("B e inversa de A");
    }else{	
        printf("B nao e inversa de A");
    }
}

int verificaMatriz(int matriz[TAM][TAM]){
    int i, j, flag = 1;
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(i == j){
                if(matriz[i][j] != 1){
                    flag = 0;
                }
            }else{
                if(matriz[i][j] != 0){
                    flag = 0;
                }
            }
        }
    }
    return flag;
}

void geraMatriz(int matriz[TAM][TAM]){
    int i, j;
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            matriz[i][j] = (rand() % 30) + 1;
        }
    }
}

void multiplicaMatriz(int matrizA[TAM][TAM], int matrizB[TAM][TAM], int matrizC[TAM][TAM]){
    int i, j, k, soma = 0;
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            for(k = 0; k < TAM; k++){
                soma += matrizA[i][k] * matrizB[k][j];
            }
            matrizC[i][j] = soma;
            soma = 0;
        }
    }
}