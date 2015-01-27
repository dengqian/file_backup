#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#define N 210
#define M 1010
#define INF 1000000


using namespace std;

struct edge
{
    int from;
    int to;
    int speed;
};

int fn[N];
edge e[M];

bool cmp(edge a, edge b)
{
    return a.speed < b.speed;
}

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        fn[i] = i;
    }
}

int root(int x)
{
    return x == fn[x] ? x : fn[x] = root(fn[x]);
}

void Union(int a, int b)
{
    int aa = root(a);
    int bb = root(b);
    if(aa != bb)
    {
        fn[bb] = aa;
    }
}

int main()
{
    int n;
    int m;
    int q;
    while(scanf("%d%d", &n, &m) != EOF )
    {
        int cnt = 0;
        int num = 0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].speed);
        }
        sort(e, e+m, cmp);
        scanf("%d", &q);
        for(int j=0; j<q; j++)
        {
            int ans = INF;
            int from,to;
            scanf("%d%d", &from, &to);
            for(int ii=0; ii<m; ii++)
            {
                init(n);
                for(int jj=ii; jj<m; jj++)
                {
                    Union(e[jj].from,e[jj].to);
                    if(root(from) == root(to))
                    {
                        if(e[jj].speed - e[ii].speed < ans)
                        {
                            ans = e[jj].speed - e[ii].speed;
                            //   printf("%d\n",ans);
                        }
                        break;
                    }
                }
            }
            if(ans == INF)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
