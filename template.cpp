#include<bits/stdc++.h>
using namespace std;
template <typename T>

void swap(T& a, T& b){
    T temp = a;
    a=b;
    b=a;
}

// void swap(int& a, int& b){
//     int temp = a;
//     a=b;
//     b=a;
// }
// void swap(char& a, char& b){
//     char temp = a;
//     a=b;
//     b=a;
// }

int man(){
    int a=2,b=3;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    char c='c',d='d';
    swap(c,d);
    cout<<c<<" "<<d<<endl;
}