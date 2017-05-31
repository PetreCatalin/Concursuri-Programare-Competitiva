#include <iostream>

using namespace std;

int m,i,j,nr,a[100][100];

void fill(int i,int j,int nr)
{
    a[i][j]=nr;
    if (a[i][j+1]==1) fill(i,j+1,nr);
    if (a[i][j-1]==1) fill(i,j-1,nr);
    if (a[i-1][j]==1) fill(i-1,j,nr);
    if (a[i+1][j]==1) fill(i+1,j,nr);
}

int main()
{
    cin>>m;
    for (i=1;i<=m;i++)
        for (j=1;j<=m;j++)
        cin>>a[i][j];

    nr=1;
    for (i=1;i<=m;i++)
        for (j=1;j<=m;j++)
            if (a[i][j]==1) {
                nr++;
                fill(i,j,nr);
            }

    for (i=1;i<=m;i++) {
        for (j=1;j<=m;j++)
            cout<<a[i][j]<<' ';
            cout<<'\n';
    }


    return 0;
}
