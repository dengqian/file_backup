#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define N 50000000

using namespace std;

int f[20][4];

int slv(long long x){
    int cnt = 0;
    int a = 1;
    for(int i=0; a<=x; i++){
       a *= 10;
    }
    a = a/10;
    int t,aa = a;

}

long long divide(long long l, long long r, int n){
    long long ans = -1;
    while(l <= r){
        long long mid = (l + r) >> 1;
        if(slv(mid) <= n){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    f[1][0] = 8;
    f[1][1] = 1;
    f[1][2] = 0;
    f[1][3] = 0;
    for(int i=2; i<20; i++){
        f[i][0] = (f[i-1][0] + f[i-1][1] + f[i-1][2]) * 8;
        f[i][1] = f[i-1][0];
        f[i][2] = f[i-1][1];
        f[i][3] = f[i-1][2] + f[i-1][3] * 9;
    }
    int t,n;
    while(cin>>t){
        for(int i=0; i<t; i++){
            cin>>n;
            long long ans = slv(n);
            cout<<ans<<endl;
        }
    }
    return 0;
}
