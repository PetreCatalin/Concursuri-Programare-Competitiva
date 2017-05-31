#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#define con 1000000
using namespace std;
//std::priority_queue<double, std::vector<double>, std::greater<double> > Q;
priority_queue< double> Q;
vector< double> V;
int n, i, j, k;
double x;
char s[11];
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int main()
{
    freopen("dstar.in", "r", stdin);
    freopen("dstar.out", "w", stdout);
    scanf("%d %d\n", &n ,&k);
    V.push_back(360);
    for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            char *p = s;
            int a = 0;
            x = 0;
            while (*p)
            {
                if (*p >='0' && *p <= '9') x = x * 10 + *p - '0', ++p;else
                    a = p - s, ++p;
            }
            a = strlen(s) - a - 1 ;
            x /= ten[a];
            V.push_back(x);
        }
    sort(V.begin(), V.end());
    int t = V.size();
    for (int i = 0; i < V.size() - 1; i++)
        Q.push((double)(V[i + 1] - V[i]));
    while (k)
    {
        k--;
        x = Q.top();
        Q.pop();
        Q.push(x / 2);
        Q.push(x / 2);
    }
    cout << setprecision(10) << Q.top();
   // printf("%lf\n", Q.top());
   return 0;
}


