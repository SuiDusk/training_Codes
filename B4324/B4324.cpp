#include <iostream>
using namespace std;
const int MAXN = 5e5+5;
const int R = MAXN-1;
int n,m;
int l[MAXN],r[MAXN];
bool del[MAXN];
void init(){
    r[0]=1;
    for(int i=1;i<=n;i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    r[n]=R;
    l[R]=n;
}
void erase(int x){
    if(x==0||x==R||del[x]) return ;
    del[x]=0;
    r[l[x]]=r[x];
    l[r[x]]=l[x];
}
void addleft(int x,int y){
    if(x==y) return ;
    erase(x);
    l[x]=l[y];
    r[l[y]]=x;
    r[x]=y;
    l[y]=x;
    del[x]=0;
}
void addright(int x,int y){
    if(x==y) return;
    erase(x);
    addleft(x,r[y]);
}
int main(){
    scanf("%d %d",&n,&m);
    init();
    int op,x,y;
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d %d",&x,&y);
            addleft(x,y);
        } else if(op==2){
            scanf("%d %d",&x,&y);
            addright(x,y);
        } else {
            scanf("%d",&x);
            erase(x);
        }
    }
    if(r[0]==R)
        printf("Empty!\n");
    else{
        for(int i=r[0];i!=R;i=r[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}