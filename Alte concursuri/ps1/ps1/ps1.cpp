// ps1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{

	int v[100],i,n,nr,ok;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&v[i]);

	if (v[1]<v[2]) nr=1;
	else
	if (v[1]>v[2]) nr=2;
	else
	nr=3;

	ok=1;
	if (nr==1) {
		for (i=3;i<=n;i++)
			if (v[i]<=v[i-1]) {ok=0;break;}\
		if (ok==1) printf("crescator");
		else
			printf("neordonat");
	}

	if (nr==2) {
		for (i=3;i<=n;i++)
			if (v[i]>=v[i-1]) {ok=0;break;}
		if (ok==1) printf("descrescator");
		else
			printf("neordonat");
	}

	if (nr==3) {
		for (i=3;i<=n;i++)
			if (v[i]!=v[i-1]) {ok=0;break;}
		if (ok==1) printf("constant");
		else
			printf("neordonat");
	}

	scanf("%d",&n);

	return 0;
}

