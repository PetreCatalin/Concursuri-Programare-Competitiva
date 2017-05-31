// ps33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int v[100];
	int n,m,i,j,a,b,c;
	scanf("%d%d",&n,&m);
	for (i=0;i<=n-1;i++)
		v[i]=0;

	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&a,&b,&c);
		for (j=a;j<=b;j++)
			v[j]=v[j]+c;
	}

	for (i=0;i<=n-1;i++)
		printf("%d ",v[i]);

	scanf("%d",&a);
	
	return 0;
}

