#include<iostream>
#include<stdio.h>
#include<limits>
#include<algorithm>
#include<vector>
#define N 1000

using namespace std;

int fa[N];
int m[27][27];

void init(){
    for(int i=0;i<N;i++){
        fa[i] = i;
    }
}

int root(int x){
    return x == fa[x] ? x : fa[x] = root(fa[x]);
}

void unin(int a,int b){
    int aa = root(a);
    int bb = root(b);
    if(aa != bb){
        fa[aa] = bb;
    }
}
int main(){
    int n;
    while(scanf("%d",&n) && n != 0){
        for(int i=0;i<n;i++){
            char a;
            int r;
            scanf("%c%d", &a,&r);
            int from = a - 'A';
            for(int j=0; j<r; j++){
                char b;
                int cost;
                scanf("%c%d",&b,&cost);
                int to = b - 'A';
                m[from][to] = cost;
                m[to][from] = cost;
            }
        }

    }
    return 0;
}
