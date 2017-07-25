#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;
#define sd(x) scanf("%d", &x)
#define F first

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

#define N 112345

int x[N], y[N];

int main(){
    int n;
    int px, py;
    int i;
    double mind, maxd;
    mind = INF;
    maxd = 0;
    sd(n); sd(px); sd(py);
    for(i = 0; i < n; ++i){
        sd(x[i]); sd(y[i]);
    }
    x[n] = x[0];
    y[n] = y[0];
    
    cout<<setprecision(20);
    double pi = acos(0) * 2;
    
    
    for(i = 0; i < n; ++i){
        mind = min(mind, DistancePointSegment(PT(x[i], y[i]), PT(x[i + 1], y[i + 1]), PT(px, py)));
        maxd = max(maxd, sqrt(dist2(PT(x[i], y[i]), PT(px, py))));
        
        cout << i << " " <<  pi*maxd*maxd << " " << pi*mind*mind << endl;
        
    }
    
    cout<<pi * (maxd * maxd - mind * mind)<<endl;
    return 0;
}
