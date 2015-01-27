#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#define INF INT_MAX
#define maxn 150 

using namespace std;
struct Edge{
	int from, to, cap, flow, cost;
	Edge(int from, int to, int cap, int flow, int cost):
		from(from), to(to), cap(cap), flow(flow), cost(cost){}
};

struct MCMF{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	void init(int n){
		this->n = n;
		for(int i=0; i<n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap, int cost){
		edges.push_back( Edge(from, to, cap, 0, cost));
		edges.push_back( Edge(to, from, 0, 0, -cost));
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool BellmanFord(int s, int t, int &flow, int &cost){
		for(int i=0; i<n; i++) d[i] = INF;
		memset(inq, 0, sizeof(inq));
		d[s]=0; inq[s]=1; p[s]=0; a[s]=INF;
		
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			inq[u] = 0;
			for(int i=0; i<G[u].size(); i++){
				Edge &e = edges[ G[u][i] ];
				if( e.cap>e.flow && d[e.to]>d[u]+e.cost){
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap-e.flow);
					if(!inq[e.to]){
						Q.push(e.to);
						inq[ e.to ] = 1;
					}
				}
			}
		}
		if(d[t] == INF) return false;
		if(d[t] >= 0) return false;
		flow += a[t];
		cost += a[t] * d[t];
		int u = t;
		while(u != s){
			edges[ p[u] ].flow += a[t];
			edges[ p[u]^1 ].flow -= a[t];
			u = edges[ p[u] ].from;
		}
		return true;
	}
	int Mincost(int s, int t){
		int flow = 0, cost = 0;
		while(BellmanFord(s, t, flow, cost));
		return cost;
	}
};

int main (){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		MCMF F;
		F.init(n+1);
		for(int i=2; i<=n; i++){
			int a;
			scanf("%d", &a);
			F.AddEdge(i, 0, INF, -a);
		}
		for(int i=0; i<m; i++){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			F.AddEdge(a, b, c, d);
			F.AddEdge(b, a, c, d);
		}
		cout << -F.Mincost(1, 0) << endl;
	}
    return 0;
}
