#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 333;

struct Point
{
	double x, y;

	Point() : x(), y() {}
	Point (double _x, double _y) : x(_x), y(_y) {}

	Point operator + (Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator * (double k)
	{
		return Point(x * k, y * k);
	}
	double operator % (Point a)
	{
		return x * a.x + y * a.y;
	}
	double operator * (Point a)
	{
		return x * a.y - y * a.x;
	}
	double sqLen()
	{
		return *this % *this;
	}
	double len()
	{
		return sqrt(sqLen());
	}

	void scan()
	{
		scanf("%lf%lf", &x, &y);
	}
};

Point a[N];
double r[N];
vector<int> g[N];
int n;
int par[N];
int sz[N];
int c[N];
bool used[N];
int m;
int p[N];

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].scan();
		scanf("%lf", &r[i]);
	}
	Point O;
	O.scan();
	double _r;
	scanf("%lf", &_r);
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i] - O;
		r[i] += _r;
	}
	return;
}

int getPar(int v)
{
	return (par[v] == -1 ? v : par[v] = getPar(par[v]));
}

void dfs(int v)
{
	used[v] = true;
	for (int u : g[v])
	{
		if (used[u]) continue;
		p[u] = v;
		dfs(u);
	}
}

void getPath(int v, int u)
{
	for (int i = 0; i < n; i++)
	{
		used[i] = 0;
		p[v] = -1;
	}
	dfs(v);
	if (p[u] == -1) return;
	m = 0;
	while(u != v)
	{
		c[m++] = u;
		u = p[u];
	}
	c[m++] = v;
	return;
}

double getAngle(Point v, Point u)
{
	return atan2(v * u, v % u);
}

bool inside()
{
/*	printf("CHECK\n");
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", c[i]);
	printf("\n");*/
	
	for(int i = 0; i < m; i++){
		cout << a[i].x << ' ' << a[i].y << endl;
	}
	
	double ang = 0;
	for (int i = 0; i < m; i++)
		ang += getAngle(a[c[i]], a[c[(i + 1) % m]]);
	return fabs(ang) > 1;
}

bool solve()
{
	for (int i = 0; i < n; i++)
	{
		par[i] = -1;
		sz[i] = 1;
	}
	for (int v = 0; v < n; v++)
		for (int u = v + 1; u < n; u++)
		{
			double L = (a[v] - a[u]).sqLen();
			double L2 = (r[v] + r[u]) * (r[v] + r[u]);
			if (L2 <= L + 1e-8) continue;
			int pv = getPar(v), pu = getPar(u);
			if (pv != pu)
			{
				cout << v << ' ' << u << endl;
				g[v].push_back(u);
				g[u].push_back(v);
				v = pv;
				u = pu;
				if (sz[v] < sz[u]) swap(v, u);
				par[u] = v;
				sz[v] += sz[u];
				continue;
			}
			getPath(v, u);
			if (inside())
				return false;
		}
	return true;
}

int main()
{
//	freopen("out.in", "r", stdin);
//	freopen("out.out", "w", stdout);

	read();
	if (solve())
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
