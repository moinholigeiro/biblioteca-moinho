#ifndef _MOINHO_H
#define _MOINHO_H


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


void gerarVetorIntAleatorio(int *vetor, int tamanho, int valorMinimo, int valorMaximo){
    for(int i=0;i<tamanho;i++){
        vetor[i] = valorMinimo + rand() % (valorMaximo-valorMinimo+1);
    }
}

int gerarIntAleatorio(int valorMinimo, int valorMaximo){
    return (valorMinimo + rand() % (valorMaximo-valorMinimo+1));
}

void bubbleSort(int *vetor, int tamanho){
    int troca;
    int aux;
    for(int posFim=tamanho-1; posFim>0; posFim--){
        troca = 0;
        for(int i=0; i<posFim; i++){
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
                troca = 1;
            }
        }
        if(troca == 0){
            break;
        }
    }
}

int arredondarFloat(float num){
    return (num >= 0) ? (int)(num + 0.5) : (int)(num - 0.5);
}

int arredondarDouble(double num){
    return (num >= 0) ? (int)(num + 0.5) : (int)(num - 0.5);
}

int intDaStr(char *string){
    int valor=0;
    int sinal=0;

    if(string[0] == 45){
        sinal = 1;
    }

    for(int i=0;string[i] != '\0';i++){
        if(string[i] > 47 && string[i] < 58){
            valor = 10*valor + (string[i] - 48);
        }
    }

    if(sinal == 0){
        return valor;
    }
    else{
        return valor * (-1);
    }
}

void strTudoMaiusculo(char *string){
    for(int i=0;i<strlen(string);i++){
        if(string[i] > 96 && string[i] < 123){
            string[i] = string[i] - 32;
        }
    }
}

char charMaiusculo(char c){
    if(c > 96 && c < 123){
            c = c - 32;
    }
    return c;
}






int pegaLinks(char *stringBuscada, char charQueLimita, char *diretorioCompletoInput, char *diretorioCompletoOutput){ // essa funcao cria um arquivo com todas as strings, uma por linha, dos textos desejados ate aparecer um caractere especifico nao desejado (muito util para pegar links de um dominio em um codigo fonte num site)
    #define QTD_MAX_DE_STR 500
    #define QTD_MAX_DE_CHAR_POR_STR 500
    #define QTD_MAX_DE_CHAR_TEXTO 100000

    FILE *file;
    file = fopen(diretorioCompletoInput, "r");
    char links[QTD_MAX_DE_STR][QTD_MAX_DE_CHAR_POR_STR];
    char *ponteiro;
    char texto[QTD_MAX_DE_CHAR_TEXTO];

    for(int i=0;texto[i-1] != EOF;i++){
        texto[i] = fgetc(file);
    }
    fclose(file);

    file = fopen(diretorioCompletoOutput, "w");

    for(int i=0;1;i++){
        ponteiro = strstr(texto, stringBuscada);
        if(ponteiro == NULL){
            fclose(file);
            return 0;
        }

        for(int j=0;*(ponteiro+j) != charQueLimita;j++){
            links[i][j] = *(ponteiro+j);
            if(strcmp(stringBuscada, "f") == 0)
                *(ponteiro+j) = 'g';
            else
                *(ponteiro+j) = 'f';
        }

        fprintf(file, "%s\n", links[i]);
    }
}


#endif
