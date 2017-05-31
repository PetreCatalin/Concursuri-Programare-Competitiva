#include <fstream>

using namespace std;

long int p1,p2,r1,r2,inc,sf,i,j,x,y,a[100][100],st1[10000],st2[10000],sf1,c,n,m;
bool ok;

int main()
{
	ifstream f("cal.in");
	ofstream g("cal.out");
	f>>n>>m;
	f>>p1>>p2;
	a[p1][p2]=1;
	st1[1]=p1;
	st2[1]=p2;
	inc=1;sf=1;
	f>>r1>>r2;
	c=2;
	sf1=1;
	while (a[r1][r2]==0) {
	while (inc<=sf &&a[r1][r2]==0) {
		x=st1[inc];
		y=st2[inc];
		if (x-2>0 && y-1>0 && x-2<=n &&y-1<=m)
		if (a[x-2][y-1]==0) {
			a[x-2][y-1]=c; sf1++;
			st1[sf1]=x-2;
			st2[sf1]=y-1;
		}
		if (x-2>0 && y+1>0 && x-2<=n &&y+1<=m)
		if (a[x-2][y+1]==0) {
			a[x-2][y+1]=c; sf1++;
			st1[sf1]=x-2;
			st2[sf1]=y+1;
		}
		if (x-1>0 && y+2>0 && x-1<=n &&y+2<=m)
		if (a[x-1][y+2]==0) {
			a[x-1][y+2]=c; sf1++;
			st1[sf1]=x-1;
			st2[sf1]=y+2;
		}
		if (x+1>0 && y+2>0 && x+1<=n &&y+2<=m)
		if (a[x+1][y+2]==0) {
			a[x+1][y+2]=c; sf1++;
			st1[sf1]=x+1;
			st2[sf1]=y+2;
		}
		if (x+2>0 && y+1>0 && x+2<=n &&y+1<=m)
		if (a[x+2][y+1]==0) {
			a[x+2][y+1]=c; sf1++;
			st1[sf1]=x+2;
			st2[sf1]=y+1;
		}
		if (x+2>0 && y-1>0 && x+2<=n &&y-1<=m)
		if (a[x+2][y-1]==0) {
			a[x+2][y-1]=c; sf1++;
			st1[sf1]=x+2;
			st2[sf1]=y-1;
		}
		if (x+1>0 && y-2>0 && x+1<=n &&y-2<=m)
		if (a[x+1][y-2]==0) {
			a[x+1][y-2]=c; sf1++;
			st1[sf1]=x+1;
			st2[sf1]=y-2;
		}
		if (x-1>0 && y-2>0 && x-1<=n &&y-2<=m)
		if (a[x-1][y-2]==0) {
			a[x-1][y-2]=c; sf1++;
			st1[sf1]=x-1;
			st2[sf1]=y-2;
		}
		inc++;
	}
	c++;
	inc=sf+1;
	sf=sf1;
	}
	g<<a[r1][r2]<<'\n';
	c=c-2;
	g<<r1<<' '<<r2<<'\n';
	x=r1;y=r2;
	while (c>0) {
	       ok=true;
	       if (x-2>0 && y-1>0 && x-2<=n &&y-1<=m)
		if (a[x-2][y-1]==c) {
		       x=x-2;y=y-1;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		if (ok) {
		if (x-2>0 && y+1>0 && x-2<=n &&y+1<=m)
		if (a[x-2][y+1]==c) {
		       x=x-2;y=y+1;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		if (ok) {
		if (x-1>0 && y+2>0 && x-1<=n &&y+2<=m)
		if (a[x-1][y+2]==c) {
		       x=x-1;y=y+2;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		if (ok) {
		if (x+1>0 && y+2>0 && x+1<=n &&y+2<=m)
		if (a[x+1][y+2]==c) {
		       x=x+1;y=y+2;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		if (ok) {
		if (x+2>0 && y+1>0 && x+2<=n &&y+1<=m)
		if (a[x+2][y+1]==c) {
		       x=x+2;y=y+1;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		if (ok) {
		if (x+2>0 && y-1>0 && x+2<=n &&y-1<=m)
		if (a[x+2][y-1]==c) {
		       x=x+2;y=y-1;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		if (ok) {
		if (x+1>0 && y-2>0 && x+1<=n &&y-2<=m)
		if (a[x+1][y-2]==c) {
		       x=x+1;y=y-2;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		if (ok){
		if (x-1>0 &&y-2>0 &&x-1<=n &&y-2<=m)
		if (a[x-1][y-2]==c) {
		       x=x-1;y=y-2;
		       g<<x<<' '<<y<<'\n';
		       ok=false;
		}
		}
		--c;
	}
	f.close();
	g.close();
	return 0;
}
