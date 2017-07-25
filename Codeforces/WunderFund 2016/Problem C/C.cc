#include <bits/stdc++.h>

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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

int n;
vector<pair<pair<int,int>, int> > v;

int main(){
	sd(n);
	int x, y;
	for(int i = 0; i < n; i++){
		sd2(x,y);
		v.pb(mp(mp(x,y),i));
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 2; i < n; i++){
		int x1 = v[i-2].fi.fi, y1 = v[i-2].fi.se;
		int x2 = v[i-1].fi.fi, y2 = v[i-1].fi.se;
		int x3 = v[i].fi.fi, y3 = v[i].fi.se;
		
		if(x1 != x2 or x2 != x3 or x3 != x1){
			if((y2-y1)*(x3-x1) != (y3-y1)*(x2-x1)){
				printf("%d %d %d\n", v[i-2].se+1, v[i-1].se+1, v[i].se+1);
				return 0;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		swap(v[i].fi.fi, v[i].fi.se);
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 2; i < n; i++){
		int x1 = v[i-2].fi.fi, y1 = v[i-2].fi.se;
		int x2 = v[i-1].fi.fi, y2 = v[i-1].fi.se;
		int x3 = v[i].fi.fi, y3 = v[i].fi.se;
		
		if(x1 != x2 or x2 != x3 or x3 != x1){
			if((y2-y1)*(x3-x1) != (y3-y1)*(x2-x1)){
				printf("%d %d %d\n", v[i-2].se+1, v[i-1].se+1, v[i].se+1);
				return 0;
			}
		}
	}
	
	return 0;
}
