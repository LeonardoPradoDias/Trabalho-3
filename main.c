#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int contCelulas = 0;              //Armazena a qtd de celulas da matriz

void delay(int tempo){
    unsigned int fim = time(0) + tempo;
    while(time(0) <= fim);
    return;
}

void splashScreen(){
    printf("\n                    ******************************************************************************\n");
    for(int i=0; i<2; i++){
            printf("                    *                                                                            *\n");
    }
    printf("                    *                      BEM VINDO AO SISTEMA DE MATRIZES                      *\n");
    for(int j=0; j<2; j++){
            printf("                    *                                                                            *\n");
    }
    printf("                    ******************************************************************************\n");
    delay(2);
    system("cls");
    return;
}

int checaSeInt(){
    char entrada[20];
    scanf("%s", entrada);
    fflush(stdin);
    int flag = 0;
    int i = 0;

    for(i=0; i<strlen(entrada); i++){
            if(entrada[i] < '0' || entrada[i] > '9'){
                    flag = 1;
            }
    }
    while(flag == 1){
        flag = 0;
        printf("Erro na formatacao. Digite novamente: \n");
        scanf("%s", entrada);
        fflush(stdin);
        for(i=0; i<strlen(entrada); i++){
            if (entrada[i] < '0' || entrada[i] > '9'){
                flag = 1;
            }
        }
    }
    flag = 0;
    return atoi(entrada);
}

float checaSeFloat(){
    char entrada[20];
    scanf("%s", entrada);
    fflush(stdin);
    int flag = 0;
    int i = 0;

    for(i=0; i<strlen(entrada); i++){
            if((entrada[i] < '0' || entrada[i] > '9') && (entrada[i] != '.')){
                    flag = 1;
            }
    }
    while(flag == 1){
        flag = 0;
        printf("Erro na formatacao. Digite novamente: \n");
        scanf("%s", entrada);
        fflush(stdin);
        for(i=0; i<strlen(entrada); i++){
            if ((entrada[i] < '0' || entrada[i] > '9') && (entrada[i] != '.')){
                flag = 1;
            }
        }
    }
    flag = 0;

    return atof(entrada);
}

typedef struct Celula{
    int i;
    int j;
    float valor;
}Celula;
Celula *cel;

void atribuirValor(int iMax, int jMax){
    int i;
    int j;
    float valor;
    int flag = 0;
    if(cel == NULL){
        printf("Erro na alocacao de memoria! \n");
        exit(1);
    }
    printf("Digite em qual linha 'i' o valor sera inserido: \n");
    i = checaSeInt();
    while(flag == 0){
        if (i < iMax){
            flag = 1;
        } else {
            printf("Posicao invalida! Digite novamente: \n");
            i = checaSeInt();
        }
    }
    flag = 1;

    printf("Digite em qual coluna 'j' o valor sera inserido: \n");
    j = checaSeInt();
    while(flag == 0){
        if (j < jMax){
            flag = 1;
        } else {
            printf("Posicao invalida! Digite novamente: \n");
            j = checaSeInt();
        }
    }
    flag = 1;

    printf("Digite qual valor sera inserido: \n");
    valor = checaSeFloat();

    contCelulas++;
    cel =(Celula*)realloc(cel, (contCelulas + 1)*sizeof(Celula));
    if(cel == NULL){
        printf("Erro na alocacao de memoria! \n");
        exit(1);
    }
    cel[contCelulas].i = i;
    cel[contCelulas].j = j;
    cel[contCelulas].valor = valor;
    printf("Valor inserido com sucesso! \n");
    system("pause");
    return;
}

void consultarValor(int iMax, int jMax){
    int i = 0;
    int j = 0;
    int flag = 1;
    while(flag == 1){
        flag = 0;
        printf("Digite a posicao 'i' da linha a ser consultada: \n");
        i = checaSeInt();
        if(i<0 || i>=iMax){
            printf("Linha inexistente! \n");
            flag  = 1;
        }
    }
    flag = 1;
    while(flag == 1){
        flag = 0;
        printf("Digite a posicao 'j' da coluna a ser consultada: \n");
        j = checaSeInt();
        if(j<0 || j>=jMax){
            printf("Coluna inexistente! \n");
            flag  = 1;
        }
    }
    for(int m=0; m<=contCelulas; m++){
        if(cel[m].i == i && cel[m].j == j){
            printf("O valor e: %f\n", cel[m].valor);
            system("pause");
            return;
        }
    }
    printf("O valor e: 0 \n");
    system("pause");
    return;
}

void somaLinha(int iMax){
    int linha = 0;
    float soma = 0;
    printf("Digite a linha a ter seus valores somados: \n");
    linha = checaSeInt();
    if(linha >= iMax){
        printf("Linha inexistente! \n");
        system("pause");
        return;
    }
    for(int m = 1; m<=contCelulas; m++){
        if(cel[m].i == linha){
            soma += cel[m].valor;
        }
    }
    printf("A soma dos valores da linha %d e: %f\n", linha, soma);
    system("pause");
}

void somaColuna(int jMax){
    int coluna = 0;
    float soma = 0;
    printf("Digite a coluna a ter seus valores somados: \n");
    coluna = checaSeInt();

    if(coluna >= jMax){
        printf("Coluna inexistente! \n");
        system("pause");
        return;
    }
    for(int m = 1; m<=contCelulas; m++){
        if(cel[m].j == coluna){
            soma += cel[m].valor;
        }
    }
    printf("A soma dos valores da coluna %d e: %f \n", coluna, soma);
    system("pause");
}


int main()
{
    splashScreen();
    int reinicio = 1;
    int iMax = 0;
    int jMax = 0;
    int comando = 0;
    int flag = 1;
    cel = (Celula*)malloc(sizeof(Celula));
    while(reinicio == 1){
        reinicio = 0;
        system("cls");
        flag = 1;

        while(flag == 1){
            flag = 0;
            printf("Digite a quantidade m de linhas da matriz esparsa: \n");
            iMax = checaSeInt();
            if(iMax ==0){
                printf("Quantidade de linhas deve ser maior do que zero! \n");
                flag = 1;
            }
        }
        flag = 1;
        while(flag == 1){
            flag = 0;
            printf("Digite a quantidade n de colunas da matriz esparsa: \n");
            jMax = checaSeInt();
            if(jMax ==0){
                printf("Quantidade de colunas deve ser maior do que zero! \n");
                flag = 1;
            }
        }
        flag = 1;
        while(flag == 1){
            system("cls");
            printf("MENU DE OPCOES\n");
            printf("1-Atribuir novo valor a matriz \n");
            printf("2-Consultar valor de uma posicao da matriz \n");
            printf("3-Consultar a soma dos valores de uma linha \n");
            printf("4-Consultar a soma dos valores de uma coluna \n");
            printf("5-Exclusao da matriz \n");
            printf("6-Finalizar programa \n\n");
            printf("Selecione uma acao: \n");
            comando = checaSeInt();
            if(comando == 1){
                atribuirValor(iMax, jMax);
            }
            else if(comando == 2){
                consultarValor(iMax, jMax);
            }
            else if(comando == 3){
                somaLinha(iMax);
            }
            else if(comando == 4){
                somaColuna(jMax);
            }
            else if(comando == 5){
                free(cel);
                iMax = 0;
                jMax = 0;
                contCelulas = 0;
                printf("Matriz excluida com sucesso! E sera reiniciada!1 \n");
                flag = 0;
                reinicio = 1;
                system("pause");
            }
            else if(comando == 6){
                printf("\nPrograma finalizado!\n");
                exit(1);
            }
            else{
                printf("Entrada invalida! Digite novamente: \n");
            }
        }
    }
    return 0;
}
