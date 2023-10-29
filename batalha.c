//Desenvolvido por Leonardo Borges Lopes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

int main(){
    int matrizlateral[TAM][1], i, j, contador = 0;
    char matrizsuperior[1][21] = {' ', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
    char matrizjogo[TAM][TAM];
    srand(time(NULL));

    for(i=0;i<TAM;i++){ //Preenchendo matriz jogo
        for(j=0;j<TAM;j++){
            matrizjogo[i][j]='*';
        }
    }

    while(contador<10){ //Posicionando as boias
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(matrizjogo[i][j] == '*'){
            matrizjogo[i][j] = '0'; //Posicionando o identificador
            contador++;
        }
    }
    
    if(contador == 10){ //Verificando a quantidade
        contador=0;
    }
    
    while(contador<5){ //Posicionando os aviões
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(0<i && j<19 && 0<=j && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j+1] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i+1][j+1] == '*'){ //Verificando se é possível colocar virado para a direita
            matrizjogo[i][j] = '1';
            matrizjogo[i-1][j+1] = '1';
            matrizjogo[i][j+1] = '1';
            matrizjogo[i+1][j+1] = '1';
            contador++;
        }else if(i>0 && i<=19 && 0<j && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j-1] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i-1][j+1] == '*'){ //Verificando se é possível colocar virado para cima
            matrizjogo[i][j] = '1';
            matrizjogo[i-1][j-1] = '1';
            matrizjogo[i-1][j] = '1';
            matrizjogo[i-1][j+1] = '1';
            contador++;
        }else if(0<i && i<19 && 19>=j && j>0 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j-1] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i+1][j-1] == '*'){ //Verificando se é possível colocar virado para a esquerda
            matrizjogo[i][j] = '1';
            matrizjogo[i-1][j-1] = '1';
            matrizjogo[i][j-1] = '1';
            matrizjogo[i+1][j-1] = '1';
            contador++;
        }else if(0<=i && i<19 && 19>j && j>0 && matrizjogo[i][j] == '*' && matrizjogo[i+1][j-1] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+1][j+1] == '*'){ //Verificando se é possível colocar virado para baixo
            matrizjogo[i][j] = '1';
            matrizjogo[i+1][j-1] = '1';
            matrizjogo[i+1][j] = '1';
            matrizjogo[i+1][j+1] = '1';
            contador++;
        }
    }
    
    if(contador == 5){ //Verificando a quantidade
        contador=0;
    }

    while(contador<5){ //Posicionando os submarinos
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(j<17 && matrizjogo[i][j] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i][j+2] == '*' && matrizjogo[i][j+3] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            matrizjogo[i][j] = '2';
            matrizjogo[i][j+1] = '2';
            matrizjogo[i][j+2] = '2';
            matrizjogo[i][j+3] = '2';
            contador++;
        }else if(i>2 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i-2][j] == '*' && matrizjogo[i-3][j] == '*'){ //Verificando se é possível colocar na vertical para cima
            matrizjogo[i][j] = '2';
            matrizjogo[i+1][j] = '2';
            matrizjogo[i+2][j] = '2';
            matrizjogo[i+3][j] = '2';
            contador++;
        }else if(2<j && matrizjogo[i][j] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i][j-2] == '*' && matrizjogo[i][j-3] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            matrizjogo[i][j] = '2';
            matrizjogo[i][j-1] = '2';
            matrizjogo[i][j-2] = '2';
            matrizjogo[i][j-3] = '2';
            contador++;
        }else if(i<17 && matrizjogo[i][j] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+2][j] == '*' && matrizjogo[i+3][j] == '*'){ //Verificando se é possível colocar na vertical para baixo
            matrizjogo[i][j] = '2';
            matrizjogo[i+1][j] = '2';
            matrizjogo[i+2][j] = '2';
            matrizjogo[i+3][j] = '2';
            contador++;
        }
    }
    
    if(contador == 5){ //Verificando a quantidade
        contador=0;
    }

    while(contador<4){ //Posicionando os espiões 1
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(i>0 && i<19 && j<17 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i][j+2] == '*' && matrizjogo[i][j+3] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            matrizjogo[i][j] = '3';
            matrizjogo[i+1][j] = '3';
            matrizjogo[i-1][j] = '3';
            matrizjogo[i][j+1] = '3';
            matrizjogo[i][j+2] = '3';
            matrizjogo[i][j+3] = '3';
            contador++;
        }else if(i>2 && j>0 && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i][j-1] == '*'  && matrizjogo[i][j+1] == '*'  && matrizjogo[i-1][j] == '*' && matrizjogo[i-2][j] == '*' && matrizjogo[i-3][j] == '*'){ //Verificando se é possível colocar na vertical para cima
            matrizjogo[i][j] = '3';
            matrizjogo[i][j-1] = '3';
            matrizjogo[i][j+1] = '3';
            matrizjogo[i-1][j] = '3';
            matrizjogo[i-2][j] = '3';
            matrizjogo[i-3][j] = '3';
            contador++;
        }else if(i>0 && 2<j && matrizjogo[i][j] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i][j-2] == '*' && matrizjogo[i][j-3] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            matrizjogo[i][j] = '3';
            matrizjogo[i-1][j] = '3';
            matrizjogo[i+1][j] = '3';
            matrizjogo[i][j-1] = '3';
            matrizjogo[i][j-2] = '3';
            matrizjogo[i][j-3] = '3';
            contador++;
        }else if(i<17 && j>0 && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+2][j] == '*' && matrizjogo[i+3][j] == '*'){ //Verificando se é possível colocar na vertical para baixo
            matrizjogo[i][j] = '3';
            matrizjogo[i][j-1] = '3';
            matrizjogo[i][j+1] = '3';
            matrizjogo[i+1][j] = '3';
            matrizjogo[i+2][j] = '3';
            matrizjogo[i+3][j] = '3';
            contador++;
        }
    }
    
    if(contador == 4){ //Verificando a quantidade
        contador=0;
    }

    while(contador<4){ //Posicionando os espiões 2 
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(i>0 && i<19 && j<17 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i][j+2] == '*' && matrizjogo[i][j+3] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            matrizjogo[i][j] = '4';
            matrizjogo[i+1][j] = '4';
            matrizjogo[i-1][j] = '4';
            matrizjogo[i][j+1] = '4';
            matrizjogo[i][j+2] = '4';
            matrizjogo[i][j+3] = '4';
            contador++;
        }else if(i>2 && j>0 && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i][j-1] == '*'  && matrizjogo[i][j+1] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i-2][j] == '*' && matrizjogo[i-3][j] == '*'){ //Verificando se é possível colocar na vertical para cima
            matrizjogo[i][j] = '4';
            matrizjogo[i][j-1] = '4';
            matrizjogo[i][j+1] = '4';
            matrizjogo[i-1][j] = '4';
            matrizjogo[i-2][j] = '4';
            matrizjogo[i-3][j] = '4';
            contador++;
        }else if(i>0 && 2<j && matrizjogo[i][j] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i][j-2] == '*' && matrizjogo[i][j-3] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            matrizjogo[i][j] = '4';
            matrizjogo[i-1][j] = '4';
            matrizjogo[i+1][j] = '4';
            matrizjogo[i][j-1] = '4';
            matrizjogo[i][j-2] = '4';
            matrizjogo[i][j-3] = '4';
            contador++;
        }else if(i<17 && j>0 && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+2][j] == '*' && matrizjogo[i+3][j] == '*'){ //Verificando se é possível colocar na vertical para baixo
            matrizjogo[i][j] = '4';
            matrizjogo[i][j-1] = '4';
            matrizjogo[i][j+1] = '4';
            matrizjogo[i+1][j] = '4';
            matrizjogo[i+2][j] = '4';
            matrizjogo[i+3][j] = '4';
            contador++;
        }
    }
    
    if(contador == 4){ //Verificando a quantidade
            contador=0;
        }

    while(contador<2){ //Posicionando os porta aviões
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(i<19 && j<16 && matrizjogo[i][j] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i][j+2] == '*' && matrizjogo[i][j+3] == '*' && matrizjogo[i][j+4] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+1][j+1] == '*' && matrizjogo[i+1][j+2] == '*' && matrizjogo[i+1][j+3] == '*' && matrizjogo[i+1][j+4] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            matrizjogo[i][j] = '5';
            matrizjogo[i][j+1] = '5';
            matrizjogo[i][j+2] = '5';
            matrizjogo[i][j+3] = '5';
            matrizjogo[i][j+4] = '5';
            matrizjogo[i+1][j] = '5';
            matrizjogo[i+1][j+1] = '5';
            matrizjogo[i+1][j+2] = '5';
            matrizjogo[i+1][j+3] = '5';
            matrizjogo[i+1][j+4] = '5';
            contador++;
        }else if(i>3 && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i-1][j] == '*' && matrizjogo[i-2][j] == '*' && matrizjogo[i-3][j] == '*' && matrizjogo[i-4][j] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i-1][j+1] == '*' && matrizjogo[i-2][j+1] == '*' && matrizjogo[i-3][j+1] == '*' && matrizjogo[i-4][j+1] == '*'){ //Verificando se é possível colocar na vertical para cima
            matrizjogo[i][j] = '5';
            matrizjogo[i-1][j] = '5';
            matrizjogo[i-2][j] = '5';
            matrizjogo[i-3][j] = '5';
            matrizjogo[i-4][j] = '5';
            matrizjogo[i][j+1] = '5';
            matrizjogo[i-1][j+1] = '5';
            matrizjogo[i-2][j+1] = '5';
            matrizjogo[i-3][j+1] = '5';
            matrizjogo[i-4][j+1] = '5';
            contador++;
        }else if(i<19 && j>3 && matrizjogo[i][j] == '*' && matrizjogo[i][j-1] == '*' && matrizjogo[i][j-2] == '*' && matrizjogo[i][j-3] == '*' && matrizjogo[i][j-4] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+1][j-1] == '*' && matrizjogo[i+1][j-2] == '*' && matrizjogo[i+1][j+-3] == '*' && matrizjogo[i+1][j-4] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            matrizjogo[i][j] = '5';
            matrizjogo[i][j-1] = '5';
            matrizjogo[i][j-2] = '5';
            matrizjogo[i][j-3] = '5';
            matrizjogo[i][j-4] = '5';
            matrizjogo[i+1][j] = '5';
            matrizjogo[i+1][j-1] = '5';
            matrizjogo[i+1][j-2] = '5';
            matrizjogo[i+1][j-3] = '5';
            matrizjogo[i+1][j-4] = '5';
            contador++;
        }else if(i<16 && j<19 && matrizjogo[i][j] == '*' && matrizjogo[i+1][j] == '*' && matrizjogo[i+2][j] == '*' && matrizjogo[i+3][j] == '*' && matrizjogo[i+4][j] == '*' && matrizjogo[i][j+1] == '*' && matrizjogo[i+1][j+1] == '*' && matrizjogo[i+2][j+1] == '*' && matrizjogo[i+3][j+1] == '*' && matrizjogo[i+4][j+1] == '*'){ //Verificando se é possível colocar na vertical para baixo
            matrizjogo[i][j] = '5';
            matrizjogo[i+1][j] = '5';
            matrizjogo[i+2][j] = '5';
            matrizjogo[i+3][j] = '5';
            matrizjogo[i+4][j] = '5';
            matrizjogo[i][j+1] = '5';
            matrizjogo[i+1][j+1] = '5';
            matrizjogo[i+2][j+1] = '5';
            matrizjogo[i+3][j+1] = '5';
            matrizjogo[i+4][j+1] = '5';
            contador++;
        }
    }
    
    if(contador == 2){ //Verificando a quantidade
        contador=0;
    }

    for(i=0;i<21;i++){ //Loop para imprimir matriz preenchida
        for(j=0;j<21;j++){
            if(i==0){
                printf("%c\t", matrizsuperior[0][j]); //Imprimindo as letras
            } else if(i!=0 && j==0){
                matrizlateral[i][0]=contador;
                contador++;
                printf("%d\t", matrizlateral[i][j]); //Imprimindo os números na lateral
             } else{
                printf("%c\t", matrizjogo[i-1][j-1]); //Imprimindo a matriz jogo
             }
        }
        printf("\n");
    }

    return 0;
}