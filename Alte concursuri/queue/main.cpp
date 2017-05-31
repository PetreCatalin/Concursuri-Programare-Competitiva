#include <fstream>
#include <vector>

using namespace std;

vector <long> s1,s2;

long n,i,poz,nr,j;
char s[25];

int main()
{
    ifstream f("queue.in");
    ofstream g("queue.out");
    f>>n;
    for (i=1;i<=n;++i) {
        f>>s;

        if (s[1]=='u') {
            poz=10;nr=0;
            while (s[poz]>='0' &&s[poz]<='9') {
                nr=nr*10+(s[poz]-'0');
                ++poz;
            }

        g<<i<<": read("<<nr<<") "<<"push(1,"<<nr<<')'<<'\n';
        s1.push_back(nr);
        }

        else
        if (s[1]=='o') {
            if (s2.size()==0) {
                g<<i<<": ";
                for (j=s1.size()-1;j>=1;--j) {
                    g<<"pop(1) push(2,";
                    g<<s1[j];
                    s2.push_back(s1[j]);
                    s1.pop_back();
                    g<<") ";
                }
                g<<"pop(1) write(";
                g<<s1[0]<<')'<<'\n';
                s1.pop_back();
            }

            else {
                g<<i<<": pop(2) write(";
                g<<s2.back()<<')'<<'\n';
                s2.pop_back();
            }
        }

    }

    f.close();
    g.close();
    return 0;
}
