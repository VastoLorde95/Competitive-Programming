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

set<pii> s;
int l[N];
int r[N];
int n;

int a[N];
int p[N];

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	s.insert(mp(a[1], 1));
	
	set<pii>::iterator i1, i2;
	
	for(int i = 2; i <= n; i++){
		i1 = s.upper_bound(mp(a[i], 0));
		if(i1 == s.begin()){
			// bigger
			l[i1->se] = i;
			p[i] = i1->se;
		}
		else{
			i2 = i1;
			i2--;
			// i1 is just bigger
			// i2 is just smaller
			
			int x = -1, y = -1;
			
			if(i1 != s.end()){
				x = i1->se;
			}
			y = i2->se;
			
			if(x == -1){
				r[y] = i;
				p[i] = y;
			}
			else{
				if(l[x] > 0){
					r[y] = i;
					p[i] = y;
				}
				else{
					l[x] = i;
					p[i] = x;
				}
			}
		}
		
		s.insert(mp(a[i], i));
		
	}
	
	for(int i = 2; i <= n; i++){
		printf("%d ", a[p[i]]);
	}
	puts("");
	return 0;
}
