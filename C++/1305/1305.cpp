#include <iostream>
#include <cstdio>
using namespace std;
int n;
int root;
string s;
class Node{
public:
    int l,r;
    Node(){l=-1,r=-1;};
};
Node node[30];
void dfs(int index);
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        if(i==1) root=s[0]-'a';
        if(s[1]!='*')
            node[s[0]-'a'].l=s[1]-'a';
        if(s[2]!='*')
            node[s[0]-'a'].r=s[2]-'a';
    }
    dfs(root);
    return 0;
}

void dfs(int index){
    printf("%c",index+'a');
    if(node[index].l!=-1) dfs(node[index].l);
    if(node[index].r!=-1) dfs(node[index].r);
}