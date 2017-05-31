// ps2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>

int main()
{
	int n,i,ap[105],a[100],j,m,s;
	float v[100];

	for (i=0;i<=100;i++)
		ap[i]=0;

	scanf("%d",&n);

	for (i=1;i<=n;i++) {
		scanf("%f",&v[i]);
		int x=floor(v[i]);
		if (x!=v[i])
			ap[x]=ap[x]+1;
	}

	scanf("%d",&m);
	for (i=1;i<=m;i++)
		scanf("%d",&a[i]);

	for (i=1;i<=m-1;i++) {
		 s=0;
			for (j=a[i];j<=a[i+1]-1;j++)
				s=s+ap[j];
		printf("%d ",s);
	}

	scanf("%d",&s);

	return 0;
}
