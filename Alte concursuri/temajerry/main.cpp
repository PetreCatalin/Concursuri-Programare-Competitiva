#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char marca[20];
    char carburant[20];
    char natura[20];
    struct
    {
        char luna;
        int an;
    }data_fabricatie;
}automobil;

typedef automobil masini[30];

void citire (masini x,int *n)                    /*citire date*/
{
    int i;
    printf ("Introduceti numarul de automobile:");
    scanf("%d",n);
    for (i=0;i<*n;i++)
    {
        printf("Introduceti datele despre automobilul %d\n",i+1);
        printf("marca:\n");
        scanf("%s",x[i].marca);
        printf("tip de carburant[Benzina/Motorina]:\n");
        scanf("%s",x[i].carburant);
        printf("natura caroseriei[berlina/break/decapotabila]:\n");
        scanf("%s",x[i].natura);
        printf("luna fabricatiei:\n");
        scanf("%d",&x[i].data_fabricatie.luna);
        printf("an fabricatie:\n");
        scanf("%d",&x[i].data_fabricatie.an);

    }
}

void afisare(masini x,int n)			/*afisare date*/
{
	int i;
	 for (i=0;i<n;i++)
	{
		printf("Automobil [%d]:\n",i+1);
		printf("marca:           %s\n",x[i].marca);
		printf("tip carburant:   %s\n",x[i].carburant);
		printf("natura:          %s\n",x[i].natura);
		printf("luna fabricate:  %d\n",x[i].data_fabricatie.luna);
		printf("an fabricatie:   %d\n\n",x[i].data_fabricatie.an);
	 }
}

void afisare2(masini x)
{
    automobil a;
		printf("Automobil:\n");
		printf("marca:           %s\n",a.marca);
		printf("tip carburant:   %s\n",a.carburant);
		printf("natura:          %s\n",a.natura);
		printf("luna fabricate:  %d\n",a.data_fabricatie.luna);
		printf("an fabricatie:   %d\n\n",a.data_fabricatie.an);

}


int criteriu (masini x, int n )
 {
     int i;
     char marca_data[30];
     char carburant_dat[20];


printf("\nIntroduceti marca dupa care se face cautarea: \n");
        scanf("%s",marca_data);
    printf("\nIntroduceti tipul de carburant dupa care se face cautarea: \n");
        scanf("%s",carburant_dat);
        int ok=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(x[i].marca,marca_data)==0&&strcmp(x[i].carburant,carburant_dat)==0)
            {
            ok=1;
            break;
        }
    }
    return ok;
 }

void vechime (masini x, int n )
 {
     int i,an_curent;

     printf("\nIntroduceti anul curent: \n");
        scanf("%d",&an_curent);
    for(i=0;i<n;i++)
    {
         if ((an_curent - x[i].data_fabricatie.an)>5)
            afisare2(x);
    }
 }



void ordonare (masini x, int n )
 {
     int i,j;
     automobil aux;

     for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(x[i].data_fabricatie.an>x[j].data_fabricatie.an)
             {
				aux=x[i];
				x[i]=x[j];
				x[j]=aux;
             }
             if (x[i].data_fabricatie.an==x[j].data_fabricatie.an)
             {
            if (x[i].data_fabricatie.luna>x[j].data_fabricatie.luna)
            {
                aux=x[i];
                x[i]=x[j];
                x[j]=aux;
            }
             }
			}
		afisare(x,n);

 }


 void decapot (masini x, int n )
 {
     int i;
     int an_dat;
     char caroserie[20]="decapotabila";

printf("\nIntroduceti anul dupa care se face cautarea: \n");
        scanf("%d",&an_dat);
    for(i=0;i<n;i++)
    {
         if(strcmp(x[i].natura,caroserie)==0&&(x[i].data_fabricatie.an==an_dat))
            afisare2(x);
    }
 }


int main(void)
{
	masini x;
	int n,i;
	citire(x,&n);
	afisare(x,n);
	printf("Daca valoarea returnata va fi 1 inseamna ca masina exista,in caz contrar valoarea returnata va fi 0:\n");
	printf("%d\n",criteriu(x,n));
	vechime(x,n);
	printf("Se va realiza ordonarea crescatoare dupa anul de fabricatie:\n");
	ordonare(x,n);
	decapot(x,n);

return 0;
}
