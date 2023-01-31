#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define O_MEU "F:/MOINHO/Programacao/c/trabalho_urna/funcionando_ja/teste/saida"


int main(){

    char NOME_ARQUIV[13][50] = {"boletim.csv","ranking_deputado_estadual.csv","ranking_deputado_federal.csv","ranking_governador.csv","ranking_presidente.csv","bancada_deputado_estadual.csv","bancada_deputado_federal.csv","eleitos.csv","media_idade.csv","genero_legislativo.csv"};

    char enderecoEXEMPLO[10][500];
    char enderecoO_MEU[10][500];

    char tudoExemplo[10][20000];
    char tudoOMeu[10][20000];

    FILE *exemplo;
    FILE *oMeu;

    int j;
    char a[500];
    char b[500];
    int igual;
    
    printf("endereco da saida DO SEU teste: ");
    scanf("%499[^\n]", b);
    getc(stdin);
    
    isso:
    while(1){
        igual = 1;
        j=0;
        printf("\n(digite '0' e de enter para fechar o programa)\nendereco da saida de teste esperado: ");
        scanf("%499[^\n]", a);
        getc(stdin);

        printf("\n");
        if(a[0] == '0' && a[1] == '\0')
            return 0;
        for(int i=0;i<10;i++){
            strcpy(enderecoEXEMPLO[i],a);
            strcat(enderecoEXEMPLO[i],"/");
            strcat(enderecoEXEMPLO[i],NOME_ARQUIV[i]);

            strcpy(enderecoO_MEU[i],b);
            strcat(enderecoO_MEU[i],"/");
            strcat(enderecoO_MEU[i],NOME_ARQUIV[i]);
        }


        for(int i=0; i<10 ;i++){

            exemplo = fopen(enderecoEXEMPLO[i], "r");
            if(exemplo == NULL){
                printf("\n\nendereco de saida EXEMPLO invalido!\n\n");
                goto isso;
            }
            oMeu = fopen(enderecoO_MEU[i], "r");
            if(oMeu == NULL){
                printf("\n\nendereco da SUA saida invalido!\n\n");
                goto isso;
            }
            j = 0;
            while(1){
                tudoExemplo[i][j] = fgetc(exemplo);
                tudoOMeu[i][j] = fgetc(oMeu);
                if(tudoExemplo[i][j] == EOF && tudoOMeu[i][j] == EOF){
                    tudoExemplo[i][j] = '\0';
                    tudoOMeu[i][j] = '\0';
                    break;
                }
                if(tudoExemplo[i][j] != tudoOMeu[i][j]){
                    printf("TA DIFERENTE (o caractere %d e diferente) do arquivo \"%s\"\n", j, NOME_ARQUIV[i]);
                    fclose(exemplo);
                    fclose(oMeu);
                    igual = 0;
                    goto resto;
                }
                if(tudoExemplo[i][j] == EOF && tudoOMeu[i][j] != EOF){
                    printf("TA DIFERENTE (o EXEMPLO acaba antes, no caractere %d) do arquivo \"%s\"\n", j, NOME_ARQUIV[i]);
                    fclose(exemplo);
                    fclose(oMeu);
                    igual = 0;
                    goto resto;
                }
                if(tudoExemplo[i][j] != EOF && tudoOMeu[i][j] == EOF){
                    printf("TA DIFERENTE (o MEU acaba antes, no caractere %d) do arquivo \"%s\"\n", j, NOME_ARQUIV[i]);
                    fclose(exemplo);
                    fclose(oMeu);
                    igual = 0;
                    goto resto;
                }
                j++;
            }
            resto:
                continue;
        }

        if(igual == 1){
            fclose(exemplo);
            fclose(oMeu);
            printf("\n\nTodos os arquivos identicos!\n\n");
            goto isso;
        }
    }

}