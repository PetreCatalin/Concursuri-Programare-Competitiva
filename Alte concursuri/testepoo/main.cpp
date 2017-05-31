#include <iostream>

using namespace std;

class cls { static int i;        int j; public: cls(int x=7) { j=x; }         static int imp(int k){ return i+k+j; } };       int cls::i;       int main()  { int k=5;         cout<<cls::imp(k);         return 0;  }
