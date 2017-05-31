#include <iostream>

using namespace std;

long n,u,z;

int main()
{
    cin>>n;
    z=n/10;
    u=n%10;
    if (z==0) {
            if (u==0) cout<<"zero";
            if (u==1) cout<<"one";
            if (u==2) cout<<"two";
            if (u==3) cout<<"three";
            if (u==4) cout<<"four";
            if (u==5) cout<<"five";
            if (u==6) cout<<"six";
            if (u==7) cout<<"seven";
            if (u==8) cout<<"eight";
            if (u==9) cout<<"nine";
            }
            else
        if (z==1) {
                if (n==10) cout<<"ten";
                if (n==11) cout<<"eleven";
                if (n==12) cout<<"twelve";
                if (n==13) cout<<"thirteen";
                if (n==14) cout<<"fourteen";
                if (n==15) cout<<"fifteen";
                if (n==16) cout<<"sixteen";
                if (n==17) cout<<"seventeen";
                if (n==18) cout<<"eighteen";
                if (n==19) cout<<"nineteen";
        }
        else {
                if (z==2) cout<<"twenty";
                if (z==3) cout<<"thirty";
                if (z==4) cout<<"forty";
                if (z==5) cout<<"fifty";
                if (z==6) cout<<"sixty";
                if (z==7) cout<<"seventy";
                if (z==8) cout<<"eighty";
                if (z==9) cout<<"ninety";
                if (u!=0) cout<<'-';
            if (u==1) cout<<"one";
            if (u==2) cout<<"two";
            if (u==3) cout<<"three";
            if (u==4) cout<<"four";
            if (u==5) cout<<"five";
            if (u==6) cout<<"six";
            if (u==7) cout<<"seven";
            if (u==8) cout<<"eight";
            if (u==9) cout<<"nine";
        }


    return 0;
}
