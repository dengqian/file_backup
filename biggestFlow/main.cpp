#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INF 0x7FFFFFFF
#define N 210

using namespace std;

int n, m, vol[N][N], path[N], flow[N], start, end;
queue<int> q;

int bfs(){
    int s;
    memset(path, -1, sizeof(path));
	path[start] = 0;
    while(!q.empty()){
        q.pop();
    }
    q.push(start);
    while(!q.empty()){
        s = q.front();
        if(s == end){
            break;
        }
        q.pop();
        for(int i=1; i<=m; i++){
            if(i!= s && path[i] == -1 && vol[s][i]){
                path[i] = s;
                q.push(i);
                flow[i] = flow[s] < vol[s][i] ? flow[s] : vol[s][i];
            }
        }
    }
    if(path[end] == -1){
        return 0;
    }
    return flow[end];
}

int EK(){
    int total = 0;
    int t, s, temp;
    while((temp = bfs()) != 0){
		 for(int j=1; j<=m; j++){
            cout<<path[j]<<" ";

        }
        cout<<endl;
        for(int fj=1; fj<=m; fj++){
            cout<<flow[fj]<<" ";

        }
		cout<<endl;
        total += temp;
        t = end;
        s = end;
        while(s != start){
            s = path[t];
            vol[s][t] -= temp;
            vol[t][s] += temp;
            t = s;
        }
    }
    return total;
}

int main()
{
    int s,t,v;
    start = 1;
    path[start] = 0;
    flow[start] = INF;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(vol, 0, sizeof(vol));
        end = m;
        for(int i=0; i<n; i++){
            scanf("%d%d%d", &s, &t, &v);
            vol[s][t] += v;
        }
        int ans = EK();
        printf("%d\n", ans);
    }
    return 0;
}
