#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#define L 1000000000
#define N 50000

using namespace std;

int dis[N+2] = {0};
int l, n, m;

bool cmp(int a, int b){
    return a <= b;
}
bool isDisOk(int x){
    int cnt = 0;
    int i = 1;
    int temp = 0;
    while(i < n+2){
        temp += dis[i] - dis[i-1];
        if(temp <= x){
            i++;
            cnt++;
        }else{
            i++;
            temp = 0;
        }
    }
    if(cnt > m){
        return true;
    }else{
        return false;
    }
}
int find(int l, int r){
    int ans = l;
    while(l <= r){
        int mid = (l + r) >> 1;
        //printf("l:%dr:%d\n", l, r);
        if(isDisOk(mid)){
            ans = mid;
        //    printf("ans:%d\n", ans);
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}
int main(){
    while(scanf("%d%d%d", &l, &n, &m) != EOF){
        for(int i=1; i<=n; i++){
            scanf("%d", &dis[i]);
        }
        dis[n+1] = l;
        sort(dis, dis+n+2, cmp);
        int minDis = l;
        for(int j=1; j<n+2; j++){
            if(dis[j] - dis[j-1] < minDis){
                minDis = dis[j] - dis[j-1];
            }
        }
        int res = find(minDis, l);
        printf("%d\n", res);
    }
    return 0;
}
