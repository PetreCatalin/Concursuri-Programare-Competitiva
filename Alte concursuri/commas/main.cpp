#include <fstream>
#include <cstring>

using namespace std;

char n[15];
int nr,i;

int main()
{
    ifstream f("commas.in");
    ofstream g("commas.out");
    f>>n;
    nr=strlen(n);
    if (nr<=3) g<<n;
    else {
        if (nr%3==0) {
            for (i=0;i<=nr-1;i++) {
                g<<n[i];
                if ((i+1)%3==0&&i!=nr-1) g<<',';
            }
        }
        else
            if (nr%3==1) {
                g<<n[0]<<',';
                for (i=1;i<=nr-1;i++) {
                    g<<n[i];
                    if (i%3==0 &&i!=nr-1) g<<',';
                }
            }
        else
            if (nr%3==2) {
                g<<n[0]<<n[1]<<',';
                for (i=2;i<=nr-1;i++) {
                    g<<n[i];
                    if (i%3==1 &&i!=nr-1) g<<',';
                }
            }
    }

    f.close();
    g.close();
    return 0;
}
