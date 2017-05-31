// ps1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int n,nr,v[10];

int d(int n)
{
	if (n<10) return v[n];
	int u=n%10;
	int z=(n%100)/10;
	int x=d(n/5);
	int y=d(u);
	if (z%2==1)
		int nr=(4*x*y)%10;
	else
		int nr=(6*x*y)%10;
	return nr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	scanf("%d",&n);
	v[0]=1;v[1]=1;v[2]=2;v[3]=6;v[4]=4;v[5]=2;v[6]=2;v[7]=4;v[8]=2;v[9]=8;
	nr=d(n);
	printf("%d",nr);
	scanf("%d",&nr);
	return 0;
}
