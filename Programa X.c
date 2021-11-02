#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void espacos_iniciais(unsigned char linF, unsigned char qtd_linhasF)
{
    unsigned char esp_inic[2]  = " ";
    int i;

    if(linF<=(qtd_linhasF/2))
    {
        for (i=1; i<linF; i++)
        {
            if(linF!=1)
            {
                printf("%s", esp_inic);
                fflush(stdout);
            }
        }
    }
    else
    {
        for (i=qtd_linhasF-1; i>=linF; i--)
        {
            if(linF!=0)
            {
                printf("%s", esp_inic);
                fflush(stdout);
            }
        }
    }
}

void espacos_do_meio(unsigned char linF, unsigned char qtd_linhasF)
{
    unsigned char esp_meio[2] = " ";
    int i;
    int var = (qtd_linhasF)-2*linF;
    int varParImp = ((linF)*2-(qtd_linhasF))-2;
    int dif = 0;

    if (linF<=(qtd_linhasF/2))
    {
         for(i=1; i<=var; i++)
         {
            printf("%s", esp_meio);
            fflush(stdout);
         }
    }
    else
    {
        for(i=1; i<(qtd_linhasF-i); i++)
        {
            dif += 1;
        }
        if(linF!= (qtd_linhasF - dif))
        {
            for(i=1; i<=varParImp; i++)
            {
                printf("%s", esp_meio);
                fflush(stdout);
            }
        }
    }
}

void segunda_bolinha (unsigned char linF, unsigned char qtd_linhasF)
{
    unsigned char bolinha [2] = "O";
    int i = 0;
    int dif = 0;

    if(qtd_linhasF%2==0)
    {
        printf("%s", bolinha);
        fflush(stdout);
    }
    else
    {
        for(i=1; i<(qtd_linhasF-i); i++)
        {
            dif += 1;
        }
        if(linF!= (qtd_linhasF - dif))
        {
            printf("%s", bolinha);
            fflush(stdout);
        }
    }
}

int main ()
{

    setlocale(LC_ALL, "portuguese");

    unsigned char lin, qtd_linhas, txtQtd_linhas [1025];
    char* erro;
    char situacao;
    double dblQtd_linhas;
    int n1;

    printf ("\n\nPrograma para Desenhar X\n\n");
    fflush (stdout);

    situacao='0';

    while(situacao=='0')
    {

        printf ("\n\nInsira a quantidade de linhas que o X deve ter: ");
        fgets (txtQtd_linhas, 1024, stdin);
        printf("\n\n");
        fflush (stdout);
        fflush (stdin);

        dblQtd_linhas=strtod(txtQtd_linhas, &erro);
        if(*erro!=10)
        {
            printf("\n\nERRO:Não foi digitado um número. Tente novamente!\n");
            fflush (stdout);
        }
        else
        {
            n1= (int)dblQtd_linhas;

            if(n1!= dblQtd_linhas)
            {
                printf("\n\nERRO:Insira um número sem vírgula. Tente novamente!\n");
                fflush (stdout);
            }
            else
            {
                 qtd_linhas=(unsigned char)dblQtd_linhas;

                 if (dblQtd_linhas<3)
                 {
                    printf ("\n\nERRO: Quantidade inválida (3 é o mínimo)!!!\n");
                    fflush (stdout);
                 }
                 else
                 {
                    situacao='1';
                 }
            }
        }
    }

    for (lin=1; lin<=qtd_linhas; lin++)
    {
        espacos_iniciais (lin,qtd_linhas);
        printf("O");
        espacos_do_meio (lin,qtd_linhas);
        segunda_bolinha (lin,qtd_linhas);
        printf("\n");
        fflush(stdout);
    }

    printf("\n\n");

    system("pause");
    return 0;
}
