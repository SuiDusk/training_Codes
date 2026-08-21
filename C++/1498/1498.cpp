#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[1030]={1};
int main(){
    scanf("%d",&n);
    for(int i=0;i<1<<n;i++){
        for(int j=1;j<(1<<n)-i;j++) printf(" ");
        for(int j=i;j>=0;j--) a[j]^=a[j-1];
        if(!(i%2)) for(int j=0;j<=i;j++) a[j]?printf("/\\"):printf("  ");
        else for(int j=0;j<=i;j+=2) a[j]?printf("/__\\"):printf("    ");
        printf("\n");
    }
    return 0;
}