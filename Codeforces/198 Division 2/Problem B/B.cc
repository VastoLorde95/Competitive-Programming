#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

int n, x, y;
pair<int, int> pts[300];
double d[300][300], mx, a1, a2, tmp1, tmp2;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int area = (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
	if (area > 0)
		return -1;
	else if (area < 0)
		return 1;
	return 0;
}


int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		pts[i] = make_pair(x,y);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			double tmp = sqrt(((pts[i].fi - pts[j].fi)*(pts[i].fi - pts[j].fi)) + ((pts[i].se - pts[j].se)*(pts[i].se - pts[j].se)));
			d[i][j] = d[j][i] = tmp;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a1 = a2 = 0;
			for(int k = 0; k < n; k++){
				if(k != i and k != j){
					int turn = ccw(pts[k], pts[i], pts[j]);
					if(turn > 0){
						double s = ((d[i][k] + d[k][j] + d[j][i])/2);
						tmp1 = sqrt(s*(s-d[i][k])*(s-d[k][j])*(s-d[j][i]));
						if(tmp1 > a1){
							a1 = tmp1;
						}
					}
					else if(turn < 0){
						double s = ((d[i][k] + d[k][j] + d[j][i])/2);
						tmp2 = sqrt(s*(s-d[i][k])*(s-d[k][j])*(s-d[j][i]));
						if(tmp2 > a2){
							a2 = tmp2;
						}
					}	
				}
			}
			
			if((a1 + a2) > mx and a1 > 0 and a2 > 0){
				mx = a1 + a2;
			}
		}
	}
	
	printf("%.17lf\n",mx);
	
	
	return 0;
}
