#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<utility>
#include<sstream>
#include<iterator>
#include<functional>
#include<numeric>
#include<iomanip>
#include<ctime>
#include<climits>
#include<cctype>
#include<cassert>
#include<complex>
#include<stdlib.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define pd(x) printf("%d", x)
#define pdn(x) printf("%d\n", x)
#define plld(x) printf("%I64d", x)
#define plldn(x) printf("%I64d\n", x)
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z); //spaces should not be there to avoid tle
#define slld(x) scanf("%I64d",&x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

/*
ifstream fin("input.txt");
ofstream fout("output.txt");
freopen("input.txt", "exitTime", stdin);
freopen("output.txt", "w", stdout);
*/

const int MAXN = 500001, MAXM = 1001;
vector<int> graph[MAXN];
vector<pair<int, pair<int, int> > > roads, joints;
int visitTime[MAXN], exitTime[MAXN], tme;

void dfs(int cur, int prev)
{
	int nxt;
	visitTime[cur] = ++tme;
	foreach(it, graph[cur])
	{
		nxt = *it;
		if(nxt == prev) 
			continue;
		dfs(nxt, cur);
	}
	exitTime[cur] = ++tme;
}

int main()
{
	FASTER; 
	int t, n, m, i, j, k, a, b, c, d, u, v, x, y;
	long long result = 0, tot;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin>>n>>m;
		for(i = 1; i <= n; i++)
			graph[i].clear();
		joints.clear();
		roads.clear();
		for(i = 1; i < n; i++)
		{
			cin>>a>>b>>d;
			graph[a].pb(b);
			graph[b].pb(a);
			joints.pb(mp(d, mp(a,b)));
		}
		dfs(1,-1);
		for(i = 0; i < m; i++)
		{
			cin>>u>>v>>c;
			roads.pb(mp(c,mp(u,v)));
		}
		long long limit = 1ll << m;
		int counts, capacity;
		for(i = 1; i < limit; i++)
		{
			bool flag = true;
			tot = 0;
			for(k = 0; k < m; k++)
			{
				if(i&(1ll<<k)) 
					tot += roads[k].first;
			}
			if(tot <= result) 
				continue;
			for(j = 0; j < n-1; j++)
			{
				counts = 0;
				capacity = joints[j].first;
				x = joints[j].second.first;
				y = joints[j].second.second;
				if(visitTime[x] > visitTime[y]) 
					swap(x,y);
				for(k = 0; k < m; k++)
				{
					if((i&(1ll<<k))){
						u = roads[k].second.first;
						v = roads[k].second.second;
						if(visitTime[u] <= visitTime[x] and visitTime[y] <= visitTime[v] and visitTime[v] < exitTime[y]) 
							counts++;
					}
					if(counts > capacity)
						break;
				}
				if(counts > capacity)
				{
					flag = false;
					break;
				}
			}
			if(flag) 
				result = tot;
		}
		printf("%lld\n", result);
	}
	return 0;
}
