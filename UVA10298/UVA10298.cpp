#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e6+5;
char s[MAXN];
int nxt[MAXN];
int main(){
    while(1){
        scanf("%s",s);
        if(s[0]=='.') break;
        int len=strlen(s);
        int k=-1;
        nxt[0]=-1;
        for(int i=1;i<len;i++){
            while(k!=-1&&s[i]!=s[k+1])k=nxt[k];
            if(s[i]==s[k+1])k++;
            nxt[i]=k;
        }
        int n=len-1;
        if((n+1)%(n-nxt[n])==0)
            printf("%d\n",((n+1)/(n-nxt[n])));
        else printf("1\n");
    }
    return 0;
}