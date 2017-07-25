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

const int N = 100100;

struct node{
	int c, s, id;
};

int n, m;
node shoes[N];
int f[N], s[N], v[N];
int fid[N], sid[N];
int used[N];

vector<int> g[N];

bool comp1(const node &a, const node &b){
	return a.s < b.s;
}

//bool comp2(const int &x, const int &y){
//	if(f[x] == f[y])
//		return s[x] < s[y];
//	return f[x] < f[y];
//}

bool comp3(const node &a, const node &b){
	return a.c > b.c;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd2(shoes[i].c, shoes[i].s);
		shoes[i].id = i;
	}
	
	sort(shoes+1, shoes+n+1, comp1);
	
	sd(m);
	for(int i = 1; i <= m; i++){
		node person; sd2(person.c, person.s);
		
		int j = lower_bound(shoes+1, shoes+1+n, person, comp1) - (shoes+1);
		j++;
		
		while(j <= n and (shoes[j].s == person.s or shoes[j].s == person.s+1)){
			if(person.c >= shoes[j].c){
				g[shoes[j].id].pb(i);
				if(f[i] == 0) f[i] = shoes[j].c, fid[i] = shoes[j].id;
				else s[i] = shoes[j].c, sid[i] = shoes[j].id;
			}
			j++;
		}
		
		if(f[i] < s[i]) swap(f[i], s[i]), swap(fid[i], sid[i]);
		
	}
		
//	for(int i = 1; i <= n; i++){
//		sort(g[i].begin(), g[i].end(), comp2);
//	}
	
	sort(shoes+1, shoes+n+1, comp3);
	
	long long ans = 0;
	int total = 0;
	for(int i = 1; i <= n; i++){
		bool ok = false;
		
		foreach(it, g[shoes[i].id]){
			if(!v[*it]){
				if(f[*it] > shoes[i].c){
					v[*it] = shoes[i].id;
					total++;
					ans += shoes[i].c;
					ok = true;
					used[shoes[i].id] = 1;
					break;
				}
				else if(f[*it] == s[*it] and (used[fid[*it]] or used[sid[*it]])){
					v[*it] = shoes[i].id;
					total++;
					ans += shoes[i].c;
					ok = true;
					used[shoes[i].id] = 1;
					break;
				}
			}
		}
		
		if(!ok){
			int mn = 2e9, id = -1;
			foreach(it, g[shoes[i].id]){
				if(!v[*it]){
					if(s[*it] < mn){
						mn = s[*it];
						id = *it;
					}
				}
			}
			if(id != -1){
				v[id] = shoes[i].id;
				total++;
				ans += shoes[i].c;
				used[shoes[i].id] = 1;
			}
		}
	}
	
	cout << ans << endl << total << endl;
	for(int i = 1; i <= m; i++){
		if(v[i]) printf("%d %d\n", i, v[i]);
	}
	
	return 0;
}
