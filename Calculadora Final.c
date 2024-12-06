#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
///ANTONIO MARCIO CREPALDI JUNIOR
int main()
{
    float N1, N2, C;
    float R;
    char P;
    printf("Calculadora\n===========");
    printf("\n '+' -> Somar\n '-' -> Subtrair\n '*' -> Multiplicar\n '/' -> Dividir\n'==' -> Finalizar\n");

    scanf("%f%c%f", &N1, &P, &N2);
    printf("%c", P);
    switch(P)
    {
        case'+':
        R = N1 + N2;
        printf("Soma: %.1f\n", R);
        break;

        case'-':
         R = N1 - N2;
        printf("Subtracao: %.1f\n", R);
        break;

        case'*':
         R = N1 * N2;
        printf("Multiplicacão: %.1f\n", R);
        break;

        case'/':
         if(N2!=0)
         {
        R = (float)N1 / N2;
        printf("Divisão: %.1f\n", R);
         }
         else printf("ERRO DIVISÂO POR ZERO");
        break;
    }
    fflush(stdin);
    do
{
        scanf("%c%f", &P,&N2);
        fflush(stdin);
         switch(P)
    {
        case'+':
        R = R + N2;
        printf("Soma: %.1f\n", R);
        break;

        case'-':
         R = R - N2;
        printf("Subtracao: %.1f\n", R);
        break;

        case'*':
         R = R * N2;
        printf("Multiplicacão: %.1f\n", R);
        break;

        case'/':
         if(N2!=0)
         {
        R = (float)R / N2;
        printf("Divisão: %.1f\n", R);
         }
         else printf("ERRO DIVISÂO POR ZERO");
        break;
    }

}   while(P!='=');
    printf("Obrigado por utilizar\n\n");
}
