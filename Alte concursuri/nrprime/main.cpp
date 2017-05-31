// nrprime.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <cmath>

int n,i,ok,x,nr;

int prim (int x)
{
	int ok,i;
	if (x==1) ok=0;
	else {
	ok=1;
	for (i=2;i<=floor(sqrt(x));i++)
		if (x%i==0) {ok=0;break;}
	}
	return ok;
}


int main()
{
	//verificare daca un numar este prim
	scanf("%d",&x);
	ok=prim(x);
	if (ok==1) printf("numarul %d este prim\n",x);
	else
		printf("numarul %d nu este prim\n",x);

	//primele n numere prime
	scanf("%d",&n);
	printf("2 ");nr=1;
	x=3;
	while (nr<n) {
		ok=prim(x);
		if (ok==1) {nr++;printf("%d ",x);}
		x=x+2;
	}
	return 0;
}
