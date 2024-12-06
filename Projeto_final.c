/*
Antonio Crepaldi Jr.   RA: 21012485
Felipe Silva Romero    RA: 21004635
Luiza Storari          RA: 21004979
Milena Souza           RA: 21000475
Yuka Sakai             RA: 21014084
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

void manual();
void creditos();
int jogos();
int livros();
int profissao();
int testa(char palavrinhas[3][11],char jogo[3][11],int Q);
void terminou(int contagem,int pontos,int acertos);

int main()
{
    int modo,topico, sair;
    do{
        setlocale(LC_ALL,"Portuguese");
        system("cls");
        printf("\n     FORCA 2.0\n====================\n");
        printf("\n1- Jogar\n2- Manual\n3- Créditos\n4- Sair\n\n");
        do{
            printf("\nDigite a opção que você deseja: ");
            scanf("%d",&modo);}while(modo<1||modo>4);
        switch(modo)
        {
        case 1:
            system("cls");
            printf("\nEm qual tópico você deseja jogar?\n");
            printf("\n1- Jogos\n2- Livros\n3- Profissão\n");
            do{
                printf("\nTópico: ");
                scanf("%d",&topico);}while(topico<1||topico>3);

            if(topico==1)jogos();
            else if(topico==2)livros();
            else profissao();
            break;
        case 2:
            manual();
            scanf("%d",&sair);
            break;
        case 3:
            creditos();
            scanf("%d",&sair);
            break;
        case 4:
            system("cls");
            printf("\nMuito obrigado por jogar !!!\n\n\n");
            return 0;
        }
    }while(sair!=2);
    system("cls");
    printf("\nMuito obrigado por jogar !!!\n\n\n");
    return 0;
}


void creditos()
{
    system("cls");
    printf("JOGO FEITO COM MUITO AMOR E CARINHO POR:\n");
    printf("Antonio Crepaldi Jr.   RA: 21012485\n");
    printf("Felipe Silva Romero    RA: 21004635 \n");
    printf("Luiza Storari          RA: 21004979\n");
    printf("Milena Souza           RA: 21000475\n");
    printf("Yuka Sakai             RA: 21014084\n\n");
    printf("Obrigado por jogar! :)\n\n\n");
    printf("Gostaria de voltar ao menu? (1-sim//2-não)\n");
}
void manual()
{
    system("cls");
    printf("MANUAL DO JOGO\n===============\n\n");
    printf("- Escolha entre os 3 tópicos: Jogos, livros e profissões\n");
    printf("- Haverão 3 palavras (com 10 letras no máx) para você tentar adivinhar\n");
    printf("- Inicialmente terão 100 pontos na contagem.\n");
    printf("- Você pode:\n");
    printf("Escolher no máximo 8 letras para adivinhar a palavra. Cada tentativa vale -5 pontos na contagem.\n");
    printf("Caso queira adivinhar a palavra é necessário digitar '?'\n");
    printf("Caso adivinhe você ganha 20 portos e caso erre, perde 20 na contagem\n\n");
    printf("\nBom jogo !!!:D\nGostaria de voltar ao menu? (1-sim//2-não)\n");
}
int jogos()
{
    char palavras[3][11]={"overwatch","tetris","among us"};
    char adivinha[3][11]={"*********","******","*****_**"};
    char joguinho[3][11];
    char tentativa;
    int conta=0,quero_adivinhar,n,Pontos=100,X,Y[3]={0}, Acertos=0,T;

    do{
        system("cls");
        if(X==1)
        {
            printf("\nAcertou!\n");
            X=0;
        }
        if(Y[0]==1&&Y[1]==1&&Y[2]==1)
        {
            terminou(conta, Pontos, Acertos);
            fflush(stdin);
            getchar();
            return 0;
        }
        printf("=========================\n");
        printf("********* JOGOS *********\n");
        printf("=========================\n\n");
        for(int i=0;i<3;i++)
        {
            printf("%s\n",adivinha[i]);
        }
        printf("\nDigite o caractere que você acha que tem,caso deseje adivinha a palavra tecle '?'.\n\nTentativa: %d\n\n",conta+1);
        fflush(stdin);
        scanf("%c",&tentativa);
        tentativa=tolower(tentativa);

        if(tentativa=='t')
        {
            adivinha[0][6]='t';
            adivinha[1][0]='t';
            adivinha[1][2]='t';
        }
        else if(tentativa=='o')
        {
            adivinha[0][0]='o';
            adivinha[2][2]='o';
        }
        else if(tentativa=='v')
        {
            adivinha[0][1]='v';
        }
        else if(tentativa=='e')
        {
            adivinha[0][2]='e';
            adivinha[1][1]='e';
        }
        else if(tentativa=='r')
        {
            adivinha[0][3]='r';
            adivinha[1][3]='r';
        }
        else if(tentativa=='w')
        {
            adivinha[0][4]='w';
        }
        else if(tentativa=='a')
        {
            adivinha[0][5]='a';
            adivinha[2][0]='a';
        }
        else if(tentativa=='c')
        {
            adivinha[0][7]='c';
        }
        else if(tentativa=='h')
        {
            adivinha[0][8]='h';
        }
        else if(tentativa=='i')
        {
            adivinha[1][4]='i';
        }
        else if(tentativa=='s')
        {
            adivinha[1][5]='s';
            adivinha[2][7]='s';
        }
        else if(tentativa=='m')
        {
            adivinha[2][1]='m';
        }
        else if(tentativa=='n')
        {
            adivinha[2][3]='n';
        }
        else if(tentativa=='g')
        {
            adivinha[2][4]='g';
        }
        else if(tentativa=='u')
        {
            adivinha[2][6]='u';
        }
        else if(tentativa=='?')
        {
            for(int i=0;i<3;i++)
            {
                printf("\n%s",adivinha[i]);
            }
            do{
                T=0;
                do{
                    printf("\n\nQual palavra você quer adivinnhar, 1, 2 ou 3?: ");
                    scanf("%d", &quero_adivinhar);
                }while(quero_adivinhar<1||quero_adivinhar>3);

                if(Y[quero_adivinhar-1]==1)
                {
                    printf("Você ja acertou essa palavra. Escolha outra:");
                    T++;
                }

            }while(T>0);

            printf("\nTente adivinhar:\n");
            fflush(stdin);
            gets(joguinho[quero_adivinhar-1]);

            X=testa(palavras,joguinho,quero_adivinhar);
            if(X==1)
            {
                Pontos = Pontos + 20;
                strcpy(adivinha[quero_adivinhar-1],joguinho[quero_adivinhar-1]);
                Y[quero_adivinhar-1]=1;
                Acertos++;
            }
            else if(X!=1)
            {
                Pontos=Pontos-20;
            }
            conta=conta-1;
            Pontos=Pontos+5;
        }
        conta++;
        Pontos=Pontos-5;
    }while(conta<8);

    system("cls");
    printf("=========================\n");
    printf("********* JOGOS *********\n");
    printf("=========================\n");
    for(int i=0;i<3;i++)
    {
        printf("%s\n",adivinha[i]);
    }
    printf("\nAcabaram suas tentativas. Você ainda pode adivinhar!\n");
    for(n=0;n<3;n++)
    {
        if(Y[n]==0)
        {
            printf("\nO que acha que é a palavra %d?: ",n+1);
            fflush(stdin);
            gets(joguinho[n]);
            X=strcmpi(palavras[n],joguinho[n]);
            if(X==0)
            {
                Pontos = Pontos + 20;
                Acertos++;
            }
            else
            {
                Pontos = Pontos - 20;
            }
        }
    }
    terminou(conta, Pontos, Acertos);
    fflush(stdin);
    getchar();
    return 0;
}
int livros()
{
    char palavras[3][11]={"pachinko","mayombe","pinoquio"};
    char adivinha[3][11]={"********","*******","********"};
    char joguinho[3][11];
    char tentativa;
    int conta=0,quero_adivinhar,n,Pontos=100,X,Y[3]={0}, Acertos=0,T;

    do{
        system("cls");
        if(X==1)
        {
            printf("\nAcertou!\n");
            X=0;
        }
        if(Y[0]==1&&Y[1]==1&&Y[2]==1)
        {
            terminou(conta, Pontos, Acertos);
            fflush(stdin);
            getchar();
            return 0;
        }
        printf("==========================\n");
        printf("********* LIVROS *********\n");
        printf("==========================\n\n");
        for(int i=0;i<3;i++)
        {
            printf("%s\n",adivinha[i]);
        }
        printf("\nDigite o caractere que você acha que tem,caso deseje adivinha a palavra tecle '?'.\n\nTentativa: %d\n\n",conta+1);
        fflush(stdin);
        scanf("%c",&tentativa);
        tentativa=tolower(tentativa);

        if(tentativa=='p')
        {
            adivinha[0][0]='p';
            adivinha[2][0]='p';
        }
        else if(tentativa=='a')
        {
            adivinha[0][1]='a';
            adivinha[1][1]='a';
        }
        else if(tentativa=='c')
        {
            adivinha[0][2]='c';
        }
        else if(tentativa=='h')
        {
            adivinha[0][3]='h';
        }
        else if(tentativa=='i')
        {
            adivinha[0][4]='i';
            adivinha[2][1]='i';
            adivinha[2][6]='i';
        }
        else if(tentativa=='n')
        {
            adivinha[0][5]='n';
            adivinha[2][2]='n';
        }
         else if(tentativa=='k')
        {
            adivinha[0][6]='k';
        }
         else if(tentativa=='o')
        {
            adivinha[0][7]='o';
            adivinha[1][3]='o';
            adivinha[2][3]='o';
            adivinha[2][7]='o';
        }
         else if(tentativa=='m')
        {
            adivinha[1][0]='m';
            adivinha[1][4]='m';
        }
        else if(tentativa=='y')
        {
            adivinha[1][2]='y';
        }
        else if(tentativa=='b')
        {
            adivinha[1][5]='b';
        }
        else if(tentativa=='e')
        {
            adivinha[1][6]='e';
        }
        else if(tentativa=='q')
        {
            adivinha[2][4]='q';
        }
        else if(tentativa=='u')
        {
            adivinha[2][5]='u';
        }
        else if(tentativa=='?')
        {
            for(int i=0;i<3;i++)
            {
                printf("\n%s",adivinha[i]);
            }
            do{
                T=0;
                do{
                    printf("\n\nQual palavra você quer adivinnhar, 1, 2 ou 3?: ");
                    scanf("%d", &quero_adivinhar);
                }while(quero_adivinhar<1||quero_adivinhar>3);

                if(Y[quero_adivinhar-1]==1)
                {
                    printf("Você ja acertou essa palavra. Escolha outra:");
                    T++;
                }

            }while(T>0);

            printf("\nTente adivinhar:\n");
            fflush(stdin);
            gets(joguinho[quero_adivinhar-1]);

            X=testa(palavras,joguinho,quero_adivinhar);
            if(X==1)
            {
                Pontos = Pontos + 20;
                strcpy(adivinha[quero_adivinhar-1],joguinho[quero_adivinhar-1]);
                Y[quero_adivinhar-1]=1;
                Acertos++;
            }
            else if(X!=1)
            {
                Pontos=Pontos-20;
            }
            conta=conta-1;
            Pontos=Pontos+5;
        }
        conta++;
        Pontos=Pontos-5;
    }while(conta<8);

    system("cls");
    printf("==========================\n");
    printf("********* LIVROS *********\n");
    printf("==========================\n");
    for(int i=0;i<3;i++)
    {
        printf("%s\n",adivinha[i]);
    }
    printf("\nAcabaram suas tentativas. Você ainda pode adivinhar!\n");
    for(n=0;n<3;n++)
    {
        if(Y[n]==0)
        {
            printf("\nO que acha que é a palavra %d?: ",n+1);
            fflush(stdin);
            gets(joguinho[n]);
            X=strcmpi(palavras[n],joguinho[n]);
            if(X==0)
            {
                Pontos = Pontos + 20;
                Acertos++;
            }
            else
            {
                Pontos = Pontos - 20;
            }
        }
    }
    terminou(conta, Pontos, Acertos);
    fflush(stdin);
    getchar();
    return 0;
}
int profissao()
{
    char palavras[3][11]={"bailarino","advogado","dentista"};
    char adivinha[3][11]={"*********","********","********"};
    char joguinho[3][11];
    char tentativa;
    int conta=0,quero_adivinhar,n,Pontos=100,X,Y[3]={0}, Acertos=0,T;

    do{
        system("cls");
        if(X==1)
        {
            printf("\nAcertou!\n");
            X=0;
        }
        if(Y[0]==1&&Y[1]==1&&Y[2]==1)
        {
            terminou(conta, Pontos, Acertos);
            fflush(stdin);
            getchar();
            return 0;
        }
        printf("==============================\n");
        printf("********* PROFISSÕES *********\n");
        printf("==============================\n\n");
        for(int i=0;i<3;i++)
        {
            printf("%s\n",adivinha[i]);
        }
        printf("\nDigite o caractere que você acha que tem,caso deseje adivinha a palavra tecle '?'.\n\nTentativa: %d\n\n",conta+1);
        fflush(stdin);
        scanf("%c",&tentativa);
        tentativa=tolower(tentativa);

        if(tentativa=='b')
        {
            adivinha[0][0]='b';
        }
        else if(tentativa=='a')
        {
            adivinha[0][1]='a';
            adivinha[0][4]='a';
            adivinha[1][0]='a';
            adivinha[1][5]='a';
            adivinha[2][7]='a';
        }
        else if(tentativa=='i')
        {
            adivinha[0][2]='i';
            adivinha[0][6]='i';
            adivinha[2][4]='i';
        }
         else if(tentativa=='l')
        {
            adivinha[0][3]='l';
        }
        else if(tentativa=='r')
        {
            adivinha[0][5]='r';
        }
        else if(tentativa=='n')
        {
            adivinha[0][7]='n';
            adivinha[2][2]='n';
        }
          else if(tentativa=='o')
        {
            adivinha[0][8]='o';
            adivinha[1][3]='o';
            adivinha[1][7]='o';
        }
        else if(tentativa=='d')
        {
            adivinha[1][1]='d';
            adivinha[1][6]='d';
            adivinha[2][0]='d';
        }
        else if(tentativa=='v')
        {
            adivinha[1][2]='v';
        }
        else if(tentativa=='g')
        {
            adivinha[1][4]='g';
        }
        else if(tentativa=='e')
        {
            adivinha[2][1]='e';
        }
        else if(tentativa=='s')
        {
            adivinha[2][5]='s';
        }
        else if(tentativa=='t')
        {
            adivinha[2][3]='t';
            adivinha[2][6]='t';
        }
        else if(tentativa=='?')
        {
            for(int i=0;i<3;i++)
            {
                printf("\n%s",adivinha[i]);
            }
            do{
                T=0;
                do{
                    printf("\n\nQual palavra você quer adivinnhar, 1, 2 ou 3?: ");
                    scanf("%d", &quero_adivinhar);
                }while(quero_adivinhar<1||quero_adivinhar>3);

                if(Y[quero_adivinhar-1]==1)
                {
                    printf("Você ja acertou essa palavra. Escolha outra:");
                    T++;
                }

            }while(T>0);

            printf("\nTente adivinhar:\n");
            fflush(stdin);
            gets(joguinho[quero_adivinhar-1]);

            X=testa(palavras,joguinho,quero_adivinhar);
            if(X==1)
            {
                Pontos = Pontos + 20;
                strcpy(adivinha[quero_adivinhar-1],joguinho[quero_adivinhar-1]);
                Y[quero_adivinhar-1]=1;
                Acertos++;
            }
            else if(X!=1)
            {
                Pontos=Pontos-20;
            }
            conta=conta-1;
            Pontos=Pontos+5;
        }
        conta++;
        Pontos=Pontos-5;
    }while(conta<8);

    system("cls");
    printf("==============================\n");
    printf("********* PROFISSÕES *********\n");
    printf("==============================\n");
    for(int i=0;i<3;i++)
    {
        printf("%s\n",adivinha[i]);
    }
    printf("\nAcabaram suas tentativas. Você ainda pode adivinhar!\n");
    for(n=0;n<3;n++)
    {
        if(Y[n]==0)
        {
            printf("\nO que acha que é a palavra %d?: ",n+1);
            fflush(stdin);
            gets(joguinho[n]);
            X=strcmpi(palavras[n],joguinho[n]);
            if(X==0)
            {
                Pontos = Pontos + 20;
                Acertos++;
            }
            else
            {
                Pontos = Pontos - 20;
            }
        }
    }
    terminou(conta, Pontos, Acertos);
    fflush(stdin);
    getchar();
    return 0;
}
int testa(char palavrinhas[3][11],char jogo[3][11],int Q)
{
    int N;
    N=strcmpi(palavrinhas[Q-1],jogo[Q-1]);
    if(N==0)
        return 1;
    else
        return 0;
}
void terminou(int contagem,int pontos,int acertos)
{
    system("cls");
    printf("\n       Acabou o jogo!!! \n");
    printf("\nSua pontuação foi de %d pontos!!", pontos);
    printf("\nNúmeros de tentativas: %d", contagem);
    printf("\nNúmero de palavras acertadas: %d",acertos);
    printf("\n\n\nObrigado por jogar! Digite qualquer tecla para sair ");
}
