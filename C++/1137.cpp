#include<cstdio>
#include<iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int t0=0,t1=1,t2=1;
        if(n==0) return t0;
        if(n==1) return t1;
        if(n==2) return t2;
        for(int i=3;i<=n;i++){
            int t3=t0+t1+t2;
            t0=t1;t1=t2;t2=t3;
        }
        return t2;
    }
};

int main(){
    int n;
    scanf("%d",&n);
    Solution s;
    cout<<s.tribonacci(n)<<endl;
    return 0;
}