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

int n, m;
int cnt = 1, tot = 0;

int main(){
	sd(n);
	sd(m);
	int x;
	for(int i = 0; i < n; i++){
		sd(x);
		if(x <= m){
			tot++;
			continue;
		}
		else{
			if(cnt > 0){
				cnt--;
				tot++;
			}
			else{
				printf("%d\n", tot);
				return 0;
			}
		}
	}	

	printf("%d\n", tot);
	
	return 0;
}
