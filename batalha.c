//Desenvolvido por Leonardo Borges Lopes 2606267

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

FILE * openFile(char *nome_arquivo){
    FILE * arquivo = fopen(nome_arquivo, "a+");
    if(arquivo != NULL){
        return arquivo;
    }else{
        printf("Não foi possível abrir o arquivo\n\n");
        return NULL;
    }
} 

void salvar_tabuleiro1(char *nome_arquivo, int linha, int coluna, char direcao, char identificador){
    FILE * arquivo = fopen(nome_arquivo, "a"); //Abrindo o arquivo .txt
    fprintf(arquivo, "%d %d %c %c\n", linha, coluna, direcao, identificador); //Escrevendo as informações do objeto
    fclose(arquivo);
}

void preencher_matriz(char matriz[][TAM]){ //Função preencher a matriz jogo
    int i, j;
    printf("Preenchendo matriz\n\n");
    for(i=0;i<TAM;i++){ 
        for(j=0;j<TAM;j++){
            matriz[i][j]='*';
        }
    }
}

void printar_matriz(char matriz[][TAM], int lateral[][1], char superior[][21]){ //Função preencher a matriz jogo
    int i, j, contador=0;
    printf("\n");
    for(i=0;i<21;i++){ //Loop para imprimir matriz preenchida
        for(j=0;j<21;j++){
            if(i==0){
                printf("%c\t", superior[0][j]); //Imprimindo as letras
            } else if(i!=0 && j==0){
                lateral[i][0]=contador;
                contador++;
                printf("%d\t", lateral[i][j]); //Imprimindo os números na lateral
             } else{
                printf("%c\t", matriz[i-1][j-1]); //Imprimindo a matriz jogo
             }
        }
        printf("\n");
    }  
}

void boias(char matriz[][TAM], int i, int j){
    matriz[i][j] = '0'; //Posicionando o identificador
}

void avioes(char matriz[][TAM], int i, int j, char direcao){
    if(direcao == 'D'){ //Verificando a direção
        matriz[i][j] = '1';
        matriz[i-1][j+1] = '1';
        matriz[i][j+1] = '1';
        matriz[i+1][j+1] = '1';
    }else if(direcao == 'C'){ //Verificando a direção
        matriz[i][j] = '1';
        matriz[i-1][j-1] = '1';
        matriz[i-1][j] = '1';
        matriz[i-1][j+1] = '1';
    }else if(direcao == 'E'){ //Verificando a direção
        direcao = 'E';
        matriz[i][j] = '1';
        matriz[i-1][j-1] = '1';
        matriz[i][j-1] = '1';
        matriz[i+1][j-1] = '1';
    }else if(direcao == 'B'){ //Verificando a direção
        direcao = 'B';
        matriz[i][j] = '1';
        matriz[i+1][j-1] = '1';
        matriz[i+1][j] = '1';
        matriz[i+1][j+1] = '1';
    }
}

void submarinos(char matriz[][TAM], int i, int j, char direcao){
    if(direcao == 'D'){ //Verificando a direção
        matriz[i][j] = '2';
        matriz[i][j+1] = '2';
        matriz[i][j+2] = '2';
        matriz[i][j+3] = '2';
    }else if(direcao == 'C'){ //Verificando a direção
        matriz[i][j] = '2';
        matriz[i-1][j] = '2';
        matriz[i-2][j] = '2';
        matriz[i-3][j] = '2';
    }else if(direcao == 'E'){ //Verificando a direção
        matriz[i][j] = '2';
        matriz[i][j-1] = '2';
        matriz[i][j-2] = '2';
        matriz[i][j-3] = '2';
    }else if(direcao == 'B'){ //Verificando a direção
        matriz[i][j] = '2';
        matriz[i+1][j] = '2';
        matriz[i+2][j] = '2';
        matriz[i+3][j] = '2';
    }
}

void espioes1(char matriz[][TAM], int i, int j, char direcao){
    if(direcao == 'D'){ //Verificando a direção
        matriz[i][j] = '3';
        matriz[i+1][j] = '3';
        matriz[i-1][j] = '3';
        matriz[i][j+1] = '3';
        matriz[i][j+2] = '3';
        matriz[i][j+3] = '3';
    }else if(direcao == 'C'){ //Verificando a direção
        matriz[i][j] = '3';
        matriz[i][j-1] = '3';
        matriz[i][j+1] = '3';
        matriz[i-1][j] = '3';
        matriz[i-2][j] = '3';
        matriz[i-3][j] = '3';
    }else if(direcao == 'E'){ //Verificando a direção
        matriz[i][j] = '3';
        matriz[i-1][j] = '3';
        matriz[i+1][j] = '3';
        matriz[i][j-1] = '3';
        matriz[i][j-2] = '3';
        matriz[i][j-3] = '3';
    }else if(direcao == 'B'){ //Verificando a direção
        matriz[i][j] = '3';
        matriz[i][j-1] = '3';
        matriz[i][j+1] = '3';
        matriz[i+1][j] = '3';
        matriz[i+2][j] = '3';
        matriz[i+3][j] = '3';
    }
}

void espioes2(char matriz[][TAM], int i, int j, char direcao){
    if(direcao == 'D'){ //Verificando a direção
        matriz[i][j] = '4';
        matriz[i+1][j] = '4';
        matriz[i-1][j] = '4';
        matriz[i][j+1] = '4';
        matriz[i][j+2] = '4';
        matriz[i][j+3] = '4';
    }else if(direcao == 'C'){ //Verificando a direção
        matriz[i][j] = '4';
        matriz[i][j-1] = '4';
        matriz[i][j+1] = '4';
        matriz[i-1][j] = '4';
        matriz[i-2][j] = '4';
        matriz[i-3][j] = '4';
    }else if(direcao == 'E'){ //Verificando a direção
        matriz[i][j] = '4';
        matriz[i-1][j] = '4';
        matriz[i+1][j] = '4';
        matriz[i][j-1] = '4';
        matriz[i][j-2] = '4';
        matriz[i][j-3] = '4';
    }else if(direcao == 'B'){ //Verificando a direção
        matriz[i][j] = '4';
        matriz[i][j-1] = '4';
        matriz[i][j+1] = '4';
        matriz[i+1][j] = '4';
        matriz[i+2][j] = '4';
        matriz[i+3][j] = '4';
    }
}

void portaAvioes(char matriz[][TAM], int i, int j, char direcao){
    if(direcao == 'D'){ //Verificando a direção
        matriz[i][j] = '5';
        matriz[i][j+1] = '5';
        matriz[i][j+2] = '5';
        matriz[i][j+3] = '5';
        matriz[i][j+4] = '5';
        matriz[i+1][j] = '5';
        matriz[i+1][j+1] = '5';
        matriz[i+1][j+2] = '5';
        matriz[i+1][j+3] = '5';
        matriz[i+1][j+4] = '5';
    }else if(direcao == 'C'){ //Verificando a direção
        matriz[i][j] = '5';
        matriz[i-1][j] = '5';
        matriz[i-2][j] = '5';
        matriz[i-3][j] = '5';
        matriz[i-4][j] = '5';
        matriz[i][j+1] = '5';
        matriz[i-1][j+1] = '5';
        matriz[i-2][j+1] = '5';
        matriz[i-3][j+1] = '5';
        matriz[i-4][j+1] = '5';
    }else if(direcao == 'E'){ //Verificando a direção
        matriz[i][j] = '5';
        matriz[i][j-1] = '5';
        matriz[i][j-2] = '5';
        matriz[i][j-3] = '5';
        matriz[i][j-4] = '5';
        matriz[i+1][j] = '5';
        matriz[i+1][j-1] = '5';
        matriz[i+1][j-2] = '5';
        matriz[i+1][j-3] = '5';
        matriz[i+1][j-4] = '5';
    }else if(direcao == 'B'){ //Verificando a direção
        matriz[i][j] = '5';
        matriz[i+1][j] = '5';
        matriz[i+2][j] = '5';
        matriz[i+3][j] = '5';
        matriz[i+4][j] = '5';
        matriz[i][j+1] = '5';
        matriz[i+1][j+1] = '5';
        matriz[i+2][j+1] = '5';
        matriz[i+3][j+1] = '5';
        matriz[i+4][j+1] = '5';
    }
}

int tiros(int i, int j, char leitura[][TAM], char jogo[][TAM], int lateral[][1], char superior[][21], int contador, int jogada){
    if(jogo[i][j] == '*'){
        if(leitura[i][j] == '0'){
            jogo[i][j] = '0';
            contador++;
        }else if(leitura[i][j] == '1'){
            jogo[i][j] = '1';
            contador++;
        }else if(leitura[i][j] == '2'){
            jogo[i][j] = '2';
            contador++;
        }else if(leitura[i][j] == '3'){
            jogo[i][j] = '3';
            contador++;
        }else if(leitura[i][j] == '4'){
            jogo[i][j] = '4';
            contador++;
        }else if(leitura[i][j] == '5'){
            jogo[i][j] = '5';
            contador++;
        }else{
            jogo[i][j] = '#';
        }
        printf("\nLinha: %d, Coluna: %d", i, j);
        printar_matriz(jogo, lateral, superior);
    }
    return contador;
}

int main(){
    int matrizlateral[TAM][1], i, j, contador = 0, completo = 0, linha2, coluna2, m, n, contadorboia = 0, contadoraviao = 0, contadorsub=0, contadorespiao1=0, contadorespiao2=0, jogada = 0, contadorporta=0, sair=0, contador2=0, meio = 0, total = 0;
    char matrizsuperior[1][21] = {' ', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
    char matriz_gabarito[TAM][TAM], matriz_leitura[TAM][TAM], matriz_jogo[TAM][TAM], direcao, direcao2, identificador2;
    srand(time(NULL));

    FILE * arquivo = openFile("tabuleiro.txt");

    preencher_matriz(matriz_gabarito);

    while(contador<10){ //Posicionando as boias
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(matriz_gabarito[i][j] == '*'){
            boias(matriz_gabarito, i, j);
        }
        salvar_tabuleiro1("tabuleiro.txt", i, j, '-', '0');
        contador++;
    }
    
    contador=0;
    
    while(contador<5){ //Posicionando os aviões
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(0<i && j<19 && 0<=j && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j+1] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i+1][j+1] == '*'){ //Verificando se é possível colocar virado para a direita
            direcao = 'D';
            avioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, direcao, '1');
            contador++;
        }else if(i>0 && i<=19 && 0<j && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j-1] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i-1][j+1] == '*'){ //Verificando se é possível colocar virado para cima
            direcao = 'C';
            avioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, direcao, '1');
            contador++;
        }else if(0<i && i<19 && 19>=j && j>0 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j-1] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i+1][j-1] == '*'){ //Verificando se é possível colocar virado para a esquerda
            direcao = 'E';
            avioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, direcao, '1');
            contador++;
        }else if(0<=i && i<19 && 19>j && j>0 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i+1][j-1] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+1][j+1] == '*'){ //Verificando se é possível colocar virado para baixo
            direcao = 'B';
            avioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, direcao, '1');
            contador++;
        }
    }
    contador = 0;

    while(contador<5){ //Posicionando os submarinos
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(j<17 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i][j+2] == '*' && matriz_gabarito[i][j+3] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            direcao = 'D';
            submarinos(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'D', '2');
            contador++;
        }else if(i>2 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i-2][j] == '*' && matriz_gabarito[i-3][j] == '*'){ //Verificando se é possível colocar na vertical para cima
            direcao = 'C';
            submarinos(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'C', '2');
            contador++;
        }else if(2<j && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i][j-2] == '*' && matriz_gabarito[i][j-3] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            direcao = 'E';
            submarinos(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'E', '2');
            contador++;
        }else if(i<17 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+2][j] == '*' && matriz_gabarito[i+3][j] == '*'){ //Verificando se é possível colocar na vertical para baixo
            direcao = 'B';
            submarinos(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, direcao, '2');
            contador++;
        }
    }

    contador=0;

    while(contador<4){ //Posicionando os espiões 1
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(i>0 && i<19 && j<17 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i][j+2] == '*' && matriz_gabarito[i][j+3] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            direcao = 'D';
            espioes1(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'D', '3');
            contador++;
        }else if(i>2 && j>0 && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j-1] == '*'  && matriz_gabarito[i][j+1] == '*'  && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i-2][j] == '*' && matriz_gabarito[i-3][j] == '*'){ //Verificando se é possível colocar na vertical para cima
            direcao = 'C';
            espioes1(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'C', '3');
            contador++;
        }else if(i>0 && 2<j && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i][j-2] == '*' && matriz_gabarito[i][j-3] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            direcao = 'E';
            espioes1(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'E', '3');
            contador++;
        }else if(i<17 && j>0 && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+2][j] == '*' && matriz_gabarito[i+3][j] == '*'){ //Verificando se é possível colocar na vertical para baixo
            direcao = 'B';
            espioes1(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'B', '3');
            contador++;
        }
    }
    
    contador=0;
    
    while(contador<4){ //Posicionando os espiões 2 
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(i>0 && i<19 && j<17 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i][j+2] == '*' && matriz_gabarito[i][j+3] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            direcao = 'D';
            espioes2(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'D', '4');
            contador++;
        }else if(i>2 && j>0 && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j-1] == '*'  && matriz_gabarito[i][j+1] == '*'  && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i-2][j] == '*' && matriz_gabarito[i-3][j] == '*'){ //Verificando se é possível colocar na vertical para cima
            direcao = 'C';
            espioes2(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'C', '4');
            contador++;
        }else if(i>0 && 2<j && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i][j-2] == '*' && matriz_gabarito[i][j-3] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            direcao = 'E';
            espioes2(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'E', '4');
            contador++;
        }else if(i<17 && j>0 && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+2][j] == '*' && matriz_gabarito[i+3][j] == '*'){ //Verificando se é possível colocar na vertical para baixo
            direcao = 'B';
            espioes2(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'B', '4');
            contador++;
        }
    }
    
    contador=0;

    while(contador<2){ //Posicionando os porta aviões
        i=rand()%20; //Sorteando a linha
        j=rand()%20; //Sorteando a coluna
        if(i<19 && j<16 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i][j+2] == '*' && matriz_gabarito[i][j+3] == '*' && matriz_gabarito[i][j+4] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+1][j+1] == '*' && matriz_gabarito[i+1][j+2] == '*' && matriz_gabarito[i+1][j+3] == '*' && matriz_gabarito[i+1][j+4] == '*'){ //Verificando se é possível colocar na horizontal para a direita
            direcao = 'D';
            portaAvioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'D', '5');
            contador++;
        }else if(i>3 && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i-1][j] == '*' && matriz_gabarito[i-2][j] == '*' && matriz_gabarito[i-3][j] == '*' && matriz_gabarito[i-4][j] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i-1][j+1] == '*' && matriz_gabarito[i-2][j+1] == '*' && matriz_gabarito[i-3][j+1] == '*' && matriz_gabarito[i-4][j+1] == '*'){ //Verificando se é possível colocar na vertical para cima
            direcao = 'C';
            portaAvioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'C', '5');
            contador++;
        }else if(i<19 && j>3 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i][j-1] == '*' && matriz_gabarito[i][j-2] == '*' && matriz_gabarito[i][j-3] == '*' && matriz_gabarito[i][j-4] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+1][j-1] == '*' && matriz_gabarito[i+1][j-2] == '*' && matriz_gabarito[i+1][j+-3] == '*' && matriz_gabarito[i+1][j-4] == '*'){ //Verificando se é possível colocar na horizontal para a esquerda
            direcao = 'E';
            portaAvioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'E', '5');
            contador++;
        }else if(i<16 && j<19 && matriz_gabarito[i][j] == '*' && matriz_gabarito[i+1][j] == '*' && matriz_gabarito[i+2][j] == '*' && matriz_gabarito[i+3][j] == '*' && matriz_gabarito[i+4][j] == '*' && matriz_gabarito[i][j+1] == '*' && matriz_gabarito[i+1][j+1] == '*' && matriz_gabarito[i+2][j+1] == '*' && matriz_gabarito[i+3][j+1] == '*' && matriz_gabarito[i+4][j+1] == '*'){ //Verificando se é possível colocar na vertical para baixo
            direcao = 'B';
            portaAvioes(matriz_gabarito, i, j, direcao);
            salvar_tabuleiro1("tabuleiro.txt", i, j, 'B', '5');
            contador++;
        }
    } 

    preencher_matriz(matriz_leitura);
    preencher_matriz(matriz_jogo);

    while(fscanf(arquivo, "%d %d %c %c", &linha2, &coluna2, &direcao2, &identificador2) != EOF){
        if(identificador2 == '0'){
            boias(matriz_leitura, linha2, coluna2);
        }else if(identificador2 == '1'){
            avioes(matriz_leitura, linha2, coluna2, direcao2);
        }else if(identificador2 == '2'){
            submarinos(matriz_leitura, linha2, coluna2, direcao2);
        }else if(identificador2 == '3'){
            espioes1(matriz_leitura, linha2, coluna2, direcao2);
        }else if(identificador2 == '4'){
            espioes2(matriz_leitura, linha2, coluna2, direcao2);
        }else if(identificador2 == '5'){
            portaAvioes(matriz_leitura, linha2, coluna2, direcao2);
        }
    }
    
    fclose(arquivo);

    contador = 0;

    i=rand()%20; //Sorteando a linha
    j=rand()%20; //Sorteando a coluna

    while(sair == 0){
        contador=0;
        if(matriz_jogo[i][j] == '*'){
            jogada++;
            printf("\nJogada: %d\n", jogada);
            tiros(i, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorsub, jogada);
            if(matriz_jogo[i][j]=='0'){
                contadorboia++;
            }else if(matriz_jogo[i][j]=='1'){
                direcao = 'D'; //Definindo direcao da verificação padrão
                contador++;;
                contadoraviao++;
                n=j+1;
                while(n<=19 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n-1] == '1' && contador < 3){ //Verificar para a direita
                    jogada++;
                    printf("\nJogada: %d\n", jogada);
                    contadoraviao = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada);
                    if (matriz_jogo[i][n] == '1'){
                        contador++;
                    }
                    n++;
                }
                if(contador == 3){ //Atualizar a casa do meio
                    meio = n-2;
                }
                n=j-1;
                if(contador >= 0 && contador < 3){ //Verificando para a esquerda
                    while(n>=0 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n+1] == '1' && contador < 3){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadoraviao = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada);
                        if(matriz_jogo[i][n] == '1'){
                            contador++;
                            n--;
                        }
                    }
                    if(contador == 3){ //Atualizar a casa do meio
                        meio = n+2;
                    }
                }
                if(contador == 3){ //Verificar as casas acima e abaixo se necessário
                    if(matriz_jogo[i-1][meio] != '1' && matriz_jogo[i+1][meio] != '1'){
                        if(i-1>=0 && matriz_jogo[i-1][meio] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i-1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada);
                        }
                        if(matriz_jogo[i-1][meio] != '1' && matriz_jogo[i+1][meio] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);                          
                            contadoraviao = tiros(i+1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada);
                        }
                    }
                } 
                if(contador == 1){ //Ponta do aviao
                    if(matriz_jogo[i-1][j] == '*'){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadoraviao = tiros(i-1, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar uma casa acima
                    }
                    if(matriz_jogo[i-1][j] == '1'){
                        if(matriz_jogo[i-1][j+1] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i-1, j+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar na diagonal superior direita
                        }
                        if(matriz_jogo[i-1][j-1] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i-1, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar na diagonal superior esquerda
                        }
                        if(matriz_jogo[i-1][j+1] != '1' || matriz_jogo[i-1][j-1] != '1'){
                            if(matriz_jogo[i-2][j] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadoraviao = tiros(i-2, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar duas casas acima
                            }
                        }
                    }else{
                        if(matriz_jogo[i+1][j] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i+1, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar uma casa abaixo
                        }
                        if(matriz_jogo[i+1][j+1] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i+1, j+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar na diagonal inferior direita
                        }
                        if(matriz_jogo[i+1][j-1] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i+1, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar na diagonal inferior esquerda
                        }
                        if(matriz_jogo[i+1][j+1] != '1' || matriz_jogo[i+1][j-1] != '1'){
                            if(matriz_jogo[i+2][j] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadoraviao = tiros(i+2, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar duas casas abaixo
                            }
                        }
                    }
                }
                if(contador == 2){
                    if(matriz_jogo[i-1][n+1] == '*'){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadoraviao = tiros(i-1, n+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar duas casas abaixo
                        if(matriz_jogo[i-1][n+1] == '1'){
                            if(matriz_jogo[i+1][n+1] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadoraviao = tiros(i+1, n+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar duas casas abaixo
                                contador++;
                            }
                        }
                    }
                    if(contador < 3){
                        if(matriz_jogo[i-1][n+2] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i-1, n+2, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar duas casas abaixo
                        }
                        if(matriz_jogo[i+1][n+2] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadoraviao = tiros(i+1, n+2, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadoraviao, jogada); //Verificar duas casas abaixo
                        }
                       
                    }
                }
                contador = 0;
            }else if(matriz_jogo[i][j] == '2'){
                n=j+1;
                contadorsub++; //Incrementar um porque a primeira vez que a função é chamada o valor retornado não é salvo
                contador++; //Incrementar um porque a primeira vez que a função é chamada o valor retornado não é salvo
                while(n<=19 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n-1] == '2' && contador < 4){ //Verificando para a direita
                    jogada++;
                    printf("\nJogada: %d\n", jogada);
                    contadorsub = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorsub, jogada);
                    if(matriz_jogo[i][n] == '2'){
                        contador++;
                    }
                    n++;
                }
                n=j-1;
                if(contador >= 0 && contador < 4){ //Verificando para a esquerda
                    while(n>=0 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n+1] == '2' && contador < 4){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorsub = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorsub, jogada);
                        if(matriz_jogo[i][n] == '2'){
                            contador++;
                        }
                        n--;
                    }
                }
                if(contador != 0){
                    m=i+1;
                    while(m<=19 && matriz_jogo[m][j] == '*' && matriz_jogo[m-1][j] == '2' && contador < 4){ //Verificando para baixo
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorsub = tiros(m, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorsub, jogada);
                        if(matriz_jogo[m][j] == '2'){
                            contador++;
                        }
                        m++;
                    }
                }
                m=i-1;
                if(contador > 0 && contador < 4){ //Verificando para cima
                    while(m>=0 && matriz_jogo[m][j] == '*' && matriz_jogo[m+1][j] == '2' && contador < 4){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorsub = tiros(m, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorsub, jogada);
                        if(matriz_jogo[m][j] == '2'){
                            contador++;
                        }
                        m--;
                    }
                }
                contador = 0;
            }else if(matriz_jogo[i][j] == '3'){
                n=j+1;
                direcao = 'D';
                contadorespiao1++; //Incrementar um porque a primeira vez que a função é chamada o valor retornado não é salvo
                contador++; //Incrementar um porque a primeira vez que a função é chamada o valor retornado não é salvo
                while(n<=19 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n-1] == '3' && contador < 4){ //Verificando para a direita
                    jogada++;
                    printf("\nJogada: %d\n", jogada);
                    contadorespiao1 = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                    if(matriz_jogo[i][n] == '3'){
                        contador++;
                    }
                    n++;
                }
                if(contador == 4){ //Atualizar a casa da ponta
                    meio = n-1;
                }
                n=j-1;
                if(contador >= 0 && contador < 4){ //Verificando para a esquerda
                    while(n>=0 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n+1] == '3' && contador < 4){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorespiao1 = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                        if(matriz_jogo[i][n] == '3'){
                            contador++;
                        }
                        n--;
                    }
                    if(contador == 4){ //Atualizar a casa da ponta
                        meio = n+1;
                        direcao = 'E';
                    }
                }
                if(contador == 4){ //Verificar as casas acima e abaixo se necessário 
                    if(direcao == 'D'){
                        if(i-1>=0 && matriz_jogo[i-1][meio] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(i-1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                        }
                        if(matriz_jogo[i-1][meio] == '3' && matriz_jogo[i+1][meio] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(i+1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            if(matriz_jogo[i-1][meio] != '3' || matriz_jogo[i+1][meio] != '3'){
                                if(matriz_jogo[i-1][meio-3] == '*' && matriz_jogo[i-1][meio] != '3' && matriz_jogo[i+1][meio] != '3'){ //Verifica as casas na ponta contrária
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(i-1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                    if(matriz_jogo[i-1][meio-3] == '3' && matriz_jogo[i+1][meio-3] == '*'){
                                        jogada++;
                                        printf("\nJogada: %d\n", jogada);
                                        contadorespiao1 = tiros(i+1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                    }
                                }
                            }
                        }
                        if(matriz_jogo[i-1][meio-3] == '*' && matriz_jogo[i-1][meio] != '3' && matriz_jogo[i+1][meio] != '3'){ //Verifica as casas na ponta contrária
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(i-1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            if(matriz_jogo[i-1][meio-3] == '3' && matriz_jogo[i+1][meio-3] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(i+1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                        }
                    }else if(direcao == 'E'){
                        if(i-1>=0 && matriz_jogo[i-1][meio] == '*'){ //Verifica a casa de cima da ponta
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(i-1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                        }
                        if(matriz_jogo[i-1][meio] == '3' && matriz_jogo[i+1][meio] == '*'){ //Verifica a casa abaixo da ponta
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(i+1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            if(matriz_jogo[i-1][meio] != '3' || matriz_jogo[i+1][meio] != '3'){
                                if(matriz_jogo[i-1][meio+3] == '*' && matriz_jogo[i-1][meio] != '3' && matriz_jogo[i+1][meio] != '3'){ //Verifica as casas na ponta contrária
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(i-1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                    if(matriz_jogo[i-1][meio+3] == '3' && matriz_jogo[i+1][meio+3] == '*'){
                                        jogada++;
                                        printf("\nJogada: %d\n", jogada);
                                        contadorespiao1 = tiros(i+1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                    }
                                }
                            }
                        }
                        if(matriz_jogo[i-1][meio+3] == '*' && matriz_jogo[i-1][meio] != '3' && matriz_jogo[i+1][meio] != '3'){ //Verifica as casas na ponta contrária
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(i-1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            if(matriz_jogo[i-1][meio+3] == '3' && matriz_jogo[i+1][meio+3] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(i+1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                        }
                    }
                }
                if(contador == 3){
                    m=i;
                    n+=3;
                    if(m>2){
                        if(matriz_jogo[m-1][n] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(m-1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                        }
                        if(matriz_jogo[m-1][n] == '3'){
                            if(matriz_jogo[m-2][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m-2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                            if(matriz_jogo[m-3][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m-3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                        }
                    }
                    if(m<17 && matriz_jogo[m-1][n] != '3'){
                        m+=3;
                        if(matriz_jogo[m-1][n] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(m+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                        }
                        if(matriz_jogo[m+1][n] == '3'){
                            if(matriz_jogo[m+2][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m+2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                            if(matriz_jogo[m+3][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m+3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                        }
                    }
                }
                m=i-1;
                if(contador == 1 || contador == 2){ //Uma das pontas laterais
                    while(m>=0 && matriz_jogo[m][j] == '*' && matriz_jogo[m+1][j] == '3' && contador < 3){ //Verificando para cima
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorespiao1 = tiros(m, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                        if(matriz_jogo[m][j] == '3'){
                            contador++;
                        }
                        m--;
                    }
                    if(contador==3){ //Verificar para a direita ou para a esquerda
                        m+=2;
                        n=j+1;
                        contador=0;
                        while(n<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n-1] == '3' && contador < 3){ //Verificando para a direita
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            if(matriz_jogo[m][n] == '3'){
                                contador++;
                            }
                            n++;
                        }
                        if(contador == 0){
                            n=j-1;
                            while(n>=0 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n+1] == '3' && contador < 3){ //Verificando para a esquerda
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                if(matriz_jogo[m][n] == '3'){
                                    contador++;
                                }
                                n--;
                            }
                        }
                        if(contador == 0){
                            if(m-2>=0){
                                if(matriz_jogo[m-2][j] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m-2, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);

                                    if(matriz_jogo[m-2][j] == '3'){
                                        if(matriz_jogo[m-2][j+1] == '*'){
                                            jogada++;
                                            printf("\nJogada: %d\n", jogada);
                                            contadorespiao1 = tiros(m-2, j+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                            if(matriz_jogo[m-2][j+1] == '3'){
                                                if(matriz_jogo[m-2][j-1] == '*'){
                                                    jogada++;
                                                    printf("\nJogada: %d\n", jogada);
                                                    contadorespiao1 = tiros(m-2, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(contador == 1 || contador == 2){
                        m=i+1;
                        while(m<=19 && matriz_jogo[m][j] == '*' && matriz_jogo[m-1][j] == '3' && contador < 3){ //Verificando para baixo
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao1 = tiros(m, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            if(matriz_jogo[m][j] == '3'){
                                contador++;
                            }
                            m++;
                        }
                        if(contador==3){ //Verificar para a direita ou para a esquerda
                            m-=2;
                            n=j+1;
                            contador=0;
                            printf("\nvalor de M: %d Valor de n: %d\n", m, n);
                            while(n<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n-1] == '3' && contador < 3){ //Verificando para a direita
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                if(matriz_jogo[m][n] == '3'){
                                    contador++;
                                }
                                n++;
                            }
                            if(contador == 0){ 
                                n=j-1;
                                while(n>=0 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n+1] == '3' && contador < 3){ //Verificando para a esquerda
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                    if(matriz_jogo[m][n] == '3'){
                                        contador++;
                                    }
                                    n--;
                                }
                            }
                            if(contador == 0){
                                if(matriz_jogo[m+2][j] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m+2, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                }
                                if(matriz_jogo[m+2][j+1] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m+2, j+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                }
                                if(matriz_jogo[m+2][j-1] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m+2, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                }
                            }
                        }
                    }
                    if(contador == 3){
                        m=i;
                        n+=3;
                        if(m>2){
                            if(matriz_jogo[m-1][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m-1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                            if(matriz_jogo[m-1][n] == '3'){
                                if(matriz_jogo[m-2][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m-2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);

                                }
                                if(matriz_jogo[m-3][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m-3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                }
                            }
                        }
                        if(m<17 && matriz_jogo[m-1][n] != '3'){
                            m+=3;
                            if(matriz_jogo[m+1][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao1 = tiros(m+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                            }
                            if(matriz_jogo[m+1][n] == '3'){
                                if(matriz_jogo[m+2][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m+2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);                              
                                }
                                if(matriz_jogo[m+3][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao1 = tiros(m+3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao1, jogada);
                                }
                            }
                        }
                    }
                }
            }else if(matriz_jogo[i][j] == '4'){
                n=j+1;
                direcao = 'D';
                contadorespiao2++; //Incrementar um porque a primeira vez que a função é chamada o valor retornado não é salvo
                contador++; //Incrementar um porque a primeira vez que a função é chamada o valor retornado não é salvo
                while(n<=19 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n-1] == '4' && contador < 4){ //Verificando para a direita
                    jogada++;
                    printf("\nJogada: %d\n", jogada);
                    contadorespiao2 = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                    if(matriz_jogo[i][n] == '4'){
                        contador++;
                    }
                    n++;
                }
                if(contador == 4){ //Atualizar a casa da ponta
                    meio = n-1;
                }
                n=j-1;
                if(contador >= 0 && contador < 4){ //Verificando para a esquerda
                    while(n>=0 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n+1] == '4' && contador < 4){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorespiao2 = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                        if(matriz_jogo[i][n] == '4'){
                            contador++;
                        }
                        n--;
                    }
                    if(contador == 4){ //Atualizar a casa da ponta
                        meio = n+1;
                        direcao = 'E';
                    }
                }
                if(contador == 4){ //Verificar as casas acima e abaixo se necessário 
                    if(direcao == 'D'){
                        if(i-1>=0 && matriz_jogo[i-1][meio] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(i-1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                        }
                        if(matriz_jogo[i-1][meio] == '4' && matriz_jogo[i+1][meio] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(i+1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            if(matriz_jogo[i-1][meio] != '4' || matriz_jogo[i+1][meio] != '4'){
                                if(matriz_jogo[i-1][meio-3] == '*' && matriz_jogo[i-1][meio] != '4' && matriz_jogo[i+1][meio] != '4'){ //Verifica as casas na ponta contrária
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(i-1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                    if(matriz_jogo[i-1][meio-3] == '4' && matriz_jogo[i+1][meio-3] == '*'){
                                        jogada++;
                                        printf("\nJogada: %d\n", jogada);
                                        contadorespiao2 = tiros(i+1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                    }
                                }
                            }
                        }
                        if(matriz_jogo[i-1][meio-3] == '*' && matriz_jogo[i-1][meio] != '4' && matriz_jogo[i+1][meio] != '4'){ //Verifica as casas na ponta contrária
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(i-1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            if(matriz_jogo[i-1][meio-3] == '4' && matriz_jogo[i+1][meio-3] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(i+1, meio-3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                        }
                    }else if(direcao == 'E'){
                        if(i-1>=0 && matriz_jogo[i-1][meio] == '*'){ //Verifica a casa de cima da ponta
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(i-1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                        }
                        if(matriz_jogo[i-1][meio] == '4' && matriz_jogo[i+1][meio] == '*'){ //Verifica a casa abaixo da ponta
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(i+1, meio, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            if(matriz_jogo[i-1][meio] != '4' || matriz_jogo[i+1][meio] != '4'){
                                if(matriz_jogo[i-1][meio+3] == '*' && matriz_jogo[i-1][meio] != '4' && matriz_jogo[i+1][meio] != '4'){ //Verifica as casas na ponta contrária
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(i-1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                    if(matriz_jogo[i-1][meio+3] == '4' && matriz_jogo[i+1][meio+3] == '*'){
                                        jogada++;
                                        printf("\nJogada: %d\n", jogada);
                                        contadorespiao2 = tiros(i+1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                    }
                                }
                            }
                        }
                        if(matriz_jogo[i-1][meio+3] == '*' && matriz_jogo[i-1][meio] != '4' && matriz_jogo[i+1][meio] != '4'){ //Verifica as casas na ponta contrária
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(i-1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            if(matriz_jogo[i-1][meio+3] == '4' && matriz_jogo[i+1][meio+3] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(i+1, meio+3, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                        }
                    }
                }
                if(contador == 3){
                    m=i;
                    n+=3;
                    if(m>2){
                        if(matriz_jogo[m-1][n] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(m-1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                        }
                        if(matriz_jogo[m-1][n] == '4'){
                            if(matriz_jogo[m-2][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m-2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                            if(matriz_jogo[m-3][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m-3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                        }
                    }
                    if(m<17 && matriz_jogo[m-1][n] != '4'){
                        m+=3;
                        if(matriz_jogo[m+1][n] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(m+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                        }
                        if(matriz_jogo[m+1][n] == '4'){
                            if(matriz_jogo[m+2][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m+2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                            if(matriz_jogo[m+3][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m+3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                        }
                    }
                }
                m=i-1;
                if(contador == 1 || contador == 2){ //Uma das pontas laterais
                    while(m>=0 && matriz_jogo[m][j] == '*' && matriz_jogo[m+1][j] == '4' && contador < 3){ //Verificando para cima
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorespiao2 = tiros(m, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                        if(matriz_jogo[m][j] == '4'){
                            contador++;
                        }
                        m--;
                    }
                    if(contador==3){ //Verificar para a direita ou para a esquerda
                        m+=2;
                        n=j+1;
                        contador=0;
                        while(n<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n-1] == '4' && contador < 3){ //Verificando para a direita
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            if(matriz_jogo[m][n] == '4'){
                                contador++;
                            }
                            n++;
                        }
                        if(contador == 0){
                            n=j-1;
                            while(n>=0 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n+1] == '4' && contador < 3){ //Verificando para a esquerda
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                if(matriz_jogo[m][n] == '4'){
                                    contador++;
                                }
                                n--;
                            }
                        }
                        if(contador == 0){
                            if(m-2>=0){
                                if(matriz_jogo[m-2][j] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m-2, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                    if(matriz_jogo[m-2][j] == '4'){
                                        if(matriz_jogo[m-2][j+1] == '*'){
                                            jogada++;
                                            printf("\nJogada: %d\n", jogada);
                                            contadorespiao2 = tiros(m-2, j+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                            if(matriz_jogo[m-2][j+1] == '4'){
                                                if(matriz_jogo[m-2][j-1] == '*'){
                                                    jogada++;
                                                    printf("\nJogada: %d\n", jogada);
                                                    contadorespiao2 = tiros(m-2, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(contador == 1 || contador == 2){
                        m=i+1;
                        while(m<=19 && matriz_jogo[m][j] == '*' && matriz_jogo[m-1][j] == '4' && contador < 3){ //Verificando para baixo
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorespiao2 = tiros(m, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            if(matriz_jogo[m][j] == '4'){
                                contador++;
                            }
                            m++;
                        }
                        if(contador==3){ //Verificar para a direita ou para a esquerda
                            m-=2;
                            n=j+1;
                            contador=0;
                            printf("\nvalor de M: %d Valor de n: %d\n", m, n);
                            while(n<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n-1] == '4' && contador < 3){ //Verificando para a direita
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                if(matriz_jogo[m][n] == '4'){
                                    contador++;
                                }
                                n++;
                            }
                            if(contador == 0){ 
                                n=j-1;
                                while(n>=0 && matriz_jogo[m][n] == '*' && matriz_jogo[m][n+1] == '4' && contador < 3){ //Verificando para a esquerda
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                    if(matriz_jogo[m][n] == '4'){
                                        contador++;
                                    }
                                    n--;
                                }
                            }
                            if(contador == 0){
                                if(matriz_jogo[m+2][j] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m+2, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                }
                                if(matriz_jogo[m+2][j+1] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m+2, j+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                }
                                if(matriz_jogo[m+2][j-1] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m+2, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                }
                            }
                        }
                    }
                    if(contador == 3){
                        m=i;
                        n+=3;
                        if(m>2){
                            if(matriz_jogo[m-1][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m-1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                            if(matriz_jogo[m-1][n] == '4'){
                                if(matriz_jogo[m-2][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m-2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                }
                                if(matriz_jogo[m-3][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m-3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                }
                            }
                        }
                        if(m<17 && matriz_jogo[m-1][n] != '4'){
                            m+=3;
                            if(matriz_jogo[m+1][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorespiao2 = tiros(m+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                            }
                            if(matriz_jogo[m+1][n] == '4'){
                                if(matriz_jogo[m+2][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m+2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);                           
                                }
                                if(matriz_jogo[m+3][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorespiao2 = tiros(m+3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorespiao2, jogada);
                                }
                            }
                        }
                    }
                }
            }
            else if(matriz_jogo[i][j] == '5'){
                //Ta verficando so na horizontal, depois fazer vertical se der tempo
                direcao='D'; //Definindo direcao padrão
                contador=0;
                n=j+1;
                contadorporta++;
                while(n<=19 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n-1] == '5' && contador < 4){ //Tentar para a direita
                    jogada++;
                    printf("\nJogada: %d\n", jogada);
                    contadorporta = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                    if(matriz_jogo[i][n] == '5'){
                        contador++;
                    }
                    n++;
                }   
                if(contador < 4 && matriz_jogo[i][n] != '5'){ //Tentar para a esquerda
                    n=j-1;
                    while(n>=0 && matriz_jogo[i][n] == '*' && matriz_jogo[i][n+1] == '5' && contador <4){
                        jogada++;
                        printf("\nJogada: %d\n", jogada);
                        contadorporta = tiros(i, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                        if(matriz_jogo[i][n] == '5'){
                            contador++;
                        }
                        n--;
                    }
                    direcao='E'; //Parou na coluna mais a esquerda
                }
                if(contador==5 || contador == 4){
                    contador=0;
                    if(direcao == 'D'){ //Percorrer da direita para esquerda
                        if(matriz_jogo[i-1][j] == '*'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorporta = tiros(i-1, j, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                        }
                        if(matriz_jogo[i-1][j] == '5'){
                            contador++;
                        }
                        while(j>=0 && matriz_jogo[i-1][j-1] == '*' && matriz_jogo[i-1][j] == '5' && contador < 5){ //Tentar linha acima
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorporta = tiros(i-1, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            if(matriz_jogo[i-1][j-1] == '5'){
                                contador++;
                            }
                            j--;
                        }
                        if(contador == 0){ //Tentar linha abaixo
                            while(j>=0 && matriz_jogo[i+1][j-1] == '*' && matriz_jogo[i+1][j] == '5' && contador < 5){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(i+1, j-1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                if(matriz_jogo[i+1][j-1] == '5'){
                                    contador++;
                                }
                                j--;
                            }
                        }
                    }else{ //Percorrer da esquerda para direita
                        n++;
                        if(matriz_jogo[i-1][n] == '5'){
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorporta = tiros(i-1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                        }
                        if(matriz_jogo[i-1][n] == '5'){ //Tentar linha acima
                            while(n<=19 && matriz_jogo[i-1][n+1] == '*' && matriz_jogo[i-1][n] == '5' && contador < 4){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(i-1, n+1, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                if(matriz_jogo[i-1][n+1] == '5'){
                                    contador++;
                                }
                                n++; 
                            }
                        }
                        if(contador == 0){ //Tentar linha abaixo
                            if(matriz_jogo[i+1][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(i+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            }
                            contador =0;
                            while(n<=19 && matriz_jogo[i+1][n+1] == '*' && matriz_jogo[i][n] == '5' && contador < 5){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(i+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                if(matriz_jogo[i+1][n] == '5'){
                                    contador++;
                                }
                                n++;
                            }
                        }
                    }
                }
                if(contador == 1 || contador == 2){
                    //Verficar na coluna, depois verificar a coluna vizinha
                    if(direcao == 'D'){
                        m=i-1;
                        n-=1;
                        contador = 1;
                        while(m>=0 && matriz_jogo[m][n] == '*' && matriz_jogo[m+1][n] == '5' && contador < 5){ 
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            if(matriz_jogo[m][n] == '5'){
                                contador++;
                            }
                            m--;
                        }
                        if(contador == 5){ //Verificando na coluna ao lado
                            n+=1;
                            contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            while(m<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m-1][n] == '5' && contador < 5){ 
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                if(matriz_jogo[m][n] == '5'){
                                    contador++;
                                }
                                m++; //Ajustar para a coluna ao lado
                            }
                        }
                        if(contador < 5){ //Verificando para baixo
                            m=i+1;
                            while(m<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m-1][n] == '5' && contador < 5){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                if(matriz_jogo[m][n] == '5'){
                                    contador++;
                                }
                                m++;
                            }
                            if(contador == 5){ //Verificando na coluna ao lado
                                m--;
                                n+=1;
                                contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                while(m<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m-1][n] == '5' && contador < 5){ 
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                    if(matriz_jogo[m][n] == '5'){
                                        contador++;
                                    }
                                    m++; //Ajustar para a coluna ao lado
                                }
                            }
                        }
                    }else if(direcao == 'E'){
                        m=i-1;
                        n+=2;
                        contador = 1;
                        while(m>=0 && matriz_jogo[m][n] == '*' && matriz_jogo[m+1][n] == '5' && contador < 5){ //Verificando para cima
                            jogada++;
                            printf("\nJogada: %d\n", jogada);
                            contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            if(matriz_jogo[m][n] == '5'){
                                contador++;
                            }
                            m--;
                        }
                        if(contador == 5){ //Verificando coluna a direita
                            n++;
                            m++;
                            if(matriz_jogo[m][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            }
                            if(matriz_jogo[m+1][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m+1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            }
                            if(matriz_jogo[m+2][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m+2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            }
                            if(matriz_jogo[m+3][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m+3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            }
                            if(matriz_jogo[m+4][n] == '*'){
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m+4, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                            }
                        }
                        if(contador < 5){ //Verficando para baixo
                            m=i+1;
                            while(m<=19 && matriz_jogo[m][n] == '*' && matriz_jogo[m-1][n] == '5' && contador < 5){ 
                                jogada++;
                                printf("\nJogada: %d\n", jogada);
                                contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                if(matriz_jogo[m][n] == '5'){
                                    contador++;
                                }
                                m++;
                            }
                            if(contador == 5){ //Verificando coluna a direita
                                m--;
                                n++;
                                if(matriz_jogo[m][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorporta = tiros(m, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                }
                                if(matriz_jogo[m-1][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorporta = tiros(m-1, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                }
                                if(matriz_jogo[m-2][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorporta = tiros(m-2, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                }
                                if(matriz_jogo[m-3][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorporta = tiros(m-3, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                }
                                if(matriz_jogo[m-4][n] == '*'){
                                    jogada++;
                                    printf("\nJogada: %d\n", jogada);
                                    contadorporta = tiros(m-4, n, matriz_leitura, matriz_jogo, matrizlateral, matrizsuperior, contadorporta, jogada);
                                }
                            }
                        }
                    }
                    
                }             
            }
        }else{
            i=rand()%20; //Sorteando a linha
            j=rand()%20; //Sorteando a coluna
        }
        if((contadorboia + contadoraviao + contadorsub + contadorespiao1 + contadorespiao2 + contadorporta) == 118){
            sair=1;
        }
    }

    if(sair == 1){
        printf("\nJogo finalizado com sucesso!!\n");
    }

    return 0;
}