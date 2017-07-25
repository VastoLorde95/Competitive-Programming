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

int n, m, s, f, cnt, cur, inc, a, b, d;
vector<pair<int, pair<int, int> > > c;

int main(){
	sd2(n,m); sd2(s,f);
	
	for(int i = 0; i < m; i++){
		sd3(a,b,d);
		c.push_back(make_pair(a, make_pair(b,d)));
	}
	
	cur = 0;
	cnt = 1;
	
	if(s < f) inc = 1; else inc = -1;
	
	while(s != f){
		if(cur < m and cnt < c[cur].fi){
			if(inc == 1){
				cout<< "R";
				s++;
				cnt++;
			}
			else{
				cout<< "L";
				s--;
				cnt++;
			}
		}
		else{
			if(cur < m and ((c[cur].se.fi <= s and s <= c[cur].se.se) or (c[cur].se.fi <= s+inc and s+inc <= c[cur].se.se))) {
				cout<< "X";
				cnt++;
			}
			else{
				if(inc == 1){
					cout<< "R";
					s++;
					cnt++;
				}
				else{
					cout<< "L";
					s--;
					cnt++;
				}
			}
			cur++;
		}
	}
	
	return 0;
}
