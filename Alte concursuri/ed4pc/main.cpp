#include <bits/stdc++.h>

using namespace std;

long long nr,i,nr1,nr2,ok,x;
char s[1000005];
stack <char> st;

int main()
{
    cin>>s;x=strlen(s)-1;
    for (i=0;i<=x;++i) {
            if (s[i]=='(' ||s[i]=='{' ||s[i]=='[' ||s[i]=='<') ++nr1;
            else
            ++nr2;
            if (nr2>nr1) {ok=1;break;}
    }

    if (nr1!=nr2 ||ok==1) cout<<"Impossible";
    else {
    for (i=0;i<=x;++i) {
    if (s[i]=='(' ||s[i]=='{' ||s[i]=='[' ||s[i]=='<')
            st.push(s[i]);
    else {
        if (s[i]==')' &&st.top()=='(') st.pop();
        else
        if (s[i]=='}' &&st.top()=='{') st.pop();
        else
        if (s[i]==']' &&st.top()=='[') st.pop();
        else
        if (s[i]=='>' &&st.top()=='<') st.pop();
        else {
           st.pop();++nr;
        }
    }
    }

    cout<<nr;
    }
    return 0;
}
