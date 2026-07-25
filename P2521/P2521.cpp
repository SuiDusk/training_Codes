#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 1e6+10;
class mp{
public:
    const double inf = 1e100;
    const double fni = 1e10;
    class Point{
    public:
        double x,y;
        bool islim=0;
        Point()=default;
        Point(double x,double y):x(x),y(y){}
        Point operator + (Point b){
            return {x+b.x,y+b.y};
        }
        Point operator - (Point b){
            return {x-b.x,y-b.y};
        }
        double operator * (Point b){
            return x*b.y+y*b.x;
        }
        bool operator < (Point b)const{
            return x!=b.x?x<b.x:y<b.y;
        }
    };
    double cross(Point a,Point b){
        return a.x*b.y-a.y*b.x;
    }
    double cross(Point u,Point v,Point w){
        return cross(w-v,v-u);
    }
    set<Point> p;
    double C=0;

    void init(){
        p.clear();
        Point L={-fni,-inf},R={fni,-inf};
        L.islim=R.islim=1;
        p.insert(L),p.insert(R);
    }
    void update(Point u,Point v,int sgn){
        if(u.islim||v.islim) return ;
        C+=sgn*sqrt(pow((u-v).x,2)+pow((u-v).y,2));
    }
    void insert(Point u){
        p.insert(u);
        auto it=p.find(u); 
        auto pre=prev(it),nxt=next(it);
        if(cross(*pre,*it,*nxt)<=0){
            p.erase(it);
            return ;
        }
        update(*pre,*nxt,-1);
        update(*pre,*it,1);
        update(*it,*nxt,1);
        while(pre!=p.begin()){
            auto pp=prev(pre);
            if(cross(*pp,*pre,*it)<=0){
                update(*pp,*it,1);
                update(*pp,*pre,-1);
                update(*pre,*it,-1);
                p.erase(pre);
            } else {
                break;
            }
            pre=pp;
        }
        while(nxt!=--p.end()){
            auto qq=next(nxt);
            if(cross(*it,*nxt,*qq)<=0){
                update(*it,*qq,1);
                update(*it,*nxt,-1);
                update(*nxt,*qq,-1);
                p.erase(nxt);
            } else {
                break;
            }
            nxt=qq;
        }
    }
}G;
class query{
public:
    long long op,x;
    double ans;
};
long long n,x,y;
long long m,q;
mp::Point a[MAXN];
int vis[MAXN];
query qs[MAXN];
int main(){
    scanf("%lld %lld %lld",&n,&x,&y);
    G.init();
    G.insert({0,0});
    G.insert({(double)n,0});
    G.insert({(double)x,(double)y});
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        scanf("%lf %lf",&a[i].x,&a[i].y);
        vis[i]=1;
    }
    scanf("%lld",&q);
    for(int i=1;i<=q;i++){
        scanf("%lld",&qs[i].op);
        if(qs[i].op==1){
            scanf("%lld",&qs[i].x);
            vis[qs[i].x]=0;
        }
    }
    for(int i=1;i<=m;i++)
        if(vis[i]==1) G.insert(a[i]);
    for(int i=q;i>=1;i--){
        if(qs[i].op==1){
            vis[qs[i].x]=1;
            G.insert(a[qs[i].x]);
        } else {
            qs[i].ans=G.C;
        }
    }
    for(int i=1;i<=q;i++){
        if(qs[i].op==2)
            printf("%.2lf\n",qs[i].ans);
    }
    return 0;
}