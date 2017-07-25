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
#include <iomanip>
#include <stack>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int MAXN = 100001;
int tree[MAXN]; // Careful, indexing begins from 1.

int query(int idx){
    int sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int n, cur;
set<long long> comp;
map<long long, int> f;
map<int, long long> finv;
multiset<long long> cnt;
multiset<long long>::iterator itt;
vector<pair<char,long long> > q;
char c;
long long x;
int ncnt = 1;

void median(){
	if(cur%2){
		int lo = 1, hi = ncnt, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			if(query(mid) >= (cur/2)+1) hi = mid;
			else lo = mid+1;
		}
		
		printf("%lld\n",finv[hi]);
	}
	else{
		int lo = 1, hi = ncnt, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			if(query(mid) >= ((cur/2)+1)) hi = mid;
			else lo = mid+1;
		}	

		itt = cnt.lower_bound(hi);
		itt--;
		int other;
		if(query(*itt) == (cur/2)) other = *itt;
		else other = hi;
//		tr3(finv[*itt], finv[hi],hi);
		double res = ((double)finv[other]/2.0f + (double)finv[hi]/2.0f);
		if(res - floor(res) == 0){
			printf("%lld\n", (long long) res);
		}
		else{
			printf("%.1lf\n", res);
		}
	}
	return;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		scanf(" %c %lld", &c, &x);
		q.pb(mp(c,x));
		comp.insert(x);
	}

	foreach(it, comp){
		finv[ncnt] = *it;
		f[*it] = ncnt++;
	}
	
	for(int i = 0; i < n; i++){
		c = q[i].fi, x = f[q[i].se];
		if(c == 'r'){
			if(!cnt.count(x)){
				puts("Wrong!");
				continue;
			}
			else{
				cnt.erase(cnt.find(x));
				update(x, -1);
				cur--;
			}
		}
		else{
			cnt.insert(x);
			update(x, 1);
			cur++;
		}
		
		if(cur == 0){
			puts("Wrong!");
			continue;
		}
		median();
	}
	
	return 0;
}
