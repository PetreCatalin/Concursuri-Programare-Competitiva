// p6.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

void spirala(int a[][100],int n,int m,int v[])
{
	int i,j,nr;
	nr=-1;
	for (i=1;i<=(n+1)/2;i++)
	{
		for (j=i; j<=n-i+1; j++) {++nr;v[nr]=a[j][i];}
		for (j=i+1; j<=m-i+1; j++) {++nr;v[nr]=a[n-i+1][j];}
		for (j=n-i;j>=i;j--) {nr++;v[nr]=a[j][m-i+1];}
		for (j=m-i;j>=i+1;j--) {nr++;v[nr]=a[i][j];}
	}
}

void afis(int v[],int nr)
{
	int i;
	for (i=0;i<=nr;i++)
		printf("%d ",v[i]);
}

int a[100][100],v[10000];

int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&a[i][j]);

	spirala(a,n,m,v);
	afis(v,n*m-1);

	return 0;
}
