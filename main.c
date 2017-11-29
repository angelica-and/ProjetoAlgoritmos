#include <stdio.h>
#include <stdlib.h>
#define tam 50

////declaração de variáveis globais
float A[tam][tam];
float B[tam][tam];
float C[tam][tam];
int linhaB, colunaB;
int linhaA, colunaA;
int i,j, k, a, b;
float aux = 0;

////imprimir menu na tela
void menu(void){

printf("\t\t MENU \n\n");

    printf("(1) Definir o tamanho da matriz A \n");
    printf("(2) Definir o tamanho da matriz B \n");
    printf("(3) Preencher a matriz A com valores aleatórios \n");
    printf("(4) Preencher a matriz B com valores aleatórios \n");
    printf("(5) Atribuir valores manualmente para os elementos da matriz A \n");
    printf("(6) Atribuir valores manualmente para os elementos da matriz B \n");
    printf("(7) Calcular A+B \n");
    printf("(8) Calcular A-B \n");
    printf("(9) Calcular A*B \n");
    printf("(10) Imprimir matriz A \n");
    printf("(11) Imprimir matriz B \n");
    printf("(12) Imprimir matriz C \n");
    printf("(13) Ler a matriz A de um arquivo \n");
    printf("(14) Ler a matriz B de um arquivo \n");
    printf("(15) Escrever a matriz C em um arquivo \n");
    printf("(16) Sair \n");


    printf("Escolha uma das opcoes acima: \n\n");

}

////1 definir tamanho da matriz A
void tamA(){

     printf("Quantidade de linhas da matriz A: ");
     scanf("%d",&linhaA);
     printf("Quantidade de colunas da matriz A: ");
     scanf("%d",&colunaA);

}

////2 definir tamanho da matriz B
void tamB(){

     printf("Quantidade de linhas da matriz B: ");
     scanf("%d",&linhaB);
     printf("Quantidade de colunas da matriz B: ");
     scanf("%d",&colunaB);

}

////3 matriz aleatória A
void aleatorioA(){

    printf("Digite o intervalo [a, b]: ");
    scanf("%d", &a);
    scanf("%d", &b);
    for(i=0;i<linhaA;i++){
        for(j=0;j<colunaA;j++){
            printf("Posicao %d,%d ",i+1,j+1);
            A[i][j] = (a+1) + ( rand() % b-a );
       }
     }
}

////4 matriz aleatória B
void aleatorioB(){

    printf("Digite o intervalo [a, b]: ");
    scanf("%d", &a);
    scanf("%d", &b);
    for(i=0;i<linhaB;i++){
        for(j=0;j<colunaB;j++){
            printf("Posicao %d,%d ",i+1,j+1);
            B[i][j] = (a+1) + ( rand() % b-a );
       }
     }
}

////5 preencher matriz A
void valoresA(){

     for(i=0;i<linhaA;i++){
           for(j=0;j<colunaA;j++){
               printf("Coloque o elemento %d,%d ",i+1,j+1);
               scanf("%f",&A[i][j]);
       }
     }
}

////6 preencher matriz B
void valoresB(){

     for(i=0;i<linhaB;i++){
           for(j=0;j<colunaB;j++){
               printf("Coloque o elemento %d,%d ",i+1,j+1);
               scanf("%f",&B[i][j]);
       }
     }
}

////7 A+B
void somaAB(){

if((linhaA == linhaB)&&(colunaA == colunaB)){
    for(i=0;i<linhaA;i++){
        for(j=0;j<colunaA;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
else{
    printf("As matrizes precisam ter tamanhos iguais!");
}
}

////8 A-B
void subtraiAB(){

if((linhaA == linhaB)&&(colunaA == colunaB)){
    for(i=0;i<linhaA;i++){
        for(j=0;j<colunaA;j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
else{
    printf("As matrizes precisam ter tamanhos iguais!");
}

}

////9 A*B
void multAB(){

if(colunaA == linhaB){

 for(i=0;i<linhaA;i++)
    {
        for(j=0;j<colunaB;j++)
        {
            C[i][j]=0;
            for(k=0;k<linhaB;k++)
            {
                aux=aux+A[i][k]*B[k][j];
            }
            printf("%f ", aux);
            C[i][j]=aux;
            aux = 0;
        }
    }
    printf("\n \n");

}
else
    printf("Erro!");


}

////imprimir matriz A
void showA(){

    printf("\n \n");
    printf("MATRIZ A: \n");
    for (i=0; i<linhaA; i++) {
        for (j=0; j<colunaA; j++) {
            printf("%f ", A[i][j]);
        }
    printf("\n");
    }
}

////imprimir matriz B
void showB(){

printf("\n \n");
printf("MATRIZ B: \n");
for (i=0; i<linhaB; i++) {
for (j=0; j<colunaB; j++) {
printf("%f ", B[i][j]);
}
printf("\n");
}
}

////imprimir matriz C
void showC(){
int opcao;
printf("Escolha qual resultado vc deseja ver: ");
printf("1 - A+B       2 - A-B       3 - A*B");
scanf("%d", &opcao);

if((opcao == 1)||(opcao == 2)){
        printf("\n \n");
    printf("MATRIZ C: \n");
    for (i=0; i<linhaA; i++) {
        for (j=0; j<colunaA; j++) {
            printf("%f ", C[i][j]);
        }
    printf("\n");

    }
}
    else{
    printf("\n \n");
    printf("MATRIZ C: \n");
    for (i=0; i<linhaA; i++) {
        for (j=0; j<colunaB; j++) {
            printf("%f ", C[i][j]);
        }
    printf("\n");

        }
    }
}

int main()
{
    FILE *arquivo, *saida;
    arquivo = fopen("C:/teste/alo.txt", "w");

    if (arquivo == NULL){
        printf("Nao abriu o arquivo");
        exit(0);
    }


    ////Declaração das Variáveis:
    int opcao;

do{
        menu();
        printf("\n");
        scanf("%d",&opcao);
        printf("\n\n");
        switch (opcao){

case 1:
    printf("(1) Definir o tamanho da matriz A \n");
    tamA();
    break;

case 2:
    printf("(2) Definir o tamanho da matriz B \n");
    tamB();
    break;

case 3:
    printf("(3) Preencher a matriz A com valores aleatórios \n");
    aleatorioA();
    break;

case 4:
    printf("(4) Preencher a matriz B com valores aleatórios \n");
    aleatorioB();
    break;

case 5:
    printf("(5) Atribuir valores manualmente para os elementos da matriz A \n");
    valoresA();
    break;

case 6:
    printf("(6) Atribuir valores manualmente para os elementos da matriz B \n");
    valoresB();
    break;

case 7:
    printf("(7) Calcular A+B \n");
    somaAB();
    break;

case 8:
    printf("(8) Calcular A-B \n");
    subtraiAB();
    break;

case 9:
    printf("(9) Calcular A*B \n");
    multAB();
    break;

case 10:
    printf("(10) Imprimir matriz A \n");
    showA();
    break;

case 11:
    printf("(11) Imprimir matriz B \n");
    showB();
    break;

case 12:
    printf("(12) Imprimir matriz C \n");
    showC();
    break;

case 13:
    printf("(13) Ler a matriz A de um arquivo \n");
    break;

case 14:
    printf("(14) Ler a matriz B de um arquivo \n");
    break;

case 15:
    printf("(15) Escrever a matriz C em um arquivo \n");
    break;

case 16:
    printf("(16) Sair \n");
    break;

    default:
        printf("Opcao Invalida!\n\n");
}

   }while(opcao>=0 && opcao<16);

    return 0;
}
