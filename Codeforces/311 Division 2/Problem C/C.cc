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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, cost, d[100100], prev;
pair<int, int> l[100100];
map<int, int> t, tot;
int mn = 1e9;


vector<int> pos[100100];

int main(){	
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(l[i].se);
		t[l[i].se]++;
	}
	for(int i = 0; i < n; i++){
		sd(l[i].fi); cost += l[i].fi;
		tot[l[i].se] += l[i].fi;
	}
	
	priority_queue<pair<int, int> > q;
		
	for(int i = 0; i < n; i++){
		q.push(l[i]);
	}
	
	for(map<int, int>::reverse_iterator it = t.rbegin(); it != t.rend(); it++){
		int need = it->se-1, cnt = 0, prev = cost - tot[it->fi];
		vector<pair<int, int> > tmp;
		
		while(!q.empty() and cnt < need){
			pair<int, int> p = q.top(); q.pop();
			if(p.se != it->fi and p.se < it->fi){
				prev -= p.fi;
				tmp.pb(p);
				cnt++;
			}
		}
		
		mn = min(mn, prev);
		
		foreach(it, tmp){
			q.push(*it);
		}
	}
	
	tr(mn);
	
	return 0;
}
