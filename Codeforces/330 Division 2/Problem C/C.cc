#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

const int N = 200100;

int n;
int x[N];

int f[N], p[N], v[N];

set<pair<int,int> > s;
set<pair<int,int> >::iterator it;

int start = 0, end = n-1;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(x[i]);
	}
	
	sort(x, x+n);
	
	p[0] = -1;
	for(int i = 1; i < n; i++){
		p[i] = i-1;
	}
	
	for(int i = 0; i < n-1; i++){
		f[i] = i+1;
	}
	f[n-1] = -1;
	
	for(int i = 1; i < n; i++){
		s.insert(mp(x[i]-x[i-1], i));
	}
	
	start = 0, end = n-1;
	
	for(int i = 0; i < n-2; i++){
		if(i%2 == 0){
			int p1 = f[start];
			int p2 = p[end];
			int d1 = x[p2] - x[start];
			int d2 = x[end] - x[p1];
			
			tr5(i,p1,p2,d1,d2);
			
			if(d1 < d2){
				v[start] = 1;
				start = p1;
				p[start] = -1;	
			}
			else if(d1 > d2){
				v[end] = 1;
				end = p2;
				f[p2] = -1;
			}
			else{
				if(i <= n-3){
					d1 = x[p1]-x[start];
					d2 = x[end]-x[p2];
					if(d1 < d2){
						v[end] = 1;
						end = p2;
						f[p2] = -1;
					}
					else{
						v[start] = 1;
						start = p1;
						p[start] = -1;
					}
				}
				else{
					v[end] = 1;
					end = p2;
					f[p2] = -1;		
				}
			}
		}
		else{
			it = s.begin();
			while(!s.empty() and (v[it->se] == 1) or (it->se >= 1 and v[it->se-1] == 1)){
				s.erase(it);
				it = s.begin();
			}	
			
			if(s.empty()) break;
			
			
			int id = it->se;
			s.erase(it);
			
			if(id == start){
				start = f[id];
			}
			
			if(id == end){
				end = p[id];
			}
			
			v[id] = 1;
			if(p[id] != -1){
				f[p[id]] = f[id];
			}
			if(f[id] != -1){
				p[f[id]] = -1;
			}
			
			if(p[id] != -1 and f[id] != -1){
				s.insert(mp(x[f[id]]-x[p[id]], f[id]));
			}
		}
	}

	cout << x[end] - x[start] << endl;	
		
	return 0;
}
