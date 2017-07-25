#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cassert>
#define rf freopen("in.in", "r", stdin)
#define wf freopen("out.out", "w", stdout)
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e5 + 10, mod = 1e9+7;
#define mp make_pair
#define pi pair<int, int>
#define ms(a, v) memset(a, int(v), sizeof(a))
 
static int C[mx], A, B, P;
int n, t, q, qs, qe, val, chno=1, idx=0;
int neg_inf = -2e9;
 
static int pos[mx], wc[mx], chain[mx], leaf_val[mx],
           l[mx], lca[mx][20], ch[mx], vis[mx], p[mx];
 
struct node
{
	int max_alive, number_alive, lazy_update_val;
} st[mx*4];
 
vector<int> g[mx];
int cmp(int l, int r)
{
	return ch[l]>ch[r];
}
 
/*----------Segment tree functions-----------*/
 
void merge(int r)
{
	st[r].number_alive = st[2*r].number_alive + st[2*r+1].number_alive;
	st[r].max_alive = max(st[2*r].max_alive, st[2*r+1].max_alive) + st[r].lazy_update_val;
} 
 
void build(int x, int y, int r)
{
	if(x == y)
	{
		st[r].max_alive = leaf_val[x];
		st[r].lazy_update_val = 0;
		st[r].number_alive = (leaf_val[x] < P);
		return;
	}
 
	int m = (x+y) >> 1;
	st[r].lazy_update_val = 0;
	build(x, m, 2*r); build(m+1, y, 2*r+1);
 
	merge(r);	
}
void up(int x, int y, int r)
{
	if(y<qs or qe<x or qs>qe)
		return;
 
	if(qs<=x && y<=qe)
	{
		st[r].lazy_update_val += val, st[r].max_alive += val;
		return;
	}
 
	int m=(x+y)>>1;
	up(x, m, 2*r); up(m+1, y, 2*r+1);
 
	merge(r);
}
 
void propagate(int x, int y, int r, int lazy)
{
	if(st[r].max_alive + lazy < P or !st[r].number_alive)
	{
		st[r].max_alive += lazy;
		st[r].lazy_update_val += lazy;
		return;
	}
 
	if(x==y)
	{
		if(st[r].max_alive + lazy >= P)
			st[r].max_alive = neg_inf, st[r].number_alive = 0;
		return;
	}
 
	int m = (x+y)>>1;
	lazy += st[r].lazy_update_val;
	st[r].lazy_update_val = 0;
 
	propagate(x, m, 2*r, lazy); propagate(m+1, y, 2*r+1, lazy);
	merge(r);
}
 
int qu(int x, int y, int r, int lazy)
{
	st[r].max_alive += lazy;
	st[r].lazy_update_val += lazy;
 
	if(y<qs || qe<x || qs>qe)
		return 0;
 
	if(qs<=x && y<=qe)
	{
		propagate(x, y, r, 0);
		return (y-x+1) - st[r].number_alive;
	}
 
	int m = (x+y)>>1;
	lazy = st[r].lazy_update_val;
	st[r].lazy_update_val = 0;
 
	int ret = qu(x, m, 2*r, lazy) + qu(m+1, y, 2*r+1, lazy);
	merge(r);
 
	return ret;
}
/*-----------------------------------------*/
 
/*-----------Lowest Common Ancestor---------*/
int lcanc(int x, int y)
{
	if(l[x]<l[y]) swap(x, y);
	while(l[x]>l[y])
	{
		int j=log2(l[x]-l[y]);
		x=lca[x][j];
	}
 
	int j=log2(l[x]);
	while(x!=y)
	{
		while(lca[x][j]==lca[y][j] && j)
			j--;
		x=lca[x][j], y=lca[y][j];
	}
	return x;
}
/*-----------------------------------------*/
 
/*-----------DFS to Preprocess---------*/
void dfs(int u)
{
	vis[u]=ch[u]=1;
	rep(i, 0, g[u].size()-1)
	{
		int v=g[u][i];
		if(vis[v]) continue;
 
		l[v]=l[u]+1;
		p[v]=lca[v][0]=u;
 
		int go=u, j=1;
		while(go!=-1)
		{
			go=lca[v][j]=lca[go][j-1];
			j++;
		}
 
		dfs(v);
		ch[u]+=ch[v];
	}
}
/*----------------------------------------------*/
 
/*------------Heavy Light Decomposition---------*/
 
void hld(int u)
{
	wc[u]=chno;
	pos[u]=++idx; leaf_val[idx] = C[u];
 
	for(int i=1; i<g[u].size(); ++i)
	{
		int v=g[u][i];
		if(i==1)
		{
			hld(v);
			continue;
		}
 
		chno++;
		chain[chno]=v;
		hld(v);
	}
}
/*------------------------------------------------*/
 
/*---------- UPDATE AND QUERY FUNCTIONS-----------*/
 
int updater(int a, int b, int chk)
{
	int ret=0;
	while(true)
	{
		if(wc[a]==wc[b])
		{
			qs=pos[b]+chk, qe=pos[a];
			up(1, n, 1);
			break;
		}
 
		int chnh=chain[wc[a]];
 
		qs=pos[chnh], qe=pos[a];
		up(1, n, 1);
 
		a=p[chnh];
	}
	return ret;
}
void update(int u, int v, int w)
{
	val = w;
	int anc = lcanc(u, v);
	updater(u, anc, 0); updater(v, anc, 1);
}
 
int getans(int a, int b, int chk)
{
	int ret=0;
	while(1)
	{
		if(wc[a]==wc[b])
		{
			qs=pos[b]+chk, qe=pos[a];
			ret += qu(1, n, 1, 0);
			break;
		}
 
		int chnh=chain[wc[a]];
 
		qs=pos[chnh], qe=pos[a];
		ret += qu(1, n, 1, 0);
 
		a=p[chnh];
	}
 
	return ret;
}
int query(int u, int v)
{
	int anc = lcanc(u, v);
	return getans(u, anc, 0) + getans(v, anc, 1);
}
/*----------------------------------------------*/
 
int main()
{
	//rf; wf;
 
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d", &n, &q, &A, &B);
		if(A == 0)
			P = (B>=0)? neg_inf: -1*neg_inf;
		else
			P = (B < 0)? ceil((-1.0*B)/A): (-B)/A;
 
		rep(i, 0, n)
		{
			g[i].clear(), vis[i]=0, ch[i]=0;
			rep(j, 0, 19)
				lca[i][j]=-1;
		}
		g[1].push_back(0);
		vis[0]=1, ch[0]=1e9;
 
		rep(i, 1, n)
			scanf("%d", &C[i]);
		rep(i, 1, n-1)
		{
			int u, v;
			scanf("%d %d", &u, &v);
 
			g[u].push_back(v);
			g[v].push_back(u);
		}
 
		dfs(1);
		rep(i, 1, n)
			sort(g[i].begin(), g[i].end(), cmp);
 
		chno=1, idx=0; chain[1]=1;
		hld(1);
		build(1, n, 1);
 
		while(q--)
		{
			int type, u, v, w;
			scanf("%d %d %d", &type, &u, &v);
 
			if(type == 1)
				scanf("%d", &w),
				update(u, v, w);
			else{
				int res = query(u, v);
				assert(res >= 0 and res <= n);
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
