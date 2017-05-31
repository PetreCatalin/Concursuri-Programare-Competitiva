#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int,char> >v;
int s,i,maxim,n;
vector <pair <char,char> > graf;
bool ok;

ifstream f("hh.in");
ofstream g("hh.out");

void citire()
{
    int x;
    f>>n;
    for (int i=0;i<n;++i) {
        f>>x;
        v.push_back(make_pair(x,'a'+i));
    }
}

void afisare()
{
    for (vector <pair <char,char> >::iterator it=graf.begin();it!=graf.end();++it)
        g<<it->first<<" "<<it->second<<"\n";
}


bool cmp(pair <int,char> a,pair <int,char> b)
{
    return a.first>b.first;
}

int main()
{
    citire();

    for (i=0;i<n;++i)
        s+=v[i].first;
    if (s%2==1) g<<"Sirul nu este un multiset grafic";
    else {
        sort(v.begin(),v.end(),cmp);
        if (v[0].first>n-1 ||v[n-1].first<0) g<<"Sirul nu este un multiset grafic";

        else {
            ok=true;
            while (ok==true) {
                maxim=v[0].first;
                for (i=1;i<=maxim;++i) {
                    --v[i].first;
                    graf.push_back(make_pair(v[0].second,v[i].second));
                }
                v[0].first=0;

                sort(v.begin(),v.end(),cmp);
                if (v[0].first==0) ok=false;
                if (v[n-1].first<0) ok=false;
            }

            ok=true;
            for (i=0;i<n;++i)
                if (v[i].first!=0) {ok=false;break;}

            if (ok==false) g<<"Sirul nu este un multiset grafic";
            else
            afisare();
        }
    }

    f.close();
    g.close();
    return 0;
}
