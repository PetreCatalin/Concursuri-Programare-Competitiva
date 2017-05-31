#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

COORD coord={0,0};

void gotoxy(int x,int y)
{
    coord.X=y;
    coord.Y=x;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);
}

void ecraninceput()
{
    printf("               --------------------LINE-UP--------------------\n");
    printf("\n");
    printf("     Scopul jocului este de a face minim 4 de X sau de 0 consecutivi pe aceeasi linie,coloana sau diagonala\n");
    printf("\n");
    printf("---------MENIU---------\n");
    printf("Apasati 1 pentru a juca cu X\n");
    printf("Apasati 2 pentru a juca cu 0\n");
    printf("\n");
}

void desenaretabel()
{
    int i,j;
    printf("  ");
    for (i=1;i<=9;i++)
        printf(" %d",i);
        printf("\n");
    for (j=1;j<=9;j++) {
        printf("  ");
        for (i=1;i<=9;i++)
        printf("--");
        printf("-");
        printf("\n");
        printf("%d ",j);
            for (i=1;i<=10;i++)
            printf("| ");
        printf("\n");
    }
    printf("  ");
    for (i=1;i<=9;i++)
        printf("--");
        printf("-");
    printf("\n");
}

int nr,poz,a[15][15],ok,x,y,t,z,l[15],c[15],i,cons,cx,cy;

int main()
{
   ecraninceput();
   scanf("%d",&nr);
   if (nr==1) printf("Jucatorul 1 a ales sa joace cu X,Jucatorul 2 va juca cu 0\n");
   else
   if (nr==2) printf("Jucatorul 1 a ales sa joace cu 0,Jucatorul 2 va juca cu X\n");
   printf("\n");

   printf("Apasati tasta 1 pentru a incepe jocul\n");
   scanf("%d",&t);
   printf("\n");

   poz=0;
   z=38; //linia pe care apare prima oara "randul jucatorului 1/2"
   //initializare pozitiile liniilor si coloanelor la consola
   for (i=1;i<=9;i++)
        l[i]=17+(i-1)*2;
   for (i=1;i<=9;i++)
        c[i]=3+(i-1)*2;

   if(t==1) {
        desenaretabel();
        ok=0;
        printf("\n");
        printf("Introduceti linia si coloana corespunzatoare patratului in care vreti sa scrieti\n");
        while (ok==0 &&poz<81) {
            poz++;
            if (poz%2==1) printf("Randul jucatorului 1: ");
            else
            printf("Randul jucatorului 2: ");
            scanf("%d%d",&x,&y);

            gotoxy(l[x],c[y]);
            if (poz%2==1) {if (nr==1) printf("X"); else printf("O"); a[x][y]=1;}
            else
            {if (nr==1) printf("0"); else printf("X"); a[x][y]=2;}

            //verificare  in matrice
            cx=x;cy=y;
            if (poz%2==1) {
                cons=1;
                while (a[x][y-1]==1) {cons++;y=y-1;}
                x=cx;y=cy;
                while (a[x][y+1]==1) {cons++;y++;}
                if (cons>=4) ok=1;

                cons=1;
                x=cx;y=cy;
                while (a[x-1][y]==1) {cons++;x=x-1;}
                x=cx;y=cy;
                while (a[x+1][y]==1) {cons++;x++;}
                if (cons>=4) ok=1;

                cons=1;
                x=cx;y=cy;
                while (a[x-1][y-1]==1) {cons++;x=x-1;y=y-1;}
                x=cx;y=cy;
                while (a[x+1][y+1]==1) {cons++;x++;y++;}
                if (cons>=4) ok=1;

                cons=1;
                x=cx;y=cy;
                while (a[x+1][y-1]==1) {cons++;x++;y=y-1;}
                x=cx;y=cy;
                while (a[x-1][y+1]==1) {cons++;x=x-1;y++;}
                if (cons>=4) ok=1;
            }

            else
            if (poz%2==0) {
                cons=1;
                while (a[x][y-1]==2) {cons++;y=y-1;}
                x=cx;y=cy;
                while (a[x][y+1]==2) {cons++;y++;}
                if (cons>=4) ok=1;

                cons=1;
                x=cx;y=cy;
                while (a[x-1][y]==2) {cons++;x=x-1;}
                x=cx;y=cy;
                while (a[x+1][y]==2) {cons++;x++;}
                if (cons>=4) ok=1;

                cons=1;
                x=cx;y=cy;
                while (a[x-1][y-1]==2) {cons++;x=x-1;y=y-1;}
                x=cx;y=cy;
                while (a[x+1][y+1]==2) {cons++;x++;y++;}
                if (cons>=4) ok=1;

                cons=1;
                x=cx;y=cy;
                while (a[x+1][y-1]==2) {cons++;x++;y=y-1;}
                x=cx;y=cy;
                while (a[x-1][y+1]==2) {cons++;x=x-1;y++;}
                if (cons>=4) ok=1;
            }

            //intoarcere in consola
            gotoxy(z,0);
            printf("                                                           ");
            gotoxy(z,0);
            if (ok==1) {
                printf("Felicitari! Jucatorul ");
                if (poz%2==1) printf("1 ");
                else
                printf("2 ");
                printf("a castigat!");
            }
        }
        if (poz>81) printf("Nici un jucator nu a castigat");
   }

    return 0;
}
