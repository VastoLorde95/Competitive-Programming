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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, x, y, a, b, cnt, dx, dy;

vector<pair<int, int> > p1, p2;
vector<pair<int, int> > pts[4];
vector<pair<int, int> > quad;

int get(pair<int, int> pt1, pair<int, int> pt2, pair<int, int> pt3){
	dx = pt1.fi - pt2.fi;
	dy = pt1.se - pt2.se;
	
	if(pt3.fi == pt1.fi and pt3.se == pt1.se)
		return 0;
	
//	if((dx > 0 and dy > 0) or (dx < 0 and dy < 0)){
		if(pt3.fi == pt2.fi-dy and pt3.se == pt2.se+dx)
			return 1;
		if(pt3.fi == pt2.fi-dx and pt3.se == pt2.se-dy)
			return 2;
		if(pt3.fi == pt2.fi+dy and pt3.se == pt2.se-dx)
			return 3;
//	}
//	else{
//		if(pt3.fi == pt2.fi+dx and pt3.se == pt2.se-dy)
//			return 1;
//		if(pt3.fi == pt2.fi-dx and pt3.se == pt2.se-dy)
//			return 2;
//		if(pt3.fi == pt2.fi+dx and pt3.se == pt2.se+dy)
//			return 3;
//	}	
}

int dist(pair<int, int> pt1, pair<int, int> pt2){
	return ((pt1.fi-pt2.fi)*(pt1.fi-pt2.fi) + (pt1.se-pt2.se)*(pt1.se-pt2.se));
}

bool is_square(vector<pair<int, int> > q){
	map<int, int> distances;	
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(j != i){
				distances[dist(q[i],q[j])]++;
			}
		}
	}
	
	
	//cout << "1" << endl;
	if(distances.size() != 2) return false;
	//cout << "2" << endl;
	
	int c[2], d[2], cur = 0;
	
	for(map<int, int>::iterator it = distances.begin(); it != distances.end(); it++){
		d[cur] = it->first; if(d[cur] == 0) return false;
		c[cur] = it->second;
		cur++;
	}
	
//	cout << c[0] << " " << d[0] << " " << c[1] << " " << d[1] << " " << endl;
	
	if(c[0] == 8 and c[1] == 4 and d[0]*2 == d[1]);
		return true;
		
	return false;
	
}

int main(){
	sd(n);
	for(int T = 0; T < n; T++){
		p1.clear(), p2.clear();
		for(int j = 0; j < 4; j++){
			sd2(x,y); sd2(a,b);
			p1.pb(mp(x,y));
			p2.pb(mp(a,b));
		}
		
		cnt = 100;
		
		for(int i = 0; i < 4; i++){
			dx = p1[i].fi - p2[i].fi;
			dy = p1[i].se - p2[i].se;
			
			a = p2[i].fi, b = p2[i].se;
			
			pts[i].clear();
			
			pts[i].pb(mp(a+dx, b+dy));
			pts[i].pb(mp(a+dy, b-dx));
			pts[i].pb(mp(a-dx, b-dy));
			pts[i].pb(mp(a-dy, b+dx));	
		}
		
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					for(int l = 0; l < 4; l++){
						quad.clear();
						quad.pb(pts[0][i]);
						quad.pb(pts[1][j]);
						quad.pb(pts[2][k]);
						quad.pb(pts[3][l]);
						
						if(is_square(quad)){
							int tmp = get(p1[0], p2[0], quad[0]); 
//							cout << tmp << "\n";
							tmp += get(p1[1], p2[1], quad[1]);
//							cout << tmp << "\n";
							tmp += get(p1[2], p2[2], quad[2]);
//							cout << tmp << endl;
							tmp += get(p1[3], p2[3], quad[3]);
//							cout << tmp << "\n";
							
//							cout << quad[0].fi << " " << quad[0].se << " " << quad[1].fi << " " << quad[1].se << " " << quad[2].fi << " " << quad[2].se << " " << quad[3].fi << " " << quad[3].se << " " << tmp << endl;
							
							cnt = min(cnt, tmp);
						}	
					}
				}
			}
		}
		if(cnt < 100) printf("%d\n", cnt); else printf("-1\n");
		
	}
	return 0;
}
