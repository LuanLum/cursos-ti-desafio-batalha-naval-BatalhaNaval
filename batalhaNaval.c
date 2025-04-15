// Hora de Codar 3: Cone

//              0 0 3 0 0   0 0 3 0 0
// 0 0 3 0 0    0 0 3 0 0   0 3 3 3 0
// 0 3 3 3 0    3 3 3 3 3   3 3 3 3 3
// 3 3 3 3 3    0 0 3 0 0   0 3 3 3 0
// 3 3 3 3 3    0 0 3 0 0   0 0 3 0 0

// Cone         Cruz        Octaedro

#include <stdio.h>

#define LINHA 10
#define COLUNA 10

int main(){
    int linha[LINHA];
    for(int i = 0; i < LINHA; i++){
        linha[i] = i;
    }


    // 1. Criando o Tabuleiro (Matriz 10x10)
    int tabuleiro[LINHA][COLUNA] = {0};

    // 2.1 Cruz 0,3 -> 4,3 / 1,2 -> 1,6 (Contagem manual)
    for(int count1 = 0, count2 = 0, size1 = 5, size2 = 5, i = 0, start1 = 0, start2 = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA ; j++){
            (i == 0) ? start1 = 1 : 0;
            if(start1 == 1 && count1 < size1 && j == 3){
                tabuleiro[i][j] = 1;
                count1++;
            } 
            (i == 2) ? start2 = 1 : 0;     
            if(start2 == 1 && count2 < size2 && j - count2 == 1){
                tabuleiro[i][j] = 1;
                count2++;
            }   
        }
    }

    // 2.2 Losango 5,7 (Encontrar centro dinamico + contagem de render por linha)
    int losangoR = 5, losangoC = 7; 
    for(int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, size1 = 1, size2 = 3, size3 = 5, size4 = 3, size5 = 1, i = 0, start1 = 0, start2 = 0, start3 = 0, start4 = 0, start5 = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA ; j++){
        (i == losangoR - 2) ? start1 = 1 : 0;
        if(start1 == 1 && count1 < size1 && j == losangoC){
            tabuleiro[i][j] = 2;
            count1++;
        } 
        (i == losangoR - 1) ? start2 = 1 : 0;
        if(start2 == 1 && count2 < size2 && j - count2 == losangoC - 1){
            tabuleiro[i][j] = 2;
            count2++;
        }
        (i == losangoR) ? start3 = 1 : 0;
        if(start3 == 1 && count3 < size3 && j - count3 == losangoC - 2){
            tabuleiro[i][j] = 2;
            count3++;
        }
        (i == losangoR + 1) ? start4 = 1 : 0;
        if(start4 == 1 && count4 < size4 && j - count4 == losangoC - 1){
            tabuleiro[i][j] = 2;
            count4++;
        }
        (i == losangoR + 2) ? start5 = 1 : 0;
        if(start5 == 1 && count5 < size5 && j - count5 == losangoC){
            tabuleiro[i][j] = 2;
            count5++;
        }
    }
}

    // 2.3 Cone 7,2 (Encontrar centro dinamico + contagem de render por linha)
    int coneR = 7, coneC = 2; 
    for(int count1 = 0, count2 = 0, count3 = 0, size1 = 1, size2 = 3, size3 = 5, i = 0, start1 = 0, start2 = 0, start3 = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA ; j++){
            (i == coneR - 2) ? start1 = 1 : 0;
            if(start1 == 1 && count1 < size1 && j == coneC){
                tabuleiro[i][j] = 3;
                count1++;
            } 
            (i == coneR - 1) ? start2 = 1 : 0;
            if(start2 == 1 && count2 < size2 && j - count2 == coneC - 1){
                tabuleiro[i][j] = 3;
                count2++;
            }
            (i == coneR) ? start3 = 1 : 0;
            if(start3 == 1 && count3 < size3 && j - count3 == coneC - 2){
                tabuleiro[i][j] = 3;
                count3++;
            }
        }
    }
    // 3. Exibindo o Tabuleiro
    printf(" TABULEIRO BATALHA NAVAL \n");

    printf("   "); // Espaço para alinhar com as letras
    for(int i = 0; i < LINHA; i++) {
        printf("%d ", linha[i]); // Coloca as letras no terminal
    }
    printf("\n");
    printf("\n");
    for(int i = 0; i < LINHA; i++) {
        printf("%d ", i); // Imprime número da linha
        (i < LINHA) ? printf(" ") : 0; // alinha última coluna

        for(int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}