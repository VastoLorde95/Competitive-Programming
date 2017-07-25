#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define INF 5e18
typedef long double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};
 
T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
 
 
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
}
 
 
int pointer[2]; //Keeps track of the best line from previous query
vector<long long> M[2]; //Holds the slopes of the lines in the envelope
vector<long long> B[2]; //Holds the y-intercepts of the lines in the envelope
//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3,bool f)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (B[f][l3]-B[f][l1])*(M[f][l1]-M[f][l2])<(B[f][l2]-B[f][l1])*(M[f][l1]-M[f][l3]);
}
//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b,bool f)
{
	//First, let's add it to the end
	M[f].push_back(m);
	B[f].push_back(b);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M[f].size()>=3&&bad(M[f].size()-3,M[f].size()-2,M[f].size()-1,f))
	{
		M[f].erase(M[f].end()-2);
		B[f].erase(B[f].end()-2);
	}
}
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long double Query(long double x,bool f)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer[f]>=M[f].size())
		pointer[f]=M[f].size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer[f]<M[f].size()-1&&
	  M[f][pointer[f]+1]*x+B[f][pointer[f]+1]<M[f][pointer[f]]*x+B[f][pointer[f]])
		pointer[f]++;
	return M[f][pointer[f]]*x+B[f][pointer[f]];
}
 
long double ComputeSignedArea(const vector<PT> &p) {
  long double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}
 
long double ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}
long double square(ll X)
{
	return X*X;
}
long double dist(ll X1,ll Y1,ll X2,ll Y2)
{
	return sqrt(square(X2-X1)+square(Y2-Y1));
}
ll x[100010],y[100010];
ll X[100010],Y[100010];
pair<ll,ll> arr[100010];
ll a[100010],b[100010],c[100010];
set<pair<ll,ll> > sett;
pair<long double,int> query[100010];
long double ans[100010];
int main()
{
	int t, n,i;
	sd(t);
	while(t--)
	{
		M[0].clear(), M[1].clear();
		B[0].clear(), B[1].clear();
		pointer[0] = pointer[1] = 0;
		sd(n);
		vector<PT> v;
		v.clear();
		for(i=0;i<n;++i)
		{
			sl(X[i]);
			sl(Y[i]);
			arr[i]=MP(X[i],Y[i]);
			PT pt(X[i],Y[i]);
			v.PB(pt);
		}
		ConvexHull(v);
		if(v.size()==n)
		{
			printf("%d\n",-1);
			continue;
		}
		long double area=ComputeArea(v);
		int sz=(int)v.size();
		sett.clear();
		for(i=0;i<sz;++i)
		{
			if(v[i].x<0)
				x[i]=v[i].x-0.5;
			else
				x[i]=v[i].x+0.5;
			
			if(v[i].y<0)
				y[i]=v[i].y-0.5;
			else
				y[i]=v[i].y+0.5;
 
			//cout<<x[i]<<' '<<y[i]<<'\n';
			sett.insert(MP(x[i],y[i]));
		}
		for(i=0;i<sz;++i)
		{
			a[i]=y[(i+1)%sz]-y[i];
			b[i]=x[i]-x[(i+1)%sz];
			c[i]=y[i]*x[(i+1)%sz]-y[(i+1)%sz]*x[i];
			if(a[i]*x[(i+2)%sz]+b[i]*y[(i+2)%sz]+c[i]<0)
			{
				a[i]=-a[i];
				b[i]=-b[i];
				c[i]=-c[i];
			}
		}
		sort(arr,arr+n);
		reverse(arr,arr+n);
		ll minx=INF,maxx=-INF;
		for(i=0;i<n;++i)
		{
			if(sett.find(arr[i])==sett.end())
			{
				add(arr[i].F,arr[i].S,0);
				minx=min(minx,arr[i].F);
				maxx=max(maxx,arr[i].F);
			}
		}
		for(i=n-1;i>=0;--i)
		{
			if(sett.find(arr[i])==sett.end())
			{
				add(-arr[i].F,-arr[i].S,1);
			}
		}
 
		for(i=0;i<sz;++i)
		{
			query[i].S=i;
			if(b[i]==0)
			{
				query[i].F=INF;
				if(a[i]<0)
					ans[i]=a[i]*maxx+c[i];
				else
					ans[i]=a[i]*minx+c[i];
			}
			else
				query[i].F=((long double)a[i])/((long double)b[i]);
		}
		sort(query,query+sz);
		for(i=0;i<sz;++i)
		{
			if(query[i].F+1>=INF)
				continue;
			long double val;
			if(b[query[i].S]>0)
				val=Query(query[i].F,0);
			else
				val=-Query(query[i].F,1);
			val=val*b[query[i].S]+c[query[i].S];
			ans[query[i].S]=val;
		}
		long double min_area=INF;
		for(i=0;i<sz;++i)
		{
			long double area1=ans[i]/sqrt(a[i]*a[i]+b[i]*b[i]);
			area1=area1*dist(x[i],y[i],x[(i+1)%sz],y[(i+1)%sz])*.5;
			//cout<<"p1: "<<x[i]<<' '<<y[i]<<' '<<"p2: "<<x[(i+1)%sz]<<' '<<y[(i+1)%sz]<<"area1: "<<area1<<'\n';
			min_area=min(min_area,area1);
		}
		area-=min_area;
		area=area*2;
		ll out=area+0.5;
		printf("%lld\n",out);
	}
} 
