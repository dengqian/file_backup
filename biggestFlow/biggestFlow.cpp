#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define N 210

using namespace std;

struct Node {
	int from;
	int to;
	int cap;
	int next;
};

Node node[N*N];
int id, head[N], m, n;
int path[N], pre[N], flow[N];
void init()
{
	memset(head, 0, sizeof(head));
	memset(node, 0, sizeof(node));
	for(int i=0; i<=n; i++){
		flow[i] = INT_MAX;
	}
	id = 1;
}

void add(int s, int e, int cap)
{
	node[id].from = s;
	node[id].to = e;
	node[id].cap += cap;
	node[id].next = head[s];
	head[s] = id;
	id++;

	node[id].from = e;
	node[id].to = s;
	node[id].cap += 0;
	node[id].next = head[e];
	head[e] = id;
	id++;
}
int bfs(int s, int e){
	queue<int> q;
	memset(path, -1, sizeof(path));
	memset(pre, 0, sizeof(pre));
	path[s] = 0;
	while(!q.empty()){
		q.pop();
	}
	q.push(s);
	int st, from, to, cap;
	while(!q.empty()){
		st = q.front();
	//	cout<<st<<endl;
		if(st == e){
			break;
		}
		q.pop();
		int i = head[st];
		while(i != 0){
			Node tempnode = node[i];
			from = tempnode.from;
			to = tempnode.to;
			cap = tempnode.cap;
			if(path[to] == -1 && cap){
				path[to] = from;
				pre[to] = i;
				q.push(to);
				flow[to] = flow[from] < cap ? flow[from] : cap;
			}
			i = tempnode.next;
		}
	}
   /*     for(int j=1; j<=n; j++){
            cout<<path[j]<<" ";
        }
        cout<<endl<<"flow:";
        for(int fj=1; fj<=n; fj++){
            cout<<flow[fj]<<" ";
		}*/
	//	cout<<endl;
	if(path[e] == -1)
		return 0;
	return flow[e];
}

int maxflow(int s, int e){
	int total = 0;
	int temp;
	while((temp = bfs(s, e)) != 0){
		total += temp;
		int st = e;
		int p = e;
		while(st != s){
			p = pre[st];
			node[p].cap -= temp;
			node[p^1].cap += temp;	
			st = path[st];
		}
	}
	return total;
}
int main()
{
	int s, e, c;
	while(scanf("%d%d", &m, &n) != EOF){
		init();
		for(int i=0; i<m; i++){
			scanf("%d%d%d", &s, &e, &c);
			add(s, e, c);
		}
		int ans = maxflow(1, n);
		printf("%d\n", ans);
	}
}
