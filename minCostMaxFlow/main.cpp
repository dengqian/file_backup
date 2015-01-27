#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <queue>
#define N 310
#define INF INT_MAX

using namespace std;

int id, beer[N], n, m;
struct Node{
    int from;
    int to;
    int cost;
    int cap;
    int next;
};
node Node[N];
int cost[N], path[N], vol[N], start, end;

void init(){
	memset(beer, 0, sizeof(beer));
	memset(node, 0, sizeof(node));
	id = 1;
}
void add(int s, int t, int cost, int cap){
    node[id].from = s;
    node[id].to = t;
    node[id].cost = cost;
    node[id].cap = cap;
    node[id].next = beer[s];
    beer[s] = id++;

    node[id].from = t;
    node[id].to = s;
    node[id].cost = -cost;
    node[id].cap = 0;
    node[id].next = beer[t];
    beer[t] = id++;
}

void bfs(){
    queue<int> q;
    memset(path, -1, sizeof(path));
    path[start] = 0;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == end){

        }
    }

}
int MinCostMaxFlow(int u, int v){
	return 0;
}
int main()
{
	init();
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i=2; i<n; i++){
			int cost;
			scanf("%d", &cost);
			add(i, n+1, cost, INF);
		}
		int from, to, cap, cost;
		for(int j=0; j<m; j++){
			scanf("%d%d%d%d", &from, &to, &cap, &cost);
			add(from, to, cost, cap);
			add(to, from, cost, cap);
		}
		for(int k=0; k<n; k++){
			cout<<beer[k]<<" ";
		}
		for(int ii=0; ii<id; ii++){
			cout<<node[ii].from<<" "<<node[ii].to<<" "<<node[ii].cost<<" "<<node[ii].cap<<" "<<node[ii].next<<" "<<endl;
		}
	}
    return 0;
}
