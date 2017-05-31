#include <bits/stdc++.h>

using namespace std;

long long t,i,j,C,D,V,x,nr,suma;
vector <long long> S;

int main() {
    ifstream f("lmmp.in");
    ofstream g("lmmp.out");
    f>>t;
    for (int j=1;j<=t;++j) {
        f>>C>>D>>V;
        S.clear();

        for (i=0;i<D;++i) {
            f>>x;
            S.push_back(x);
        }

       nr=0;suma=0;i=0;
       while (suma<V) {
            if (i<D && S[i]<=suma+1) { //cat timp am valori din cele initiale pe care nu le-am folosit,actualizam suma la care putem ajunge cu S[i]*C
                    suma+=S[i]*C;
                    ++i;
            }
            else {   //nu putem produce suma+1,deci adaugam o noua valoare(suma+1) si actualizam suma maxima la care putem ajunge
                ++nr;
                suma=suma+(suma+1)*C;
            }
       }

        g<<"Case #"<<j<<": "<<nr<<'\n';
    }

    f.close();
    g.close();
    return 0;
}
