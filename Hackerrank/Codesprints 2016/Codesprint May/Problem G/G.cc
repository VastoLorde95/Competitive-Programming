#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;
int p[N], rnk[N];

set<int> s[N];
set<int> passive[N];
set<pii> active[N];
int mx[N];

int ptr1[N], ptr2[N], ptr3[N];

int n, m, q;
int t[N];

vector<pair<int, pii> > e;

int qr[N];

int ans[N];

void create(int x){
	p[x] = x;
	rnk[x] = 0;
	ptr1[x] = x;	// s
	ptr2[x] = x;	// passive
	ptr3[x] = x;	// active
	mx[x] = 0;
	s[x].insert(t[x]);
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y, int val){
	int px = find(x);
	int py = find(y);
	if(px == py) return;
	
	if(rnk[py] > rnk[px]) swap(px, py);
	if(rnk[py] == rnk[px]) rnk[px]++;
	
	mx[px] = max(mx[px], mx[py]);
	mx[px] = max(mx[px], val);
	
	int i, j;
	
	i = ptr1[px];
	j = ptr1[py];
	
	if(s[i].size() >= s[j].size()){
		foreach(it, s[j]) s[i].insert(*it);
		s[j].clear();
	}
	else{
		foreach(it, s[i]) s[j].insert(*it);
		ptr1[px] = j;
		s[i].clear();
	}
	
	i = ptr2[px];
	j = ptr2[py];
	
	if(passive[i].size() >= passive[j].size()){
		vector<int> er;
		foreach(it, passive[j]){
			if(passive[i].count(*it))
				er.pb(*it);
			else
				passive[i].insert(*it);
		}
		
		int k = ptr3[px];
		foreach(it, er){
			passive[i].erase(*it);
			active[k].insert(mp(qr[*it], *it));
		}
		
		passive[j].clear();
	}
	else{
		vector<int> er;
		foreach(it, passive[i]){
			if(passive[j].count(*it))
				er.pb(*it);
			else
				passive[j].insert(*it);
		}
		
		int k = ptr3[px];
		foreach(it, er){
			passive[j].erase(*it);
			active[k].insert(mp(qr[*it], *it));
		}
		
		ptr2[px] = j;
		passive[i].clear();
	}
	
	i = ptr3[px];
	j = ptr3[py];
	
	if(active[i].size() >= active[j].size()){
		foreach(it, active[j]) active[i].insert(*it);
		active[j].clear();
	}
	else{
		foreach(it, active[i]) active[j].insert(*it);
		
		ptr3[px] = j;
		active[i].clear();
	}
	
	int k = s[ptr1[px]].size();
	
	vector<pii> er;
	
	foreach(it, active[ptr3[px]]){
		if(it->fi > k) break;
		ans[it->se] = min(ans[it->se], val);
		er.pb(*it);
	}
	
	foreach(it, er) active[ptr3[px]].erase(*it);
	
	p[py] = px;
	
	return;
}

int main(){
	sd3(n,m,q);
	
	for(int i = 1; i <= n; i++){
		sd(t[i]);
		create(i);
	}
	
	for(int i = 0; i < m; i++){
		int x, y, u;
		sd3(x,y,u);
		e.pb(mp(u, mp(x,y)));
	}
	
	sort(e.begin(), e.end());
	
	int inf = 1e9;

	for(int i = 1; i <= q; i++){
		int x, y, k;
		sd3(x,y,k);
		
		ans[i] = inf;
		
		qr[i] = k;		
		if(x == y){
			if(k <= 1)
				ans[i] = 0;
			else
				active[x].insert(mp(k,i));
		}
		else{		
			passive[x].insert(i);
			passive[y].insert(i);
		}
	}
	
	for(int i = 0; i < m; i++){
		int curw = e[i].fi;
		while(i < m and e[i].fi == curw){
			merge(e[i].se.fi, e[i].se.se, curw);
			i++;
		}
		i--;
	}
	
	for(int i = 1; i <= n; i++){
		foreach(it, active[ptr3[i]]){
			assert(it->fi > s[ptr1[i]].size());
			ans[it->se] = -1;
		}
	}
	
	for(int i = 1; i <= q; i++){
//		assert(ans[i] != inf);
		if(ans[i] == inf) ans[i] = -1;
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
