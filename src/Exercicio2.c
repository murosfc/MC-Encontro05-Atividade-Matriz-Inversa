/*
A matriz inversa pode ser utilizada para a resolução de um Sistema Linear A.x = b. 
Faça um programa que solucione o Sistema A.x = b, dada as matrizes A−1 e b acima, utilizando a estratégia apresentada anteriormente (x = A−1.b).
Crie e utilize um procedimento para solucionar o Sistema (encontrar o valor de x).
Obs.: Todas as matrizes utilizadas devem ser declaradas na função main.
*/

//Aluno Felipe Muros
#include <stdio.h>

#define TAM 3

void printMat(float mat[TAM][TAM]);
void calcMatX(float matAInv[TAM][TAM], int vetB[TAM], float vetX[TAM]);

int main(){
    float MatA[TAM][TAM] = {{1, 0, 0}, {1, 3, 1}, {1, 2, 0}};
    float matAInv[TAM][TAM] = {{1, 0, 0}, {-0.5, 0, -0.5}, {0.5, 1, -1.5}};
    int vetB[TAM] = {4, 9, 8};
    float vetX[TAM];

    calcMatX(matAInv, vetB, vetX);

    printf("Matriz A:\n");
    printMat(MatA);

    printf("Matriz A Inversa:\n");
    printMat(matAInv);
    
    printf("\nVetor B:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetB[i]);
    }

    printf("\n\nVetor X:\n");
    for (int i = 0; i < TAM; i++){
        printf("%.1f\t", vetX[i]);
    }   
}

void printMat(float mat[TAM][TAM]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("%.1f\t", mat[i][j]);
        }
        printf("\n");
    }
}

void calcMatX(float matAInv[TAM][TAM], int vetB[TAM], float vetX[TAM]){
    for (int i = 0; i < TAM; i++) {
        vetX[i] = 0;
        for (int j = 0; j < TAM; j++) {
            vetX[i] += matAInv[i][j] * vetB[j];
        }
    }
}