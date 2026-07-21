#include <iostream>
#include <cstdio>
using namespace std;
string a,b;
void div(int x,int y,int p,int q){
    if(x>y||p>q) return ;
    else {
        int i=b.find(a[x]);
        div(x+1,x+i-p,p,i-1);
        div(x+i-p+1,y,i+1,q);
        printf("%c",a[x]);
    }
}
int main(){
    cin>>b>>a;
    int l=a.length();
    div(0,l-1,0,l-1);
    return 0;
}