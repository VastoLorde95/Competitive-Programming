#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include <locale>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
	
	double w, h, a, d, x1, y1, m1, x2, y2, x3, x4, y3, y4, m2, PI, b, res, t;
	
	cin >> w >> h >> a;
	
	if(a == 0 or a == 180){
		printf("%.12lf\n", w*h);
		return 0;
	}
	if(a == 90){
		printf("%.12lf\n", min(w,h)*min(w,h));
		return 0;
	}
	
	if(a >= 90) a = 180 - a;
	if(w < h) swap(w,h);
	
	PI = acos(-1);
	b = atan2(h,w)*2.0;
	
	res = w*h;
	
	d = sqrt((w*w/4.0)+(h*h/4.0));
	
	t = (atan2(h,w)*180)/PI;
	
	x1 = d*cos((t+a)*PI/180.0);
	y1 = d*sin((t+a)*PI/180.0);
	
	x2 = d*cos((-t+a)*PI/180.0);
	y2 = d*sin((-t+a)*PI/180.0);
	
	x3 = d*cos((180-t+a)*PI/180.0);
	y3 = d*sin((180-t+a)*PI/180.0);
	
	x4 = d*cos((180+t+a)*PI/180.0);
	y4 = d*sin((180+t+a)*PI/180.0);
	
	if(((a*PI)/180.0) <= b){
		double yy1 = h/2.0;
		double xx1 = (((x1-x3)*(yy1-y1))/(y1-y3))+x1;
		
		double yy2 = h/2.0;
		double xx2 = (((x1-x2)*(yy2-y1))/(y1-y2))+x1;
		
		double xx3 = w/2.0;
		double yy3 = ((y1-y2)/(x1-x2))*(xx3-x1) + y1;
		
		double xx4 = w/2.0;
		double yy4 = ((y2-y4)/(x2-x4))*(xx4-x2) + y2;
		
		res = res - (dist(x1,y1,xx1,yy1)*dist(x1,y1,xx2,yy2) + dist(x2,y2,xx3,yy3)*dist(x2,y2,xx4,yy4));
		printf("%.12lf\n", res);
	}
	else{
		double yy1 = h/2.0;
		double xx1 = (((x1-x3)*(yy1-y1))/(y1-y3))+x1;
		
		double yy2 = h/2.0;
		double xx2 = (((x2-x4)*(yy2-y2))/(y2-y4))+x2;
		
		res = fabs(xx1-xx2)*h;
		printf("%.12lf\n", res);
	}
	
	return 0;
}
