#include <stdio.h>
#include <stdlib.h>
int contCelulas = 0;              //Armazena a qtd de celulas da matriz



typedef struct Celula{
    int i;
    int j;
    int valor;
}Celula;
Celula *cel;
//void checaSeInt(int valor){

//}
void atribuirValor(long int iMax, long int jMax){
    int i;
    int j;
    int valor;
    if(cel == NULL){
        printf("Erro na alocacao de memoria! \n");
        exit(1);
    }
    printf("Digite em qual posicao 'i' o valor sera inserido: \n");
    scanf("%d", &i);
    fflush(stdin);
//    checaSeInt(i);
    printf("Digite em qual posicao 'j' o valor sera inserido: \n");
    scanf("%d", &j);
    //checaSeInt(j);
    printf("Digite qual o valor a ser inserido: \n");
    scanf("%d", &valor);
    fflush(stdin);
    //checaSeInt(valor);
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
    getch();
    return;
}

void consultarValor(long int iMax, long int jMax){
    int i = 0;
    int j = 0;
    printf("Digite a posicao i da linha a ser consultada: \n");
    scanf("%d", &i);
    fflush(stdin);
    //checaSeInt();
    printf("Digite a posicao j da coluna a ser consultada: \n");
    scanf("%d", &j);
    fflush(stdin);
    //checaSeInt();
    for(int m=0; m<=contCelulas; m++){
        if(cel[m].i == i && cel[m].j == j){
            printf("O valor eh: %d", cel[m].valor);
            getch();
            return;
        }
    }
    printf("O valor eh: 0 \n");
    getch();
    return;
}

void somaLinha(long int iMax){
    int linha = 0;
    int soma = 0;
    printf("Digite a linha a ter seus valores somados: \n");
    scanf("%d", &linha);
    fflush(stdin);
    //checaSeInt();
    //if(linha > iMax){
        //printf("Linha inexistente! \n");
    //}
    for(int m = 1; m<=contCelulas; m++){
        if(cel[m].i == linha){
            soma += cel[m].valor;
        }
    }
    printf("A soma dos valores da linha %d eh: %d", linha, soma);
    getch();
}

void somaColuna(long int jMax){
    int coluna = 0;
    int soma = 0;
    printf("Digite a coluna a ter seus valores somados: \n");
    scanf("%d", &coluna);
    fflush(stdin);
    //if(coluna > jMax){
        //printf("Linha inexistente! \n");
    //}
    for(int m = 1; m<=contCelulas; m++){
        if(cel[m].j == coluna){
            soma += cel[m].valor;
        }
    }
    printf("A soma dos valores da coluna %d eh: %d", coluna, soma);
    getch();
}


int main()
{
    long int iMax = 0;
    long int jMax = 0;
    int comando = 0;
    int flag = 1;
    cel = (Celula*)malloc(sizeof(Celula));
    printf("Digite a quantidade m de linhas da matriz esparsa: \n");
    scanf("%ld", &iMax);
    fflush(stdin);
    printf("Digite a quantidade n de colunas da matiz esparsa: \n");
    scanf("%ld", &jMax);
    fflush(stdin);
    while(flag == 1){
        system("cls");
        printf("1-Atribuir novo valor na matriz \n");
        printf("2-Consultar valor de uma posicao da matriz \n");
        printf("3-Consultar a soma dos valores de uma linha \n");
        printf("4-Consultar a soma dos valores de uma coluna \n");
        printf("5-Exclusao da matriz \n");
        scanf("%d", &comando);
        fflush(stdin);
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
        }
        else{
            printf("Entrada invalida! Digite novamente \n");
            //delay();
        }
    }
    return 0;
}
