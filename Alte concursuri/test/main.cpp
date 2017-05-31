#include <iostream>
#include <cstring>
using namespace std;

char s[100];
int x,i;

int main()
{
    cout<<"Va rugam raspundeti la urmatorul chestionar "<<'\n'<<'\n';
    cout<<"Ce va place sa beti dintre:"<<'\n'<<"a)palinca;"<<'\n'<<"b)vin;"<<'\n'<<"c)bere;"<<'\n'<<"d)sampanie"<<'\n';
    cout<<"Va rugam sa precizati numele bauturii,nu varianta de raspuns "<<'\n';
    cin>>s;
    x=1;
    while (s[0]!='t'&&s[1]!='o') {
        if (s[0]=='p') cout<<"Nu cred eu ca va place doar palinca"<<'\n'<<"Spuneti adevarul"<<'\n'<<'\n';
        if (s[0]=='v') cout<<"Nu cred eu ca va place doar vinul"<<'\n'<<"Spuneti adevarul"<<'\n'<<'\n';
        if (s[0]=='b') cout<<"Nu cred eu ca va place doar berea"<<'\n'<<"Spuneti adevarul"<<'\n'<<'\n';
        if (s[0]=='s') cout<<"Nu cred eu ca va place doar sampania"<<'\n'<<"Spuneti adevarul"<<'\n'<<'\n';
        cin>>s;
    }
    cout<<"Este ca iti plac toate???"<<'\n'<<'\n';
    cin>>s;
    cout<<'\n';
    for (i=1;i<=8;i++)
    cout<<"CE ITI MAI PLACE BAUTURA!!!!"<<'\n';
    return 0;
}
